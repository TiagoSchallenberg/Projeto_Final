#include "connectarduino.h"
#include "ui_connectarduino.h"

ConnectArduino::ConnectArduino(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConnectArduino)
{
    ui->setupUi(this);

    this->serialPort = new QSerialPort;

    QStringList ports;
    const auto serialPortsInfos = QSerialPortInfo::availablePorts();
    int i = 0;
    for (const QSerialPortInfo &serialPortInfo : serialPortsInfos){
        ports.insert(i,serialPortInfo.portName());
        i++;
    }
    ui->comboBox_port->insertItems(0,ports);

    QStringList bauds;
    bauds << "9600" << "19200";
    ui->comboBox_baud->insertItems(0,bauds);

    connect(ui->Button_connenct,SIGNAL(clicked(bool)),this,SLOT(connctToSerial()));
    //connect(this,SIGNAL(startReading(bool)),this,SLOT(Reading()));
    connect(this->serialPort,SIGNAL(readyRead()),this,SLOT(Reading()));

}

ConnectArduino::~ConnectArduino()
{
    delete ui;
}

void ConnectArduino::connctToSerial()
{
    if(this->serialPort->isOpen()){
        this->serialPort->close();
        ui->label_status->setText("Desconectado");
        ui->Button_connenct->setText("Conectar");
        return;
    }
    this->serialPort->setPortName(ui->comboBox_port->currentText());
    this->serialPort->setBaudRate(ui->comboBox_baud->currentText().toUInt());

    if(!this->serialPort->open(QIODevice::ReadOnly)){
        ui->label_status->setText("Falha ao tentar conectar");
        return;
    }
    ui->label_status->setText("Conectado");
    ui->Button_connenct->setText("Desconectar");

    emit startReading(true);

}

void ConnectArduino::Reading()
{
    QByteArray readData = this->serialPort->readLine();
    qDebug() << readData;




}

void ConnectArduino::jumpWithArduino()
{

}
