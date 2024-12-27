#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>
#include "transport.h"

namespace Ui {
class AdminPage;
}

class AdminPage : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPage(QWidget *parent = nullptr);
    ~AdminPage();

    void resetListView();

    int hizmetbedeli = 1000;

    int getHizmetbedeli() const;
    void setHizmetbedeli(int newHizmetbedeli);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::AdminPage *ui;
};

#endif // ADMINPAGE_H
