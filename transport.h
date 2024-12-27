#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "company.h"
#include "bus.h"
#include "airplane.h"
#include "train.h"
#include "vehicle.h"
#include "bus.h"
#include "trip.h"
#include "route.h"
#include "reservation.h"
#include <vector>
#include <QDate>
#include <QDebug>
#include <QRandomGenerator>

class Transport
{
public:
    Company* company_a = new Company("A", "asifre");
    Company* company_b = new Company("B", "bsifre");
    Company* company_c = new Company("C", "csifre");
    Company* company_d = new Company("D", "dsifre");
    Company* company_f = new Company("F", "fsifre");

    Bus* bus_a1 = new Bus("Otobus_A_1", company_a, 20);
    Bus* bus_a2 = new Bus("Otobus_A_2", company_a, 15);
    Bus* bus_b1 = new Bus("Otobus_B_1", company_b, 15);
    Bus* bus_b2 = new Bus("Otobus_B_2", company_b, 20);
    Bus* bus_c1 = new Bus("Otobus_C_1", company_c, 20);
    Airplane* airplane_c1 = new Airplane("Ucak_C_1", company_c, 30);
    Airplane* airplane_c2 = new Airplane("Ucak_C_2", company_c, 30);
    Train* train_d1 = new Train("Tren_D_1", company_d, 25);
    Train* train_d2 = new Train("Tren_D_2", company_d, 25);
    Train* train_d3 = new Train("Tren_D_3", company_d, 25);
    Airplane* airplane_f1 = new Airplane("Ucak_F_1", company_f, 30);
    Airplane* airplane_f2 = new Airplane("Ucak_F_2", company_f, 30);

    Route* route_1 = new Route("Route_1", {"Istanbul", "Kocaeli", "Bilecik", "Eskisehir", "Ankara"}, "Demiryolu");
    Route* route_2 = new Route("Route_2", {"Istanbul", "Kocaeli", "Bilecik", "Eskisehir", "Konya"}, "Demiryolu");
    Route* route_3 = new Route("Route_3", {"Istanbul", "Kocaeli", "Ankara"}, "Karayolu");
    Route* route_4 = new Route("Route_4", {"Istanbul", "Kocaeli", "Eskisehir", "Konya"}, "Karayolu");
    Route* route_5 = new Route("Route_5", {"Istanbul", "Konya"}, "Havayolu");
    Route* route_6 = new Route("Route_6", {"Istanbul", "Ankara"}, "Havayolu");

    static Transport& getInstance();
    std::vector<Company*>& getCompanies();
    std::vector<Vehicle*>& getVehicles();
    std::vector<Trip*>& getTrips();
    std::vector<Route*>& getRoutes();
    std::vector<Reservation*>& getReservations();

private:
    Transport();
    static Transport instance;
    std::vector<Company*> companies;
    std::vector<Vehicle*> vehicles;
    std::vector<Trip*> trips;
    std::vector<Route*> routes;
    std::vector<Reservation*> reservations;
};

#endif // TRANSPORT_H
