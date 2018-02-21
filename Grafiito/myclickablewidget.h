#ifndef MYCLICKABLEWIDGET_H
#define MYCLICKABLEWIDGET_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include <QPainter>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include "grafoclass.h"
#include "aristaclass.h"
#include "verticeclass.h"
#include <QFrame>
#include <QGraphicsView>
#include <QPointF>

namespace Ui {
class MyClickableWidget;
}

class MyClickableWidget : public QGraphicsView
{
    Q_OBJECT

public:
    MyClickableWidget(QWidget *parent = 0);
    GrafoClass grafito;

    QGraphicsScene* scene=new QGraphicsScene;

    void agregarVertice(int p, int x, int y, string nombre);
    void agregarArista(int p, int from, int to);
    void dijkstra();
    void eliminarVertice(int p);
    void eliminarArista(int p);
    int getMinValue(VerticeClass*v);
    void reset();
    void draw();

    vector<QRectF> vertices;
    vector<QRectF> aristas;
    int cant;
    int cantV;
    int contName;
    vector<bool> verticeCam;
    vector<bool> aristaCam;
    QGraphicsTextItem* text;

protected:
    void mousePressEvent(QMouseEvent *event) override;
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MyClickableWidget *ui;
};

#endif // MYCLICKABLEWIDGET_H
