#ifndef COMPANYPAGE_H
#define COMPANYPAGE_H

#include <QDialog>
#include "transport.h"

namespace Ui {
class CompanyPage;
}

class CompanyPage : public QDialog
{
    Q_OBJECT

public:
    explicit CompanyPage(QWidget *parent = nullptr);
    ~CompanyPage();

    void resetVehicleListView();
    void resetTripListView();

    QString getCompanyName() const;
    void setCompanyName(const QString &newCompanyName);

public slots:
    void resetListView();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::CompanyPage *ui;
    QString companyName;
};

#endif // COMPANYPAGE_H
