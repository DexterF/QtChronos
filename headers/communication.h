#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <vector>
#include <QtSerialPort/QtSerialPort>

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

typedef struct _portlist{
    QString name;
    QString description;
} portlist;


class Communication
{
private:
    bool isappresent;
    std::vector<portlist> ports;
    std::vector<portlist> apports;
    QSerialPort *serial;
public:
    Communication();
    bool apAvail();
    bool openPort();
};

#endif // COMMUNICATION_H
