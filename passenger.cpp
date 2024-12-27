#include "passenger.h"

Passenger::Passenger(QString name, QString surname, QString Tc, QDate bdate) {
    this->setName(name);
    this->setSurname(surname);
    this->setTc(Tc);
    this->setBdate(bdate);
}

QString Passenger::getTc() const
{
    return Tc;
}

void Passenger::setTc(const QString &newTc)
{
    Tc = newTc;
}

QDate Passenger::getBdate() const
{
    return bdate;
}

void Passenger::setBdate(const QDate &newBdate)
{
    bdate = newBdate;
}
