#ifndef COMPANY_H
#define COMPANY_H

#include "user.h"
#include <QString>

class Company : public User
{
public:
    Company(QString name, QString password);

    QString companyName;
    QString getCompanyName() const;
    void setCompanyName(const QString &newCompanyName);
};

#endif // COMPANY_H
