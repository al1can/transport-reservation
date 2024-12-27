#include "user.h"

User::User() {}

QString User::getName() const
{
    return name;
}

void User::setName(const QString &newName)
{
    name = newName;
}

QString User::getPassword() const
{
    return password;
}

void User::setPassword(const QString &newPassword)
{
    password = newPassword;
}
