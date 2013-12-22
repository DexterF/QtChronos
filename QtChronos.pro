#-------------------------------------------------
#
# Project created by QtCreator 2013-12-19T01:10:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport

TARGET = QtChronos
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/communication.cpp

HEADERS  += headers/mainwindow.h \
    headers/communication.h

FORMS    += ui/mainwindow.ui
