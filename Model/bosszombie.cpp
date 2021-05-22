#include "oak.h"
#include "bosszombie.h"
#include "bullet.h"
#include "shooterplant.h"
#include "shovelboard.h"
#include "sunflower.h"

BossZombie::BossZombie(QGraphicsScene * scene,Score* score,QList<Ground*> blocks
                        ,QList<Zombie*> controllerZombies,const int &pixPerMiliSec,const int& lives)
   : Zombie(scene,score,blocks,controllerZombies)
{
    this->lives=lives;
    this->pixPermiliSec=pixPerMiliSec;
}

void BossZombie::moveToLeft()
{
    walkLevel++;
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
               scene->removeItem(colliding_items[i]);
               // delete them from the heap
               auto shovel=new ShovelBoard(scene,score,blocks);
                    for (int j=0;j<blocks.count();++j) {
                        if(blocks[j]->x()==colliding_items[i]->x()){
                            block=blocks[j];
                        }
                    }
                    block->isPlanted=false;
               delete colliding_items[i];
               return;
          }
       }
    if(walkLevel==1){
        setPixmap(QPixmap(":/images/boss1.png"));
    }else if(walkLevel==2){
        setPixmap(QPixmap(":/images/boss2.png"));
    }else if(walkLevel==3){
        setPixmap(QPixmap(":/images/boss3.png"));
    }
    if(walkLevel%3==0){
        walkLevel=0;
    }
    setPos((x()-pixPermiliSec),y());

//     if(x()==0){
//        isGameOver=true;
//        scene->removeItem(this);
//        delete this;
//     }
}
