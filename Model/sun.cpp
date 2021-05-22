#include "sun.h"

Sun::Sun(QGraphicsScene * scene,Score* sunScore,QGraphicsItem* parent
         ,QTimer* timer): QObject (),QGraphicsPixmapItem (parent)
  ,scene{scene},timeInterval{0},sunScore{sunScore}

{
    setPixmap(QPixmap(":/images/sun.png"));

    scene->addItem(this);
    setPos(rand()%500,30);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveToDown()));
    timeInterval=0;
}

void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    sunScore->increseScore();
    scene->removeItem(this);
    delete this;
}
void Sun:: moveToDown(){
    timeInterval++;
    setPixmap(QPixmap(":/images/sun.png"));
    scene->addItem(this);
    setPos(x(),y()+6);
    if(timeInterval==2||y()==300){
        scene->removeItem(this);
        delete this;
     }
}
