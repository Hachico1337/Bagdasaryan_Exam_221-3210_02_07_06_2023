
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windows.h"
#include "singletonclient.h"

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


void MainWindow::on_pushButton_clicked()
{

    auto req = "sort&" + ui->textEdit_2->toPlainText() + "&" + ui->textEdit->toPlainText();

    SingletonClient::getInstance()->send_msg_to_server(req);
    SingletonClient::getInstance()->slotServerRead();
    auto result = ResultMessage;
    ui->textEdit_3->setText(result);
    qDebug() << result;
}





