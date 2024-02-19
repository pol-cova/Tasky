#include "mainwindow.h"
#include "ui_mainwindow.h"
// Include agenda
#include "agenda.h"
// Include credits
#include "credits.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_enterBTN_clicked()
{
    Agenda* myAgenda = new Agenda(this);
    this->hide();
    myAgenda->show();

}


void MainWindow::on_infoBTN_clicked()
{
    credits* myCredits = new credits(this);
    myCredits->show();
}




void MainWindow::on_settingsBTN_clicked()
{

}


void MainWindow::on_exitBTN_clicked()
{
    QCoreApplication::quit();
}

