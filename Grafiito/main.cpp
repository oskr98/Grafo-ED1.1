#include "mainwindow.h"
#include <QApplication>
#include <QHBoxLayout>

#include "myclickablewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //QWidget mainWidget;
    //QGridLayout * gridLayout = new QGridLayout(&mainWidget);
    //gridLayout->addWidget( new MyClickableWidget);

    //mainWidget.setWindowTitle(QObject::tr("GraphNator 3000"));
    //mainWidget.show();

    return a.exec();
}
