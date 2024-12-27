#include "odemeekrani.h"
#include "ui_odemeekrani.h"
#include "transport.h"
#include <QMessageBox>

OdemeEkrani::OdemeEkrani(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OdemeEkrani)
{
    ui->setupUi(this);
}

OdemeEkrani::~OdemeEkrani()
{
    delete ui;
}

int OdemeEkrani::getPrice() const
{
    return price;
}

void OdemeEkrani::setPrice(int newPrice)
{
    price = newPrice;
}

std::vector<int>& OdemeEkrani::getSeats()
{
    return seats;
}

void OdemeEkrani::setSeats(const std::vector<int> &newSeats)
{
    seats = newSeats;
}

Trip *OdemeEkrani::getTrip() const
{
    return trip;
}

void OdemeEkrani::setTrip(Trip *newTrip)
{
    trip = newTrip;
}

void OdemeEkrani::on_buttonBox_accepted()
{
    QString ad = ui->ad_linedit->text();
    QString soyad = ui->soyad_lineedit->text();
    QString Tc = ui->tc_lineedit->text();
    QDate bdate = ui->dateEdit->date();
    if (!ad.isEmpty() && !soyad.isEmpty() && !Tc.isEmpty()) {
        Passenger* passenger = new Passenger(ad, soyad, Tc, bdate);
        Reservation* reservation = new Reservation(passenger, this->getTrip(), this->getSeat(), this->getPrice());
        Transport::getInstance().getReservations().push_back(reservation);
        auto seatsOccupied = this->getTrip()->getSeatOccupied();
        for (int i : this->getSeats()) {
            seatsOccupied[i-1] = 1;
        }
        this->getTrip()->setSeatOccupied(seatsOccupied);
        QMessageBox::information(this,
                                 "Rezervasyon yapildi!",
                                 "Rezervasyon tarihi: " + trip->getDate().toString() +
                                 "\nReserve trip route: " + trip->getRoute()->getName() +
                                 "\nArac ismi:" + trip->getVehicle()->getName() +
                                 "\nSirket adi: " + trip->getVehicle()->getCompany()->getCompanyName() +
                                     "\nRezerve Koltuklar: " + QString::number(this->getSeat()));

    } else {
        QMessageBox::critical(this, "Hata", "Bilgilerin girilmesi zorunludur!");
    }
}

int OdemeEkrani::getSeat() const
{
    return seat;
}

void OdemeEkrani::setSeat(int newSeat)
{
    seat = newSeat;
}

void OdemeEkrani::getValues(Trip* trip, int seat, int price) {
    this->setTrip(trip);
    this->setSeat(seat);
    this->getSeats().push_back(seat);
    this->setPrice(price);
}
