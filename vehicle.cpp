#include "vehicle.h"

Company *Vehicle::getCompany() const
{
    return company;
}

void Vehicle::setCompany(Company *newCompany)
{
    company = newCompany;
}

int Vehicle::getSeatCount() const
{
    return seatCount;
}

void Vehicle::setSeatCount(int newSeatCount)
{
    seatCount = newSeatCount;
}

QString Vehicle::getName() const
{
    return name;
}

void Vehicle::setName(const QString &newName)
{
    name = newName;
}
