#include "seferbul.h"
#include "ui_seferbul.h"
#include <qdebug.h>

#include <QMessageBox>

SeferBul::SeferBul(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SeferBul)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate(2023, 12, 4));
}

SeferBul::~SeferBul()
{
    delete ui;
}

void SeferBul::on_buttonBox_accepted()
{
    QString startPos = ui->lineEdit->text();
    QString destinationPos = ui->lineEdit_2->text();

    QDate date = ui->dateEdit->date();
    QDate dateStart = QDate(2023, 12, 4);
    QDate dateEnd = QDate(2023, 12, 10);
    if (!(date >= dateStart && date <= dateEnd)) {
        QMessageBox::critical(nullptr, "Error", "Yalnizca 4 ve 10 aralik arasindaki seferler secilebilir.", QMessageBox::Ok);
        return;
    }

    emit UserPageResetListView(startPos, destinationPos, date);
}

