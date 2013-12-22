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
        tmp.path = info.systemLocation();
        tmp.description = info.manufacturer() + " " + info.description();
        if(info.hasProductIdentifier() && info.hasVendorIdentifier()){
            if(info.productIdentifier()==0340 && info.vendorIdentifier()==2047)
                this->isappresent == true;
        }

        ports.push_back(tmp);
    }
}

bool Communication::portAvail(){

}
