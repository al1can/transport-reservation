#ifndef TRAIN_H
#define TRAIN_H

#include "vehicle.h"
#include <QString>
#include "company.h"

class Train : public Vehicle
{
public:
    Train(QString name, Company* company, int seatCount);
    int Train::CalculateFuelCost() override;
};

#endif // TRAIN_H
