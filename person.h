#ifndef PERSON_H
#define PERSON_H

#include <QString.h>

class Person
{
public:
    Person();

    QString name;
    QString surname;
    QString getName() const;
    void setName(const QString &newName);
    QString getSurname() const;
    void setSurname(const QString &newSurname);
};

#endif // PERSON_H
