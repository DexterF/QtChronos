#include "headers/communication.h"
#include <QtSerialPort/QtSerialPort>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

Communication::Communication()
{
    this->isappresent = false;
    portlist tmp;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        tmp.name = info.portName();
        tmp.description = info.manufacturer() + " " + info.description();
        if(info.hasProductIdentifier() && info.hasVendorIdentifier()){
            if(info.productIdentifier()==832 && info.vendorIdentifier()==8263){
                this->isappresent = true;
                this->apports.push_back(tmp);
            }
        }
        this->ports.push_back(tmp);
    }
}

bool Communication::apAvail(){
    bool avail = false;
    if (isappresent == true){
        foreach (portlist ap, apports) {
            if(!(QSerialPortInfo(ap.name).isBusy())){
                avail = true;
            }
        }
    }
    return avail;
}

bool Communication::openPort(){
    if(this->apAvail()){
        portlist tmp = apports.front();
        serial = new QSerialPort();
        serial->setPortName(tmp.name);
        if(serial->open(QIODevice::ReadWrite)){
            serial->setBaudRate(QSerialPort::Baud115200);
            return true;
        }
        else
            qDebug() << "Serial open failed with error: " << serial->errorString();
    }
    return false;
}

void Communication::closePort(){
    serial->close();
}

Communication::~Communication(){
    this->closePort();
}
