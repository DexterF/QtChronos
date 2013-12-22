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
    bool sendPayload(QByteArray &payload);
    QByteArray getPayload();
public:
    Communication();
    bool apAvail();
    bool openPort();
    void closePort();
    void resetHW();
    void getHWStatus();
    ~Communication();
};

#endif // COMMUNICATION_H
