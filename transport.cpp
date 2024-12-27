#include "transport.h"
#include <QDebug>

Transport Transport::instance;

Transport& Transport::getInstance() {
    return instance;
}

std::vector<Company*>& Transport::getCompanies() {
    return companies;
}

std::vector<Vehicle*>& Transport::getVehicles() {
    return vehicles;
}

std::vector<Trip*>& Transport::getTrips() {
    return trips;
}

std::vector<Route*>& Transport::getRoutes() {
    return routes;
}

std::vector<Reservation*>& Transport::getReservations() {
    return reservations;
}

Transport::Transport() {
    companies.push_back(company_a);
    companies.push_back(company_b);
    companies.push_back(company_c);
    companies.push_back(company_d);
    companies.push_back(company_f);

    vehicles.push_back(bus_a1);
    vehicles.push_back(bus_a2);
    vehicles.push_back(bus_b1);
    vehicles.push_back(bus_b2);
    vehicles.push_back(bus_c1);
    vehicles.push_back(airplane_c1);
    vehicles.push_back(airplane_c2);
    vehicles.push_back(train_d1);
    vehicles.push_back(train_d2);
    vehicles.push_back(train_d3);
    vehicles.push_back(airplane_f1);
    vehicles.push_back(airplane_f2);

    QDate date;

    int randomInt = QRandomGenerator::global()->bounded(4, 11);
    date.setDate(2023, 12, randomInt);
    std::vector<int> seatOccupied;
    for (int i = 0; i < bus_a1->seatCount; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(2);
        seatOccupied.push_back(randomValue);
    }
    Trip* trip_1 = new Trip(bus_a1, route_3, date, 0, seatOccupied);
    seatOccupied.clear();

    randomInt = QRandomGenerator::global()->bounded(4, 11);
    date.setDate(2023, 12, randomInt);
    for (int i = 0; i < bus_a2->seatCount; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(2);
        seatOccupied.push_back(randomValue);
    }
    Trip* trip_2 = new Trip(bus_a2, route_3, date, 0, seatOccupied);
    seatOccupied.clear();

    randomInt = QRandomGenerator::global()->bounded(4, 11);
    for (int i = 0; i < bus_b1->seatCount; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(2);
        seatOccupied.push_back(randomValue);
    }
    date.setDate(2023, 12, randomInt);
    Trip* trip_3 = new Trip(bus_b1, route_3, date, 0, seatOccupied);
    seatOccupied.clear();

    randomInt = QRandomGenerator::global()->bounded(4, 11);
    for (int i = 0; i < bus_b2->seatCount; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(2);
        seatOccupied.push_back(randomValue);
    }
    date.setDate(2023, 12, randomInt);
    Trip* trip_4 = new Trip(bus_b2, route_4, date, 0, seatOccupied);
    seatOccupied.clear();

    randomInt = QRandomGenerator::global()->bounded(4, 11);
    for (int i = 0; i < bus_c1->seatCount; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(2);
        seatOccupied.push_back(randomValue);
    }
    date.setDate(2023, 12, randomInt);
    Trip* trip_5 = new Trip(bus_c1, route_4, date, 0, seatOccupied);
    seatOccupied.clear();

    randomInt = QRandomGenerator::global()->bounded(4, 11);
    for (int i = 0; i < airplane_c1->seatCount; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(2);
        seatOccupied.push_back(randomValue);
    }
    date.setDate(2023, 12, randomInt);
    Trip* trip_6 = new Trip(airplane_c1, route_5, date, 0, seatOccupied);
    seatOccupied.clear();

    randomInt = QRandomGenerator::global()->bounded(4, 11);
    for (int i = 0; i < airplane_c2->seatCount; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(2);
        seatOccupied.push_back(randomValue);
    }
    date.setDate(2023, 12, randomInt);
    Trip* trip_7 = new Trip(airplane_c2, route_5, date, 0, seatOccupied);
    seatOccupied.clear();

    randomInt = QRandomGenerator::global()->bounded(4, 11);
    for (int i = 0; i < train_d1->seatCount; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(2);
        seatOccupied.push_back(randomValue);
    }
    date.setDate(2023, 12, randomInt);
    Trip* trip_8 = new Trip(train_d1, route_1, date, 0, seatOccupied);
    seatOccupied.clear();

    randomInt = QRandomGenerator::global()->bounded(4, 11);
    for (int i = 0; i < train_d1->seatCount; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(2);
        seatOccupied.push_back(randomValue);
    }
    date.setDate(2023, 12, randomInt);
    Trip* trip_9 = new Trip(train_d2, route_2, date, 0, seatOccupied);
    seatOccupied.clear();

    randomInt = QRandomGenerator::global()->bounded(4, 11);
    for (int i = 0; i < train_d3->seatCount; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(2);
        seatOccupied.push_back(randomValue);
    }
    date.setDate(2023, 12, randomInt);
    Trip* trip_10 = new Trip(train_d3, route_2, date, 0, seatOccupied);
    seatOccupied.clear();

    randomInt = QRandomGenerator::global()->bounded(4, 11);
    for (int i = 0; i < airplane_f1->seatCount; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(2);
        seatOccupied.push_back(randomValue);
    }
    date.setDate(2023, 12, randomInt);
    Trip* trip_11 = new Trip(airplane_f1, route_6, date, 0, seatOccupied);
    seatOccupied.clear();

    randomInt = QRandomGenerator::global()->bounded(4, 11);
    for (int i = 0; i < airplane_f2->seatCount; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(2);
        seatOccupied.push_back(randomValue);
    }
    date.setDate(2023, 12, randomInt);
    Trip* trip_12 = new Trip(airplane_f2, route_6, date, 0, seatOccupied);
    seatOccupied.clear();

    trips.push_back(trip_1);
    trips.push_back(trip_2);
    trips.push_back(trip_3);
    trips.push_back(trip_4);
    trips.push_back(trip_5);
    trips.push_back(trip_6);
    trips.push_back(trip_7);
    trips.push_back(trip_8);
    trips.push_back(trip_9);
    trips.push_back(trip_10);
    trips.push_back(trip_11);
    trips.push_back(trip_12);

    routes.push_back(route_1);
    routes.push_back(route_2);
    routes.push_back(route_3);
    routes.push_back(route_4);
    routes.push_back(route_5);
    routes.push_back(route_6);

}
