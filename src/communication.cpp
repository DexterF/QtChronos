#include "headers/communication.h"
//#include <QtSerialPort/QtSerialPort>
//#include <QApplication>
//#include <QWidget>
//#include <QVBoxLayout>
//#include <QLabel>

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

Communication::~Communication(){
    this->closePort();
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

bool Communication::sendPayload(QByteArray &payload){
    if(payload.isEmpty()){
        return false;
    }
    serial->write(payload);
    QThread::msleep(15);
    return true;
}

QByteArray Communication::getPayload(){
    QByteArray payload;
    payload = serial->read(10);
    return payload;
}

void Communication::resetHW(){
    QByteArray payload;
    payload.append("\xFF\x01\x03", 3);
    sendPayload(payload);
}

void Communication::getHWStatus(){
    QByteArray payloadsent, payloadrecv;
    payloadsent.append("\xFF\x00\x04\x00", 4);
    sendPayload(payloadsent);
    payloadrecv = getPayload();
    qDebug() << payloadrecv.toHex();

}
