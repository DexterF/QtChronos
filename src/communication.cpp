#include "headers/communication.h"
#include <QtSerialPort/QtSerialPort>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>



Communication::Communication()
{
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
    if (this->isappresent == true){
        foreach (portlist ap, this->apports) {
            if(!(QSerialPortInfo(ap.name).isBusy())){
                avail = true;
            }
        }
    }
    return avail;
}
