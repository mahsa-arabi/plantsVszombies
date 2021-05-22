#include "sunflower.h"

SunFlower::SunFlower(QGraphicsScene * scene,Score* score):score{score}
{
    this->scene=scene;
   setPixmap(QPixmap(":/images/SunFlower 1.png"));
   time=new QTimer;
   level=0;
    sun();
   connect(time,SIGNAL(timeout()),this,SLOT(move()));
   time->start(10000);
   connect(time,SIGNAL(timeout()),this,SLOT(sun()));
   time->start(10000);
}
//SunFlower::SunFlower(QGraphicsScene * scene)
//{
//    this->scene=scene;
//   setPixmap(QPixmap(":/images/SunFlower 1.png"));
//   time=new QTimer;
//   level=0;
//   connect(time,SIGNAL(timeout()),this,SLOT(move()));
//   time->start(15000);
//   connect(time,SIGNAL(timeout()),this,SLOT(sun()));
//   time->start(15000);
//}

SunFlower::~SunFlower()
{
    scene->removeItem(this);
    delete time;
}
void SunFlower:: move(){
    level++;
    switch (level) {
    case 1:
        setPixmap(QPixmap(":/images/SunFlower 1.png"));
        break;
case 2:
        setPixmap(QPixmap(":/images/SunFlower 2.png"));
        level=0;
        break;
    }
}
void SunFlower:: sun(){
   Sun* sun1= new Sun(scene,score,nullptr,time);
   sun1->setPos(x(),y()+10);
}
