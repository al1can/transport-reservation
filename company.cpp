#include "company.h"

Company::Company(QString name, QString password) {
    this->setCompanyName(name);
    this->setName(name);
    this->setPassword(password);
}

QString Company::getCompanyName() const
{
    return companyName;
}

void Company::setCompanyName(const QString &newCompanyName)
{
    companyName = newCompanyName;
}
