#include "trip.h"

Trip::Trip(Vehicle* vehicle, Route* route, QDate date, int price, std::vector<int> seatOccupied) {
    this->setVehicle(vehicle);
    this->setRoute(route);
    this->setDate(date);
    this->setPrice(price);
    this->setSeatOccupied(seatOccupied);
}

std::vector<int> Trip::getSeatOccupied()
{
    return seatOccupied;
}

void Trip::setSeatOccupied(std::vector<int> &newSeatOccupied)
{
    seatOccupied = newSeatOccupied;
}

int Trip::getPrice() const
{
    return price;
}

void Trip::setPrice(int newPrice)
{
    price = newPrice;
}

void Trip::setDate(const QDate &newDate)
{
    date = newDate;
}

QDate Trip::getDate() const
{
    return date;
}

Route *Trip::getRoute() const
{
    return route;
}

void Trip::setRoute(Route *newRoute)
{
    route = newRoute;
}

Vehicle *Trip::getVehicle() const
{
    return vehicle;
}

void Trip::setVehicle(Vehicle *newVehicle)
{
    vehicle = newVehicle;
}
