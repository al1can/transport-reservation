#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

QString MyWidget::getRoute() const
{
    return route;
}

void MyWidget::setRoute(const QString &newRoute)
{
    route = newRoute;
}

QString MyWidget::getCompany() const
{
    return company;
}

void MyWidget::setCompany(const QString &newCompany)
{
    company = newCompany;
}

QString MyWidget::getDate() const
{
    return date;
}

void MyWidget::setDate(const QString &newDate)
{
    date = newDate;
}

QString MyWidget::getVehicle() const
{
    return vehicle;
}

void MyWidget::setVehicle(const QString &newVehicle)
{
    vehicle = newVehicle;
}

QString MyWidget::getSeatCount() const
{
    return seatCount;
}

void MyWidget::setSeatCount(const QString &newSeatCount)
{
    seatCount = newSeatCount;
}

void MyWidget::updateWidget(QString route,
                            QString seatCount,
                            QString vehicle,
                            QString date,
                            QString company) {
    this->setRoute(route);
    this->setSeatCount(seatCount);
    this->setVehicle(vehicle);
    this->setDate(date);
    this->setCompany(company);

    ui->route->setText(this->getRoute());
    ui->seatCount->setText(this->getSeatCount());
    ui->vehicle->setText(this->getVehicle());
    ui->date->setText(this->date);
    ui->company->setText(this->getCompany());
}

QSize MyWidget::sizeHint() const
{
    return QSize(400, 200);
}
