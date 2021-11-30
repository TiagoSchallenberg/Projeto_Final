#include "dinoitem.h"
#include <QTimer>
#include <QGraphicsScene>


DinoItem::DinoItem(QPixmap pixmap) :
    legsPosition(LegsPosition::Up),
    legsDirection(0)
{
    setPixmap(pixmap);

    QTimer * dinoLegsTimer = new QTimer(this);
    connect(dinoLegsTimer,&QTimer::timeout,[=](){
        updatePixmap();
    });

    dinoLegsTimer->start(80);

    groundPosition = scenePos().y() + 0; // Posição do Dino no chão

    yAnimation = new QPropertyAnimation(this, "y", this);
    yAnimation->setStartValue(scenePos().y());
    yAnimation->setEndValue(groundPosition);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(100);

    yAnimation->start();
}


qreal DinoItem::y() const
{
    return m_y;
}

void DinoItem::shootUp()
{
    yAnimation->stop();

    qreal cursPosY = y();

    yAnimation->setStartValue(cursPosY);
    yAnimation->setEndValue(cursPosY - scene()->sceneRect().height()/8);
    yAnimation->setEasingCurve(QEasingCurve::OutQuad);
    yAnimation->setDuration(285);

    connect(yAnimation, &QPropertyAnimation::finished,[=](){
        fallToGroundIfNecessary();
    });

    yAnimation->start();


}

void DinoItem::setY(qreal y)
{
    moveBy(0,y-m_y);
    m_y = y;
}

void DinoItem::fallToGroundIfNecessary()
{
    if( y() < groundPosition){
        //yAnimation->stop();

        yAnimation->setStartValue(y());
        yAnimation->setEasingCurve(QEasingCurve::InQuad);
        yAnimation->setEndValue(groundPosition);
        yAnimation->setDuration(1000);
        yAnimation->start();

    }
}

void DinoItem::updatePixmap()
{
    if(legsPosition == LegsPosition::Middle){
        if(legsDirection){
            //Up
            setPixmap(QPixmap(":/images/dino_up.png"));
            legsPosition = LegsPosition::Up;
            legsDirection = 0;
        }else{
            //Down
            //Up
            setPixmap(QPixmap(":/images/dino_down.png"));
            legsPosition = LegsPosition::Down;
            legsDirection = 1;
            }

    }else{
        setPixmap(QPixmap(":/images/dino_middle.png"));
        legsPosition = LegsPosition::Middle;
    }
}
