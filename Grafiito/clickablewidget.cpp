#include <QtWidgets>
#include "clickablewidget.h"
#include <QDebug>
#include <iostream>
#include <QLine>
using namespace std;

ClickableWidget::ClickableWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    //scene = new QGraphicsScene();
    setMinimumSize(600, 400);
    setMouseTracking(true);
    setSceneRect(0,0,600,400);
    setScene(scene);
    scene->update();

}

void ClickableWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton){
        cout<<"Mouse x: "<<event->x()<<endl;
        cout<<"Mouse y: "<<event->y()<<endl;
    }
    QPointF pt = mapToScene(event->pos());
    agregarVertice(1,pt.x()-20, pt.y()-20);
    scene->update();
    draw();
    /*
    scene->addEllipse(pt.x()-20, pt.y()-20, 40, 40,
                QPen(), QBrush(Qt::SolidPattern));
    */
}

void ClickableWidget::agregarVertice(int p, int x, int y)
{
    VerticeClass* nuevo = new VerticeClass(p,x,y,"");
    grafito.vertices.push_back(nuevo);
    QRectF vertNuevo(x,y, 60.0, 60.0);
    vertices.push_back(vertNuevo);
    for(unsigned int i=0;i<vertices.size();i++)
    {
        verticeCam.push_back(false);
    }
    for(unsigned int i=0;i<aristas.size();i++)
    {
        aristaCam.push_back(false);
    }
    update();
}
void ClickableWidget::agregarArista(int p, int from, int to){

}
int ClickableWidget::getMinValue(VerticeClass*v)
{

}
void ClickableWidget::reset(){

}
void ClickableWidget::dijkstra(){

}
void ClickableWidget::eliminarVertice(int p){

}
void ClickableWidget::eliminarArista(int p){

}
void ClickableWidget::draw(){
    QPen pen;
    pen.setWidth(5);
    for(unsigned int c=0;c<vertices.size();c++)
    {
        if(verticeCam[c]==true)
        {
            pen.setColor(Qt::red);
            scene->addEllipse(vertices.at(c),pen,QBrush(Qt::SolidPattern));
        }
        else
        {
            pen.setColor(Qt::black);
            scene->addEllipse(vertices.at(c),pen,QBrush(Qt::SolidPattern));
        }
    }
    for(unsigned int p=0;p<aristas.size();p++)
    {
        if(aristaCam[p]==true)
        {
            int xa = aristas[p].x();
            int ya = aristas[p].y();
            int xb = aristas[p].width();
            int yb = aristas[p].height();
            pen.setColor(Qt::red);
            scene->addLine(xa+30,ya+30,xb+30,yb+30, pen);
        }
        else
        {
            int xa = aristas[p].x();
            int ya = aristas[p].y();
            int xb = aristas[p].width();
            int yb = aristas[p].height();
            pen.setColor(Qt::black);
            scene->addLine(xa+30,ya+30,xb+30,yb+30, pen);
        }
    }
    scene->update();

}
