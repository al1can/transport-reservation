#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "adminlogin.h"
#include "companylogin.h"
#include "userpage.h"

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
    AdminLogin adminLogin;
    adminLogin.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    CompanyLogin companyLogin;
    companyLogin.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    UserPage userPage;
    userPage.exec();
}

