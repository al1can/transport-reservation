#include "vehicleseat.h"
#include "ui_vehicleseat.h"
#include "QDebug"
#include <QMessageBox>

VehicleSeat::VehicleSeat(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VehicleSeat)
{
    ui->setupUi(this);
    connect(this, &VehicleSeat::sendToOdemeEkrani, odemeEkrani, &OdemeEkrani::getValues);
    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
}

VehicleSeat::~VehicleSeat()
{
    delete ui;
}

Trip *VehicleSeat::getTrip() const
{
    return trip;
}

void VehicleSeat::setTrip(Trip *newTrip)
{
    trip = newTrip;
}

void VehicleSeat::updateListView(Trip* trip)
{
    this->setTrip(trip);
    ui->listWidget->clear();
    for (int i = 0; i < trip->getSeatOccupied().size(); i++) {
        QListWidgetItem* item;
        if (trip->getSeatOccupied()[i]) {
            item = new QListWidgetItem("Koltuk " + QString::number(i + 1) + ")    Dolu");
        } else {
            item = new QListWidgetItem("Koltuk " + QString::number(i + 1) + ")    Bos");
        }
        item->setData(Qt::UserRole, i+1);
        ui->listWidget->addItem(item);
    }

}

void VehicleSeat::on_buttonBox_accepted()
{
    std::vector<int> seats;
    seats.clear();
    QList<QListWidgetItem*> selectedItems = ui->listWidget->selectedItems();
    for (auto item : selectedItems) {
        if (item->text().contains("Dolu")) {
            QMessageBox::critical(this, "Hatali Secim", "Yalnizca bos olan koltuklari secebilirsiniz!");
            return;
        }
        int data = item->data(Qt::UserRole).value<int>();
        seats.push_back(data);
        emit sendToOdemeEkrani(trip, data, 0);
        odemeEkrani->exec();
    }

}

