#include "reservation.h"

Reservation::Reservation(Passenger* passenger, Trip* trip, int seat, int price) {}

Trip *Reservation::getTrip() const
{
    return trip;
}

void Reservation::setTrip(Trip *newTrip)
{
    trip = newTrip;
}

int Reservation::getSeat() const
{
    return seat;
}

void Reservation::setSeat(int newSeat)
{
    seat = newSeat;
}

Vehicle *Reservation::getVehicle() const
{
    return vehicle;
}

void Reservation::setVehicle(Vehicle *newVehicle)
{
    vehicle = newVehicle;
}

Passenger Reservation::getPassenger() const
{
    return passenger;
}

void Reservation::setPassenger(const Passenger &newPassenger)
{
    passenger = newPassenger;
}
