#ifndef CONNECTARDUINO_H
#define CONNECTARDUINO_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include "dinoitem.h"

namespace Ui {
class ConnectArduino;
}

class ConnectArduino : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConnectArduino(QWidget *parent = nullptr);
    ~ConnectArduino();

    QSerialPort *serialPort;

    void jumpWithArduino();

public slots:
    void connctToSerial();
    void Reading();



signals:
    void startReading(bool ok);


private:
    Ui::ConnectArduino *ui;
};

#endif // CONNECTARDUINO_H
