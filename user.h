#ifndef USER_H
#define USER_H

#include "iloginable.h"
#include <QString>

#pragma once

class User : ILoginable
{
public:
    User();

    QString getName() const;
    void setName(const QString &newName);

    QString getPassword() const;
    void setPassword(const QString &newPassword);

private:
    QString name;
    QString password;
};

#endif // USER_H
