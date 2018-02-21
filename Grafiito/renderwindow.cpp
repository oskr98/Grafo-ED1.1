#include "renderwindow.h"

RenderWindow::RenderWindow(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
QSize RenderWindow::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderWindow::sizeHint() const
{
    return QSize(800, 400);
}

int RenderWindow::cant = 0;

void RenderWindow::agregarVertice(int p, int x, int y)
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
void RenderWindow::agregarArista(int p, int from, int to){

}
int RenderWindow::getMinValue(VerticeClass*v)
{

}
void RenderWindow::reset(){

}
void RenderWindow::dijkstra(){

}
void RenderWindow::eliminarVertice(int p){

}
void RenderWindow::eliminarArista(int p){

}
void RenderWindow::paintEvent(QPaintEvent * /* event */){
    QPen pen;
    pen.setWidth(5);
    QPainterPath path;
    QPainter painter(this);
    for(unsigned int c=0;c<vertices.size();c++)
    {
        if(verticeCam[c]==true)
        {
            pen.setColor(Qt::red);
            painter.setPen(pen);
            painter.drawEllipse(vertices.at(c));
        }
        else
        {
            pen.setColor(Qt::black);
            painter.setPen(pen);
            painter.drawEllipse(vertices.at(c));
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
            painter.setPen(pen);
            painter.drawLine(xa+30,ya+30,xb+30,yb+30);
        }
        else
        {
            int xa = aristas[p].x();
            int ya = aristas[p].y();
            int xb = aristas[p].width();
            int yb = aristas[p].height();
            pen.setColor(Qt::black);
            painter.setPen(pen);
            painter.drawLine(xa+30,ya+30,xb+30,yb+30);
        }
    }

}
