#ifndef ROUTE_H
#define ROUTE_H

#include <QString>
#include <vector>

class Route
{
public:
    Route();
    Route(QString name, std::vector<QString> route, QString type);

    QString name;
    std::vector<QString> route;
    QString type;
    // kalkis noktasi
    QString startPos;
    // varis noktasi
    QString destinationPos;
    QString getName() const;
    void setName(const QString &newName);
    std::vector<QString> getRoute();
    void setRoute(const std::vector<QString> &newRoute);
    QString getStartPos() const;
    void setStartPos(const QString &newStartPos);
    QString getDestinationPos() const;
    void setDestinationPos(const QString &newDestinationPos);
    QString getType() const;
    void setType(const QString &newType);
};

#endif // ROUTE_H
