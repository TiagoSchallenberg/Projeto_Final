#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

Scene::Scene(QObject *parent) : QGraphicsScene(parent),
    gameOn(false)
{
    setUpCactoTimer();    
}

void Scene::addDino()
{
    dino = new DinoItem(QPixmap(":/images/dino_up.png"));
    dino->setPos(QPointF(-300,-70)); // Local do Dino
    addItem(dino);
}

void Scene::startGame()
{
    // Dino
    dino->startRun();
    //Cactos
    if(!cactoTimer->isActive()){
        cleanCactos();
        setGameOn(true);
        cactoTimer->start(1000); // Tempo de criação do cacto
    }
}

void Scene::setUpCactoTimer()
{
    cactoTimer = new QTimer(this);
    connect(cactoTimer,&QTimer::timeout,[=](){

        CactoItem * cactoItem = new CactoItem();
        connect(cactoItem,&CactoItem::collideFail,[=](){
            cactoTimer->stop();
            freezeDinoAndCactosInPlace();
            setGameOn(false);
        });
        addItem(cactoItem);
    });

    cactoTimer->start(1000);


}

void Scene::freezeDinoAndCactosInPlace()
{
    // Para o Dino
    dino->freezeInPlace();

    // Para os cactos
    QList<QGraphicsItem *> sceneItems = items();
    foreach(QGraphicsItem * item, sceneItems){
        CactoItem * cacto = dynamic_cast<CactoItem *>(item);
        if(cacto){
            cacto->freezeInPlace();
        }
    }
}

bool Scene::getGameOn() const
{
    return gameOn;
}

void Scene::setGameOn(bool value)
{
    gameOn = value;
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space){
        if(gameOn)
            dino->shootUp();
    }
    QGraphicsScene::keyPressEvent(event);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        if(gameOn)
            dino->shootUp();
    }
    QGraphicsScene::mousePressEvent(event);
}

void Scene::cleanCactos()
{
    QList<QGraphicsItem *> sceneItems = items();
    foreach(QGraphicsItem * item, sceneItems){
        CactoItem * cacto = dynamic_cast<CactoItem *>(item);
        if(cacto){
            removeItem(cacto);
            delete cacto;
        }
    }
}
