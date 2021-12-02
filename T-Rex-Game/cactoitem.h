#ifndef CACTOITEM_H
#define CACTOITEM_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class CactoItem :public QObject , public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)

public:
    explicit CactoItem();
    ~CactoItem();

    qreal x() const;

    void freezeInPlace();

public slots:
    void setX(qreal x);

signals:
    void collideFail();

private:

    bool collidesWithDino();


    QGraphicsPixmapItem * cacto_small;
    QPropertyAnimation * xAnimation;
    int xPos;

    qreal m_x;
};

#endif // CACTOITEM_H
