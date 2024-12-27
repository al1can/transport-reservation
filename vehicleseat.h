#ifndef VEHICLESEAT_H
#define VEHICLESEAT_H

#include <QDialog>
#include "trip.h"
#include "odemeekrani.h"

namespace Ui {
class VehicleSeat;
}

class VehicleSeat : public QDialog
{
    Q_OBJECT

public:
    explicit VehicleSeat(QWidget *parent = nullptr);
    ~VehicleSeat();
    OdemeEkrani* odemeEkrani = new OdemeEkrani();
    Trip* trip;

    Trip *getTrip() const;
    void setTrip(Trip *newTrip);

public slots:
    void updateListView(Trip* trip);

private slots:
    void on_buttonBox_accepted();

signals:
    void sendToOdemeEkrani(Trip* trip, int seat, int price);

private:
    Ui::VehicleSeat *ui;
};

#endif // VEHICLESEAT_H
