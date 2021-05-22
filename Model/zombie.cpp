#include "oak.h"
#include "bullet.h"
#include "gameovering.h"
#include "restart.h"
#include "shooterplant.h"
#include "sunflower.h"
#include "zombie.h"
#include <QException>
#include "ground.h"
#include <iostream>
Zombie::Zombie(QGraphicsScene * scene,Score* score,QList<Ground*> blocks,
               QList<Zombie*> controllerZombies,const int& pixPermiliSec,const int& lives)
    :score{score},blocks{blocks},controllerZombies{controllerZombies}

{
    this->lives=lives;
    this->scene=scene;
    scene->addItem(this);
    walkLevel=0;
    zombieTimer=new QTimer();

    connect(zombieTimer,SIGNAL(timeout()),this,SLOT(moveToLeft()));
    zombieTimer->start(50);

    this->pixPermiliSec=pixPermiliSec;
}

Zombie::~Zombie()
{
    scene->removeItem(this);
    delete zombieTimer;
}

void Zombie::shooted()
{
    lives--;
    if(lives==0){
        die();
    }else if (lives==1) {
        setPixmap(QPixmap(":/images/die3.png"));
     }else if (lives==2) {
        setPixmap(QPixmap(":/images/die2.png"));
    }else {
      setPixmap(QPixmap(":/images/die1.png"));
   }
}

void Zombie::die()
{
    lives=0;
    controllerZombies.removeOne(this);
    scene->removeItem(this);
    //delete this;
}

void Zombie::moveToLeft()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();


    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Bullet)){
            // remove them from the scene
            scene->removeItem(colliding_items[i]);
            shooted();

            // delete them from the heap
            delete colliding_items[i];

            return;
        }else if (typeid(*(colliding_items[i])) == typeid(Oak)) {
            scene->removeItem(colliding_items[i]);
            die();
            // delete them from the heap
            delete colliding_items[i];

            return;
       }else if (typeid(*(colliding_items[i])) == typeid(ShooterPlant)||
                 typeid(*(colliding_items[i])) == typeid(SunFlower)) {
           auto shovel=new ShovelBoard(scene,score,blocks);
                for (int j=0;j<blocks.count();++j) {
                    if(blocks[j]->x()==colliding_items[i]->x()){
                        block=blocks[j];
                    }
                }
                block->isPlanted=false;
            scene->removeItem(colliding_items[i]);
            // delete them from the heap
            delete colliding_items[i];
            return;
       }

    }
    walkLevel++;
    //zombie walk
    if(walkLevel==1){
        setPixmap(QPixmap(":/images/zombie1.png"));
    }else if(walkLevel==2){
        setPixmap(QPixmap(":/images/zombie2.png"));
    }else if(walkLevel==3){
        setPixmap(QPixmap(":/images/zombie3.png"));
    }else if(walkLevel==4){
        setPixmap(QPixmap(":/images/zombie2.png"));
    }
    if(walkLevel%4==0){
        walkLevel=0;
    }

   setPos((x()-pixPermiliSec),y());

//    if(x()<=0){
//         isGameOver=true;
//        scene->removeItem(this);
//        delete this;
//    }
}


