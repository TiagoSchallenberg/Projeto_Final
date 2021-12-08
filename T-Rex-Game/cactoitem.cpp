#include "cactoitem.h"
#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QDebug>
#include <dinoitem.h>

CactoItem::CactoItem() :
    cacto_small(new QGraphicsPixmapItem(QPixmap(":/images/cacti_small_1.png")))
{

    cacto_small->setPos(QPointF(0,-48)); // Local do cacto

    addToGroup(cacto_small); // Add ao Widget.ui

    xPos = QRandomGenerator::global()->bounded(150);


    setPos(QPoint(0,0) + QPoint(xPos,0)); // Ajustar


    xAnimation = new QPropertyAnimation(this,"x",this);
    xAnimation->setStartValue(300 + xPos);
    xAnimation->setEndValue(-500);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(2000); // Duração da animção

    connect(xAnimation,&QPropertyAnimation::finished,[=](){
       qDebug() << "Animation finished";
        scene()->removeItem(this);
        delete this;
    });

    xAnimation->start();


}

CactoItem::~CactoItem()
{
    qDebug() << "Deleting Cacto!";
    delete cacto_small;
}

qreal CactoItem::x() const
{
    return m_x;
}

void CactoItem::freezeInPlace()
{
    xAnimation->stop();
}

void CactoItem::setX(qreal x)
{
    // qDebug() << "Cacto position : " << x;
    m_x = x;
    if(collidesWithDino()){
        emit collideFail();
    }
    setPos(QPointF(0,0) + QPointF(x + xPos,0));
}

bool CactoItem::collidesWithDino()
{
    QList<QGraphicsItem*> collidingItems = cacto_small->collidingItems();
    collidingItems.append(cacto_small->collidingItems());

    foreach (QGraphicsItem * item, collidingItems) {
        DinoItem * dinoItem = dynamic_cast<DinoItem*>(item);
        if(dinoItem){
            return true;
        }
    }
    return false;
}
