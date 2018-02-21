#ifndef CLICKABLEWIDGET_H
#define CLICKABLEWIDGET_H

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
#include "customscene.h"

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

//! [0]
class ClickableWidget : public QGraphicsView
{
public:
    ClickableWidget(QWidget *parent = 0);
    GrafoClass grafito;

    QGraphicsScene* scene=new QGraphicsScene;

    void agregarVertice(int p, int x, int y);
    void agregarArista(int p, int from, int to);
    void dijkstra();
    void eliminarVertice(int p);
    void eliminarArista(int p);
    int getMinValue(VerticeClass*v);
    void reset();
    void draw();

    vector<QRectF> vertices;
    vector<QRectF> aristas;
    static int cant;
    static int cantV;
    vector<bool> verticeCam;
    vector<bool> aristaCam;
protected:
    void mousePressEvent(QMouseEvent *event) override;
    /*
    void paintEvent(QPaintEvent *event) override;
    */
};
#endif // CLICKABLEWIDGET_H
