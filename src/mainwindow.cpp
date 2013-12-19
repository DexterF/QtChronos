#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create and set the options button on the top left of the tabs
    QPushButton* buttonOptions = new QPushButton();
    ui->tabWidget->setCornerWidget(buttonOptions, Qt::TopLeftCorner);

    connect(buttonOptions, SIGNAL(clicked()),
            this, SLOT(OpenSettings()));

    /***************************************************************************
     * Shortcuts
     **************************************************************************/
    // Quit
    QShortcut* shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q),
                                        this);
    shortcut->setContext(Qt::ApplicationShortcut);
    connect(shortcut, SIGNAL(activated()),
            this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenSettings(){
    OptionsWindow* settings =  new OptionsWindow(this);
    settings->show();
}
