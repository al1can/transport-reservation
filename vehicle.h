#ifndef VEHICLE_H
#define VEHICLE_H

#include <QString>
#include "company.h"

class Vehicle
{
public:
    virtual int CalculateFuelCost() = 0;

    QString name;
    Company* company;
    int seatCount;
    QString getName() const;
    void setName(const QString &newName);
    Company *getCompany() const;
    void setCompany(Company *newCompany);
    int getSeatCount() const;
    void setSeatCount(int newSeatCount);
};

#endif // VEHICLE_H
