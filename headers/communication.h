#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <vector>
#include <QtSerialPort/QtSerialPort>

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
    void closePort();
    ~Communication();
};

#endif // COMMUNICATION_H
