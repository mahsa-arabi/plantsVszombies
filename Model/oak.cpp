#include "Oak.h"

Oak::Oak(QGraphicsScene * scene,const int& pixPermiliSec)
{
    this->scene=scene;
     scene->addItem(this);
    walkLevel=0;
    oakTimer=new QTimer();

    connect(oakTimer,SIGNAL(timeout()),this,SLOT(moveToRight()));
    oakTimer->start(50);

    this->pixPermiliSec=pixPermiliSec;
}

Oak::~Oak()
{
    scene->removeItem(this);
    delete oakTimer;
}

void Oak::moveToRight()
{
    walkLevel++;
    //oak move
    if(walkLevel==1){
        setPixmap(QPixmap(":/images/Oak1.png"));
    }else if(walkLevel==2){
        setPixmap(QPixmap(":/images/Oak2.png"));
    }else if(walkLevel==3){
        setPixmap(QPixmap(":/images/Oak3.png"));
    }else if(walkLevel==4 ){
        setPixmap(QPixmap(":/images/Oak4.png"));
    }
    if(walkLevel%4==0){
        walkLevel=0;
    }

   setPos((x()+pixPermiliSec),y());
   if(x()>800){
      // scene()->removeItem(this);
       delete this;
   }
}

