#ifndef SEFERBUL_H
#define SEFERBUL_H

#include <QDialog>

namespace Ui {
class SeferBul;
}

class SeferBul : public QDialog
{
    Q_OBJECT

public:
    explicit SeferBul(QWidget *parent = nullptr);
    ~SeferBul();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SeferBul *ui;

signals:
    void UserPageResetListView(QString startPos, QString destinationPos, QDate date);

};

#endif // SEFERBUL_H
