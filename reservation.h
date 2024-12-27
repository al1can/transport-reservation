#ifndef RESERVATION_H
#define RESERVATION_H

#include "passenger.h"
#include "vehicle.h"
#include "trip.h"

class Reservation
{
public:
    Reservation(Passenger* passenger, Trip* trip, int seat, int price);

    Passenger passenger;
    Vehicle* vehicle;
    Trip* trip;
    int seat;
    Passenger getPassenger() const;
    void setPassenger(const Passenger &newPassenger);
    Vehicle *getVehicle() const;
    void setVehicle(Vehicle *newVehicle);
    int getSeat() const;
    void setSeat(int newSeat);
    Trip *getTrip() const;
    void setTrip(Trip *newTrip);
};

#endif // RESERVATION_H
