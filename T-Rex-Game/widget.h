#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "scene.h"
#include "connectarduino.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_Connect_toolButton_clicked();

    void on_Start_toolButton_clicked();

private:
    Ui::Widget *ui;

    ConnectArduino *formAdd;
    Scene * scene;
};
#endif // WIDGET_H
