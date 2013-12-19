#-------------------------------------------------
#
# Project created by QtCreator 2013-12-19T01:10:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtChronos
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
        src/optionswindow.cpp

HEADERS  += headers/mainwindow.h \
            headers/optionswindow.h

FORMS    += ui/mainwindow.ui \
            ui/optionswindow.ui
