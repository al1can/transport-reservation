#include "train.h"

Train::Train(QString name, Company* company, int seatCount) {
    this->setName(name);
    this->setCompany(company);
    this->setSeatCount(seatCount);
}

int Train::CalculateFuelCost() {
    return 0;
}
