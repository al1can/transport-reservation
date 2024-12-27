#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include <QDebug>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

    QString route;
    QString seatCount;
    QString vehicle;
    QString date;
    QString company;

    QString getSeatCount() const;
    void setSeatCount(const QString &newSeatCount);

    QString getVehicle() const;
    void setVehicle(const QString &newVehicle);

    QString getDate() const;
    void setDate(const QString &newDate);

    QString getCompany() const;
    void setCompany(const QString &newCompany);

    void updateWidget(QString route,
                      QString seatCount,
                      QString vehicle,
                      QString date,
                      QString company);

    QSize sizeHint() const override;

    QString getRoute() const;
    void setRoute(const QString &newRoute);

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
