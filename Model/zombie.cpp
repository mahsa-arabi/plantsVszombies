#include "zombie.h"

Zombie::Zombie(const int& pixPermiliSec)
{
    walkLevel=0;
    zombieTimer=new QTimer();

    //setPixmap(QPixmap(":/images/SunFlower 1.png"));

    connect(zombieTimer,SIGNAL(timeout()),this,SLOT(moveToLeft()));
    zombieTimer->start(50);

    this->pixPermiliSec=pixPermiliSec;
}

void Zombie::moveToLeft()
{
    walkLevel++;
    //oak
//    if(walkLevel==1){
//        setPixmap(QPixmap(":/images/Oak1.png"));
//    }else if(walkLevel==2){
//        setPixmap(QPixmap(":/images/Oak2.png"));
//    }else if(walkLevel==3){
//        setPixmap(QPixmap(":/images/Oak3.png"));
//    }else if(walkLevel==4 ){
//        setPixmap(QPixmap(":/images/Oak4.png"));
//    }
//    if(walkLevel%4==0){
//        walkLevel=0;
//    }

    //zombie walk
    if(walkLevel==1){
        setPixmap(QPixmap(":/images/zombie1.png"));
    }else if(walkLevel==2){
        setPixmap(QPixmap(":/images/zombie2.png"));
    }else if(walkLevel==3){
        setPixmap(QPixmap(":/images/zombie3.png"));
    }
    if(walkLevel%3==0){
        walkLevel=0;
    }
    //zombie dies
//    if(walkLevel==1){
//          setPixmap(QPixmap(":/images/die1.png"));
//      }else if(walkLevel==2){
//          setPixmap(QPixmap(":/images/die2.png"));
//      }else if(walkLevel==3){
//          setPixmap(QPixmap(":/images/die3.png"));
//      }else if(walkLevel==4 ){
//          setPixmap(QPixmap(":/images/die4.png"));
//      }else if(walkLevel==5 ){
//        setPixmap(QPixmap(":/images/die5.png"));
//    }
//      if(walkLevel%5==0){
//          walkLevel=0;
//      }

   setPos((x()-pixPermiliSec),y());

    if(x()==0){
        exit(1); //must be changed
    }
}

