#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    setUpCactoTimer();    
}

void Scene::addDino()
{
    dino = new DinoItem(QPixmap(":/images/dino_up.png"));
    dino->setPos(QPointF(-300,-70)); // Local do Dino
    addItem(dino);
}

void Scene::setUpCactoTimer()
{
    cactoTimer = new QTimer(this);
    connect(cactoTimer,&QTimer::timeout,[=](){

        CactoItem * cactoItem = new CactoItem(); // A cada 1s cria um novo cacto

        addItem(cactoItem);
    });

    cactoTimer->start(1000);


}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space){
        dino->shootUp();
    }
    QGraphicsScene::keyPressEvent(event);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        dino->shootUp();
    }
    QGraphicsScene::mousePressEvent(event);
}
