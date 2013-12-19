#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "optionswindow.h"

#include <QMainWindow>
#include <QPushButton>
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void OpenSettings();
};

#endif // MAINWINDOW_H
