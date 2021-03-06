#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsPixmapItem>


Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new Scene(this);
    scene->setSceneRect(-350,-350,700,400); // Tamanho da cena.

    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/images/Dino_scene2.png"));
    scene->addItem(pixItem);
    pixItem->setPos(QPointF(0,0) - QPointF(pixItem->boundingRect().width()/2,
                                           pixItem->boundingRect().height()/2));
//    scene->addLine(-400,20,400,20,QPen(Qt::blue)); // Medidas do gráfico para as linhas X.
//    scene->addLine(20,-400,20,400,QPen(Qt::blue)); // Medidas do gráfico para as linhas Y.

    ui->graphicsView->setScene(scene);

    scene->addDino();


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Connect_toolButton_clicked()
{
    formAdd = new ConnectArduino(this);
    formAdd->show();
}

void Widget::on_Start_toolButton_clicked()
{
    scene->startGame();
}


