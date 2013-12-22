#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <vector>

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

typedef struct _portlist{
    QString name;
    QString description;
} portlist;


class Communication
{
private:
    bool isappresent = false;
    std::vector<portlist> ports;
    std::vector<portlist> apports;
public:
    Communication();
    bool apAvail();
};



#endif // COMMUNICATION_H
