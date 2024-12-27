#include "adminpage.h"
#include "ui_adminpage.h"
#include "company.h"
#include "transport.h"
#include <qDebug>

AdminPage::AdminPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminPage)
{
    ui->setupUi(this);
    AdminPage::resetListView();
}

AdminPage::~AdminPage()
{
    delete ui;
}

void AdminPage::resetListView() {
    ui->listWidget->clear();
    for (Company* company : Transport::getInstance().getCompanies()) {
        QListWidgetItem* item = new QListWidgetItem(company->getCompanyName());
        ui->listWidget->addItem(item);
    }
}

int AdminPage::getHizmetbedeli() const
{
    return hizmetbedeli;
}

void AdminPage::setHizmetbedeli(int newHizmetbedeli)
{
    hizmetbedeli = newHizmetbedeli;
}

void AdminPage::on_pushButton_2_clicked()
{
    AdminPage::hizmetbedeli = ui->hizmetbedeli_lineedit->text().toInt();
}

void AdminPage::on_pushButton_clicked()
{
    Company* company_new = new Company(ui->firmaismi_lineedit->text(), ui->firmaismi_lineedit->text() + "sifre");
    Transport::getInstance().getCompanies().push_back(company_new);
    resetListView();
}

void AdminPage::on_pushButton_5_clicked()
{
    ui->listWidget->removeItemWidget(ui->listWidget->currentItem());
    Transport::getInstance().getCompanies().erase(
        std::remove_if(
            Transport::getInstance().getCompanies().begin(),
            Transport::getInstance().getCompanies().end(),
            [this](Company* company) {
                return company->getCompanyName() == ui->listWidget->currentItem()->text();
            }
            ),
        Transport::getInstance().getCompanies().end()
        );

    resetListView();
}

