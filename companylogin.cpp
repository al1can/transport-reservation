#include "companylogin.h"
#include "ui_companylogin.h"
#include "companypage.h"

#include <QMessageBox>
#include <QDebug>

CompanyLogin::CompanyLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CompanyLogin)
{
    ui->setupUi(this);

    //CompanyCredentials["A"] = "asifre";
    //CompanyCredentials["B"] = "bsifre";
    //CompanyCredentials["C"] = "csifre";
    //CompanyCredentials["D"] = "dsifre";
    //CompanyCredentials["F"] = "fsifre";
}

CompanyLogin::~CompanyLogin()
{
    delete ui;
}

std::map<std::string, std::string> CompanyLogin::getCompanyCredentials() const
{
    return CompanyCredentials;
}

void CompanyLogin::setCompanyCredentials(const std::map<std::string, std::string> &newCompanyCredentials)
{
    CompanyCredentials = newCompanyCredentials;
}

void CompanyLogin::on_buttonBox_accepted()
{
    CompanyPage companyPage;
    companyPage.setCompanyName(ui->username_lineedit->text());
    auto companies = Transport::getInstance().getCompanies();
    int i = 0;
    for (const Company* company : companies) {
        QString username = company->getName();
        QString password = company->getPassword();

        if (ui->username_lineedit->text() == username &&
            ui->password_lineedit->text() == password) {

            companyPage.resetListView();
            companyPage.exec();
            i++;
        }
    }
    if (i == 0) {
        QMessageBox::warning(nullptr, "Warning", "Username or password is wrong!");

    }
}

