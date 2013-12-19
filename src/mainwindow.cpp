#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create and set the options button on the top left of the tabs
    QPushButton* buttonOptions = new QPushButton();
    ui->tabWidget->setCornerWidget(buttonOptions, Qt::TopLeftCorner);
}

MainWindow::~MainWindow()
{
    delete ui;
}
