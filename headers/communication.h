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
private:
    bool isappresent;
public:
    Communication();
    bool portAvail();
    std::vector<portlist> ports;
};



#endif // COMMUNICATION_H
