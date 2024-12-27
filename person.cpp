#include "person.h"

Person::Person() {}

QString Person::getSurname() const
{
    return surname;
}

void Person::setSurname(const QString &newSurname)
{
    surname = newSurname;
}

QString Person::getName() const
{
    return name;
}

void Person::setName(const QString &newName)
{
    name = newName;
}
