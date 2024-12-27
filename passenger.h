#ifndef PASSENGER_H
#define PASSENGER_H

#include <qstring.h>
#include <QDate>
#include "person.h"

class Passenger : public Person
{
public:
    Passenger() {};
    Passenger(QString name, QString surname, QString Tc, QDate bdate);

    QString getTc() const;
    void setTc(const QString &newTc);

    QDate getBdate() const;
    void setBdate(const QDate &newBdate);

private:
    QString name;
    QString surname;
    QString Tc;
    QDate bdate;
};

#endif // PASSENGER_H
