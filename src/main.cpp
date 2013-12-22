/*#include "headers/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}*/


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
    w.setWindowTitle(QObject::tr("Info about all available serial ports."));
    QVBoxLayout *layout = new QVBoxLayout;
    Communication *ser = new Communication();

    foreach (portlist sport, ser->ports) {
        QLabel *label = new QLabel(sport.name + " - " + sport.description + " @ " + sport.path + "\n");
        layout->addWidget(label);
    }

    w.setLayout(layout);
    w.show();

    return a.exec();
}
