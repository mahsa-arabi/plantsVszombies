#include "bullet.h"
#include "zombie.h"

Bullet::Bullet(QGraphicsScene * scene,const int& pixPerMiliSec)
{
    this->scene=scene;
    walkLevel=0;
    bulletTimer=new QTimer();
    setPixmap(QPixmap(":/images/Bullet 1.png"));
    scene->addItem(this);
    connect( bulletTimer,SIGNAL(timeout()),this,SLOT(move()));
     bulletTimer->start(50);

     this->pixPer50MiliSec=pixPerMiliSec;
}

Bullet::~Bullet()
{
    scene->removeItem(this);
    delete bulletTimer;
}
void Bullet::move()
{
    if(walkLevel==1){
        setPixmap(QPixmap(":/images/Bullet 1.png"));
    }else if(walkLevel==2){
        setPixmap(QPixmap(":/images/Bullet 2.png"));
    }else if(walkLevel==3){
        setPixmap(QPixmap(":/images/Bullet 3.png"));
    }
    if(walkLevel%3==0){
        walkLevel=0;
    }
    setPos(x()+pixPer50MiliSec,y());
    if(x()>800){
        scene->removeItem(this);
        delete this;
    }
}
