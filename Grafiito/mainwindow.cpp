#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myclickablewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gView = ui->graphicsView;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    int from = ui->fromText->text().toInt();
    int to = ui->toText->text().toInt();
    int peso = ui->peso->text().toInt();
    gView->agregarArista(peso,from,to);
    gView->draw();
    gView->update();
}
