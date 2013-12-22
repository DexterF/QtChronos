#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <vector>

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

typedef struct _portlist{
    QString name;
    QString path;
    QString description;
} portlist;


class Communication
{
public:
    Communication();
    QString listPorts();
    std::vector<portlist> ports;
};



#endif // COMMUNICATION_H
