#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include "admin.h"

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = nullptr);
    ~AdminLogin();
    Admin* admin = new Admin();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AdminLogin *ui;
};

#endif // ADMINLOGIN_H
