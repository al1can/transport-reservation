#include "route.h"

Route::Route() {}

Route::Route(QString name, std::vector<QString> route, QString type) {
    this->setName(name);
    this->setRoute(route);
    this->setType(type);
    this->setStartPos(this->route[0]);
    this->setDestinationPos(this->route[this->route.size() - 1]);

}

QString Route::getType() const
{
    return type;
}

void Route::setType(const QString &newType)
{
    type = newType;
}

QString Route::getDestinationPos() const
{
    return destinationPos;
}

void Route::setDestinationPos(const QString &newDestinationPos)
{
    destinationPos = newDestinationPos;
}

QString Route::getStartPos() const
{
    return startPos;
}

void Route::setStartPos(const QString &newStartPos)
{
    startPos = newStartPos;
}

std::vector<QString> Route::getRoute()
{
    return route;
}

void Route::setRoute(const std::vector<QString> &newRoute)
{
    route = newRoute;
}

QString Route::getName() const
{
    return name;
}

void Route::setName(const QString &newName)
{
    name = newName;
}
