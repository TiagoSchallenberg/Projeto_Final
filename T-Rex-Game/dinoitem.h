#ifndef DINOITEM_H
#define DINOITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class DinoItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal y READ y WRITE setY)
public:
    explicit DinoItem(QPixmap pixmap);

    qreal y() const;


    void shootUp();

    // void startRun();

    void freezeInPlace();

public slots:
    void setY(qreal y);

    void fallToGroundIfNecessary();


signals:

private:
    enum LegsPosition{
        Up,
        Middle,
        Down
    };
    void updatePixmap();

    LegsPosition legsPosition;
    bool legsDirection; // 0:  down , 1: up
    qreal m_y;
    QPropertyAnimation * yAnimation;
    qreal groundPosition;

};

#endif // DINOITEM_H
