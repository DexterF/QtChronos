#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QtSerialPort/QSerialPortInfo>
#include "headers/communication.h"

QT_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    w.setWindowTitle(QObject::tr("QtChronos Dummy App"));
    QVBoxLayout *layout = new QVBoxLayout;
    Communication *ser = new Communication();

    QLabel *label;
    if(ser->apAvail()){

        label = new QLabel(QString::fromStdString("Woot! Available!!"));
        ser->openPort();
        ser->resetHW();
        ser->getHWStatus();
    }
    else
        label = new QLabel(QString::fromStdString("=( No ap available"));

    layout->addWidget(label);

    w.setLayout(layout);
    w.show();

    return a.exec();
}
