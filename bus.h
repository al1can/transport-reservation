#ifndef BUS_H
#define BUS_H

#include "vehicle.h"
#include <QString>
#include "company.h"

class Bus : public Vehicle
{
public:
    Bus(QString name, Company* company, int seatCount);
    int Bus::CalculateFuelCost() override;
};

#endif // BUS_H
