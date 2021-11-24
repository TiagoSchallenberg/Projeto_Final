#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsPixmapItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new Scene(this);
    scene->setSceneRect(-350,-200,700,400);

    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/images/Dino_scene2.png"));
    scene->addItem(pixItem);
    pixItem->setPos(QPointF(0,0) - QPointF(pixItem->boundingRect().width()/2,
                                           pixItem->boundingRect().height()/2));
    scene->addLine(-400,20,400,20,QPen(Qt::blue));
    scene->addLine(20,-400,20,400,QPen(Qt::blue));

    ui->graphicsView->setScene(scene);
}

Widget::~Widget()
{
    delete ui;
}

