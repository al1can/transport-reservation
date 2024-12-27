#include "airplane.h"

Airplane::Airplane(QString name, Company* company, int seatCount) {
    this->setName(name);
    this->setCompany(company);
    this->setSeatCount(seatCount);
}

int Airplane::CalculateFuelCost() {
    return 0;
}
