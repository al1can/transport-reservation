#include "userpage.h"
#include "ui_userpage.h"
#include "transport.h"
#include "trip.h"
#include "mywidget.h"
#include "vehicleseat.h"

#include <QString>
#include <QPointer>

UserPage::UserPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserPage)
{
    ui->setupUi(this);
    connect(ui->listWidget, &QListWidget::itemClicked, this, &UserPage::handleItemClicked);
    connect(this, &UserPage::updateVehicleSeat, vehicleSeat, &VehicleSeat::updateListView);
    connect(seferBul, &SeferBul::UserPageResetListView, this, &UserPage::updateListView);
    renderListView();
}

UserPage::~UserPage()
{
    delete ui;
}

void UserPage::on_pushButton_clicked()
{
    seferBul->exec();
}

void UserPage::renderListView() {

    if (!QMetaType::hasRegisteredConverterFunction<Trip*, QVariant>()) {
        qRegisterMetaType<Trip*>("Trip*");
    }

    ui->listWidget->clear();
    auto trips = Transport::getInstance().getTrips();
    for (Trip* trip : trips) {
        myWidget = new MyWidget(this);
        QString routeString;
        for(auto route : trip->getRoute()->getRoute()) {
            routeString.append(route + ", ");
        }
        myWidget->updateWidget(routeString,
                               QString::number(trip->getVehicle()->getSeatCount()),
                               trip->getVehicle()->getName(),
                               trip->getDate().toString("dd-MM-yyyy"),
                               trip->getVehicle()->getCompany()->getCompanyName());

        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        item->setSizeHint(myWidget->sizeHint());
        item->setData(Qt::UserRole, QVariant::fromValue(trip));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, myWidget);
    }

    ui->listWidget->update();
}

void UserPage::updateListView(QString startPos, QString destinationPos, QDate date) {
    ui->listWidget->clear();
    auto trips = Transport::getInstance().getTrips();
    bool startExists = false;
    bool destinationExists = false;
    for (Trip* trip : trips) {
        auto route = trip->getRoute()->getRoute();
        startExists = std::find(route.begin(), route.end(), startPos) != route.end();
        destinationExists = std::find(route.begin(), route.end(), destinationPos) != route.end();

        if (trip->getDate() == date &&
            (startPos.isEmpty() || startExists) &&
            (destinationPos.isEmpty() || destinationExists)) {
            myWidget = new MyWidget(this);
            QString routeString;
            for(auto route : trip->getRoute()->getRoute()) {
                routeString.append(route + ", ");
            }
            myWidget->updateWidget(routeString,
                                   QString::number(trip->getVehicle()->getSeatCount()),
                                   trip->getVehicle()->getName(),
                                   trip->getDate().toString("dd-MM-yyyy"),
                                   trip->getVehicle()->getCompany()->getCompanyName());

            QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
            item->setSizeHint(myWidget->sizeHint());
            item->setData(Qt::UserRole, QVariant::fromValue(trip));
            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item, myWidget);
        }
    }

    ui->listWidget->update();
}


void UserPage::handleItemClicked(QListWidgetItem *item) {
    Trip *trip = item->data(Qt::UserRole).value<Trip*>();
    emit updateVehicleSeat(trip);
    vehicleSeat->exec();
}
