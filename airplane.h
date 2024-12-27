#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "vehicle.h"
#include <QString>
#include "company.h"

class Airplane : public Vehicle
{
public:
    Airplane(QString name, Company* company, int seatCount);
    int Airplane::CalculateFuelCost() override;
};

#endif // AIRPLANE_H
