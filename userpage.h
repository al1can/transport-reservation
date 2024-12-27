#ifndef USERPAGE_H
#define USERPAGE_H

#include <QDialog>
#include "mywidget.h"
#include "trip.h"
#include "vehicleseat.h"
#include "seferbul.h"

namespace Ui {
class UserPage;
}

class UserPage : public QDialog
{
    Q_OBJECT

public:
    explicit UserPage(QWidget *parent = nullptr);
    ~UserPage();
    MyWidget* myWidget;
    VehicleSeat* vehicleSeat = new VehicleSeat();
    SeferBul* seferBul = new SeferBul();

private slots:
    void on_pushButton_clicked();

public slots:
    void handleItemClicked(QListWidgetItem *item);
    void renderListView();
    void updateListView(QString startPos, QString destinationPos, QDate date);

signals:
    void updateVehicleSeat(Trip* trip);

private:
    Ui::UserPage *ui;
};

#endif // USERPAGE_H
