#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include "cactoitem.h"
#include "dinoitem.h"
#include "connectarduino.h"


class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

    void addDino();

    void startGame();

    bool getGameOn() const;
    void setGameOn(bool value);

    void jumpWithArduino();

signals:

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;


private:
    void cleanCactos();
    void setUpCactoTimer();
    void freezeDinoAndCactosInPlace();

    QTimer * cactoTimer;
    DinoItem * dino;
    bool gameOn;


};

#endif // SCENE_H
