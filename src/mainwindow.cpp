#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    /***************************************************************************
     * Create and set the settings button on the top left of the tabs
     **************************************************************************/
    buttonSettings = new QPushButton();
    ui->tabWidget->setCornerWidget(buttonSettings, Qt::TopLeftCorner);
    setupMenu();
    connect(buttonSettings, SIGNAL(clicked()),
            this, SLOT(openMenu()));

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupMenu() {
    menuSettings = new QMenu(this);
    menuSettings->addAction("&File");
    menuSettings->addAction("&Help");

    QAction* aSettings = menuSettings->addAction("&Settings");
    connect(aSettings, SIGNAL(triggered()),
            this, SLOT(openSettings()));
    menuSettings->addSeparator();

    // Quit action
    QAction* aQuit = menuSettings->addAction("&Quit");
    this->addAction(aQuit);
    aQuit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
    connect(aQuit, SIGNAL(triggered()),
            this, SLOT(close()));
}

void MainWindow::openMenu() {
    menuSettings->exec(buttonSettings->mapToGlobal(QPoint(0, buttonSettings->height())));
}

void MainWindow::openSettings() {
    OptionsWindow* settings =  new OptionsWindow(this);
    settings->show();
}
