#include "dialogarista.h"
#include "ui_dialogarista.h"

DialogArista::DialogArista(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogArista)
{
    ui->setupUi(this);
}

DialogArista::~DialogArista()
{
    delete ui;
}
