#include "myclickablewidget.h"
#include "ui_myclickablewidget.h"
#include <QtWidgets>
#include <QDebug>
#include <iostream>
#include <QLineF>
#include <QRectF>

using namespace std;

MyClickableWidget::MyClickableWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    //scene = new QGraphicsScene();
    setMinimumSize(450, 220);
    setMouseTracking(true);
    setSceneRect(10,10,450,220);
    setScene(scene);
    scene->update();
    cant=0;
    cantV=0;
    contName=1;
}

void MyClickableWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton){
        cout<<"Mouse x: "<<event->x()<<endl;
        cout<<"Mouse y: "<<event->y()<<endl;
    }

    string tmpStr = "Nodo";
    string nam = tmpStr + std::to_string(contName);
    QPointF pt = mapToScene(event->pos());

    agregarVertice(1,pt.x()-25, pt.y()-25, nam);
    contName++;
    scene->update();
    draw();
}

void MyClickableWidget::agregarVertice(int p, int x, int y, string n)
{
    VerticeClass* nuevo = new VerticeClass(p,x,y,n);
    grafito.vertices.push_back(nuevo);
    QRectF vertNuevo(x,y, 50.0, 50.0);
    vertices.push_back(vertNuevo);
    for(unsigned int i=0;i<vertices.size();i++)
    {
        verticeCam.push_back(false);
    }
    for(unsigned int i=0;i<aristas.size();i++)
    {
        aristaCam.push_back(false);
    }
    scene->update();
    update();
}
void MyClickableWidget::agregarArista(int p, int from, int to){
    /*
    int fromIndex;
    int toIndex;
    for (int i = 0; i<grafito.vertices.size();i++)
    {
        if(grafito.vertices[i]->name == from)
        {
            fromIndex=i;
        }
    }
    for (int i = 0; i<grafito.vertices.size();i++)
    {
        if(grafito.vertices[i]->name == to)
        {
            toIndex=i;
        }
    }
    */
    if(grafito.vertices[from-1]!=NULL && grafito.vertices[to-1]!=NULL)
    {
        VerticeClass* fromu = grafito.vertices[from-1];
        VerticeClass* tou = grafito.vertices[to-1];
        AristaClass* nuevaArista = new AristaClass(p,fromu,tou);
        nuevaArista->id=cant;
        grafito.vertices[from-1]->aristas.push_back(nuevaArista);
        QRectF oc(fromu->ex,fromu->ey, tou->ex,tou->ey);
        aristas.push_back(oc);
        cant++;
    }
    for(unsigned int g=0;g<vertices.size();g++)
    {
        verticeCam.push_back(false);
    }
    for(unsigned int gg=0;gg<aristas.size();gg++)
    {
        aristaCam.push_back(false);
    }
    scene->update();
    update();
}
int MyClickableWidget::getMinValue(VerticeClass*v)
{

}
void MyClickableWidget::reset(){

}
void MyClickableWidget::dijkstra(){

}
void MyClickableWidget::eliminarVertice(int p){

}
void MyClickableWidget::eliminarArista(int p){

}
void MyClickableWidget::draw(){
    QPen pen;
    pen.setWidth(4);
    for(unsigned int p=0;p<aristas.size();p++)
    {
        if(aristaCam[p]==true)
        {
            int xa = aristas[p].x();
            int ya = aristas[p].y();
            int xb = aristas[p].width();
            int yb = aristas[p].height();
            pen.setColor(Qt::yellow);
            scene->addLine(xa+25,ya+25,xb+25,yb+25, pen);
        }
        else
        {
            int xa = aristas[p].x();
            int ya = aristas[p].y();
            int xb = aristas[p].width();
            int yb = aristas[p].height();
            pen.setColor(Qt::black);
            scene->addLine(xa+25,ya+25,xb+25,yb+25, pen);
        }
    }
    for(unsigned int c=0;c<vertices.size();c++)
    {
        if(verticeCam[c]==true)
        {
            pen.setColor(Qt::yellow);
            scene->addEllipse(vertices.at(c),pen,QBrush(Qt::lightGray,Qt::SolidPattern));
        }
        else
        {
            pen.setColor(Qt::black);
            scene->addEllipse(vertices.at(c),pen,QBrush(Qt::lightGray,Qt::SolidPattern));
            QGraphicsTextItem* text;
            string namem = grafito.vertices.at(c)->name;
            QString qstr = QString::fromStdString(namem);
            text= scene->addText(qstr,QFont("Arial", 11));
            text->setPos(vertices.at(c).x(), vertices.at(c).y()+10);
        }
    }
    scene->update();
}

void MyClickableWidget::on_pushButton_2_clicked()
{
    int from = ui->fromText->text().toInt();
    int to = ui->toText->text().toInt();
    int peso = ui->peso->text().toInt();
    if(from<=0 || from>cant){
        cout<<"'Desde' invalido"<<endl;
    }
    else if(to<=0 || to>cant){
        cout<<"'Hasta' invalido"<<endl;
    }
    else if(to==to || from==from){
        cout<<"No puede ser el mismo"<<endl;
    }
    else{
        agregarArista(peso,from,to);
        scene->update();
        update();
    }
}

