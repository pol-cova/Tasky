#include "credits.h"
#include "ui_credits.h"

#include <QDesktopServices>
#include <QUrl>

credits::credits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::credits)
{
    ui->setupUi(this);
    ui->header->setStyleSheet("color: #1a1b25");
    ui->dev->setStyleSheet("color: #1a1b25");
    ui->soporte->setStyleSheet("color: #1a1b25");
    ui->date->setStyleSheet("color: #1a1b25");

}

credits::~credits()
{
    delete ui;
}

void credits::on_pushButton_clicked()
{
    QUrl url("https://github.com/pol-cova/Tasky");
    QDesktopServices::openUrl(url);
}

