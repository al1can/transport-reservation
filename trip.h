#ifndef TRIP_H
#define TRIP_H

#include <QDate>
#include "vehicle.h"
#include "route.h"
#include <QMetaType>

class Trip
{
public:
    Trip(Vehicle* vehicle, Route* route, QDate date, int price, std::vector<int>);
    Vehicle* vehicle;
    Route* route;
    QDate date;
    int price;
    std::vector<int> seatOccupied;

    Vehicle *getVehicle() const;
    void setVehicle(Vehicle *newVehicle);
    Route *getRoute() const;
    void setRoute(Route *newRoute);
    QDate getDate() const;
    void setDate(const QDate &newDate);
    int getPrice() const;
    void setPrice(int newPrice);
    std::vector<int> getSeatOccupied();
    void setSeatOccupied(std::vector<int> &newSeatOccupied);
};

Q_DECLARE_METATYPE(Trip*)

#endif // TRIP_H
