#include "bus.h"

Bus::Bus(QString name, Company* company, int seatCount) {
    this->setName(name);
    this->setCompany(company);
    this->setSeatCount(seatCount);
}

int Bus::CalculateFuelCost() {
    return 0;
}
