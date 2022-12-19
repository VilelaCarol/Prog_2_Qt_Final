#include "gamewon.hpp"
#include "ui_gamewon.h"

gamewon::gamewon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamewon)
{
    ui->setupUi(this);
}

gamewon::~gamewon()
{
    delete ui;
}
