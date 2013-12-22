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

        ports.push_back(tmp);
    }
}

QString Communication::listPorts(){

}
