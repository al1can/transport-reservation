#ifndef COMPANYLOGIN_H
#define COMPANYLOGIN_H

#include <QDialog>

namespace Ui {
class CompanyLogin;
}

class CompanyLogin : public QDialog
{
    Q_OBJECT

public:
    explicit CompanyLogin(QWidget *parent = nullptr);
    ~CompanyLogin();

    std::map<std::string, std::string> CompanyCredentials;

    std::map<std::string, std::string> getCompanyCredentials() const;
    void setCompanyCredentials(const std::map<std::string, std::string> &newCompanyCredentials);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CompanyLogin *ui;
};

#endif // COMPANYLOGIN_H
