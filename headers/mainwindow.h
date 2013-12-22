#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "optionswindow.h"

#include <QMainWindow>
#include <QPushButton>
#include <QMenu>

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
    QMenu* menuSettings;
    QPushButton* buttonSettings;

    void setupMenu();

private slots:
    void openMenu();
    void openSettings();
};

#endif // MAINWINDOW_H
