#include "adminlogin.h"
#include "ui_adminlogin.h"

#include <QMessageBox>
#include "adminpage.h"

AdminLogin::AdminLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminLogin)
{
    ui->setupUi(this);
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::on_buttonBox_accepted()
{
    if (ui->username_lineedit->text() == this->admin->getName() && ui->password_lineedit->text() == this->admin->getPassword()) {
        AdminPage adminPage;
        adminPage.exec();
    } else {
        QMessageBox::warning(nullptr, "Hata", "Kullanici adi veya sifre yanlis!");
    }

}

