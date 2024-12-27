#ifndef ODEMEEKRANI_H
#define ODEMEEKRANI_H

#include <QDialog>
#include "trip.h"

namespace Ui {
class OdemeEkrani;
}

class OdemeEkrani : public QDialog
{
    Q_OBJECT

public:
    explicit OdemeEkrani(QWidget *parent = nullptr);
    ~OdemeEkrani();

    Trip *getTrip() const;
    void setTrip(Trip *newTrip);

    std::vector<int>& getSeats();
    void setSeats(const std::vector<int> &newSeats);

    int getPrice() const;
    void setPrice(int newPrice);

    int getSeat() const;
    void setSeat(int newSeat);

public slots:
    void getValues(Trip* trip, int seat, int price);

private slots:
    void on_buttonBox_accepted();


private:
    Ui::OdemeEkrani *ui;
    Trip* trip;
    std::vector<int> seats;
    int seat;
    int price;
};

#endif // ODEMEEKRANI_H
