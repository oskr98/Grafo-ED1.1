#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

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

using namespace std;

class RenderWindow : public QWidget
{
    Q_OBJECT
public:
    RenderWindow();
public:
    GrafoClass grafito;
    RenderWindow(QWidget *parent = 0);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    void agregarVertice(int p, int x, int y);
    void agregarArista(int p, int from, int to);
    void dijkstra();
    void eliminarVertice(int p);
    void eliminarArista(int p);
    int getMinValue(VerticeClass*v);
    void reset();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    vector<QRectF> vertices;
    vector<QRectF> aristas;
    static int cant;
    static int cantV;
    vector<bool> verticeCam;
    vector<bool> aristaCam;
};

#endif // RENDERWINDOW_H
