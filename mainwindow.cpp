#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->panel = new Panel(this);
    this->alArea = new AlgorithmArea;

    this->panel->setAlArea(this->alArea);
    this->alArea->setWidget(this->panel);
}

MainWindow::~MainWindow()
{
    delete this->alArea;
    delete this->panel;
    delete this->ui;
}


//Events
void MainWindow::resizeEvent(QResizeEvent *event){
    Q_UNUSED(event);
    this->panel->updatePanel();
}
//End events
