#include "companypage.h"
#include "ui_companypage.h"
#include "transport.h"
#include "bus.h"
#include "train.h"
#include "airplane.h"

#include <QDebug>
#include <QInputDialog>
#include <QLineEdit>
#include <QDateEdit>
#include <QInputDialog>
#include <QMessageBox>

CompanyPage::CompanyPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CompanyPage)
{
    ui->setupUi(this);
}

CompanyPage::~CompanyPage()
{
    delete ui;
}

void CompanyPage::resetListView() {
    resetVehicleListView();
    resetTripListView();
}

void CompanyPage::resetVehicleListView() {
    ui->listWidget->clear();
    auto vehicles = Transport::getInstance().getVehicles();
    for (Vehicle* vehicle : vehicles) {
        if (vehicle->getCompany()->getCompanyName() == this->getCompanyName()) {
            QListWidgetItem* item = new QListWidgetItem(vehicle->getName());
            ui->listWidget->addItem(item);
        }
    }
}

void CompanyPage::resetTripListView() {
    ui->listWidget_2->clear();
    auto trips = Transport::getInstance().getTrips();
    for (Trip* trip : trips) {
        if (trip->getVehicle()->getCompany()->getCompanyName() == this->getCompanyName()) {
            QListWidgetItem* item = new QListWidgetItem(QString(trip->getVehicle()->getName() + ", " + trip->getRoute()->getName()));
            ui->listWidget_2->addItem(item);
        }
    }
}

void CompanyPage::on_pushButton_2_clicked()
{
    auto currentItemText = ui->listWidget->currentItem()->text();
    ui->listWidget->removeItemWidget(ui->listWidget->currentItem());
    Transport::getInstance().getVehicles().erase(
        std::remove_if(
            Transport::getInstance().getVehicles().begin(),
            Transport::getInstance().getVehicles().end(),
            [currentItemText](Vehicle* vehicle) {
                return vehicle->name == currentItemText;
            }
            ),
        Transport::getInstance().getVehicles().end()
        );

    resetListView();
}


void CompanyPage::on_pushButton_clicked()
{
    bool ok;
    QStringList items;
    items << "Otobus" << "Tren" << "Ucak";
    QString type = QInputDialog::getItem(this, "Input Dialog", "Arac turu:", items, 0, false, &ok);
    QString name = QInputDialog::getText(this, "Input Dialog", "Arac adi:", QLineEdit::Normal, "", &ok);
    QString company_name = QInputDialog::getText(this, "Input Dialog", "Sirket adi:", QLineEdit::Normal, "", &ok);
    int seatCount = QInputDialog::getInt(this, "Input Dialog", "Koltuk sayisi giriniz:", 0, 0, 100, 1, &ok);
    if (ok && !type.isEmpty() && !name.isEmpty() && !company_name.isEmpty()) {
        Vehicle* newVehicle = nullptr;

        Company* company_ = nullptr;
        const std::vector<Company*>& companies = Transport::getInstance().getCompanies();
        for (Company* company : companies) {
            if (company->getCompanyName() == company_name) {
                company_ = company;
                break;
            }
        }

        if (type == "Otobus") { newVehicle = new Bus(name, company_, seatCount); }
        else if (type == "Tren") { newVehicle = new Train(name, company_, seatCount); }
        else if (type == "Ucak") { newVehicle = new Airplane(name, company_, seatCount); }

        Transport::getInstance().getVehicles().push_back(newVehicle);

        ui->listWidget->addItem(new QListWidgetItem(name));
    } else {
        QMessageBox::critical(this, "Error", "Bir ad girilmedi.", QMessageBox::Ok);
    }
}


void CompanyPage::on_pushButton_4_clicked()
{
    bool ok;
    QString vehicle_name = QInputDialog::getText(this, "Input Dialog", "Arac ismi:", QLineEdit::Normal, "", &ok);
    QString route_name = QInputDialog::getText(this, "Input Dialog", "Sefer ismi:", QLineEdit::Normal, "", &ok);
    QDialog* dialog = new QDialog();
    QHBoxLayout* layout = new QHBoxLayout();
    QDateEdit* dateEdit = new QDateEdit(QDate::currentDate(), this);
    QPushButton* button = new QPushButton("Ok");
    QObject::connect(button, &QPushButton::clicked, dialog, &QDialog::close);
    layout->addWidget(dateEdit);
    layout->addWidget(button);
    dialog->setLayout(layout);
    dialog->exec();
    int price = QInputDialog::getInt(this, "Input Dialog", "Enter an integer value:", 0, 0, 2000, 1, &ok);

    if (ok && !vehicle_name.isEmpty() && !route_name.isEmpty()) {
        Vehicle* vehicle_ = nullptr;
        const std::vector<Vehicle*>& vehicles = Transport::getInstance().getVehicles();
        for (Vehicle* vehicle : vehicles) {
            if (vehicle->name == vehicle_name) {
                vehicle_ = vehicle;
                break;
            }
        }

        Route* route_ = nullptr;
        const std::vector<Route*>& routes = Transport::getInstance().getRoutes();
        for (Route* route : routes) {
            if (route->getName() == route_name) {
                route_ = route;
                break;
            }
        }

        if (vehicle_ == nullptr || route_ == nullptr) {
            QMessageBox::critical(nullptr, "Error", "Girilen degerlerde veriler yok.", QMessageBox::Ok);
            return;
        }

        Trip* newTrip = new Trip(vehicle_, route_, dateEdit->date(), price, {});

        Transport::getInstance().getTrips().push_back(newTrip);

        ui->listWidget_2->addItem(new QListWidgetItem(QString(newTrip->getVehicle()->getName() + ", " + newTrip->getRoute()->getName())));
    } else {
        QMessageBox::critical(this, "Hata", "Bilgilerin girilmesi zorunludur!");
        return;
    }
}

QString CompanyPage::getCompanyName() const
{
    return companyName;
}

void CompanyPage::setCompanyName(const QString &newCompanyName)
{
    companyName = newCompanyName;
}


void CompanyPage::on_pushButton_3_clicked()
{
    auto currentItemText = ui->listWidget_2->currentItem()->text();

    ui->listWidget_2->removeItemWidget(ui->listWidget->currentItem());
    Transport::getInstance().getTrips().erase(
        std::remove_if(
            Transport::getInstance().getTrips().begin(),
            Transport::getInstance().getTrips().end(),
            [currentItemText](Trip* trip) {
                return QString(trip->getVehicle()->getName() + ", " + trip->getRoute()->getName()) == currentItemText;
            }
            ),
        Transport::getInstance().getTrips().end()
        );

    resetListView();
}

