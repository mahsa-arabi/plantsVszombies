
#include "cherrybomb.h"
#include "ground.h"
#include "shooterplant.h"
#include <iostream>

Ground::Ground(QGraphicsScene * scene,Score* score,int elementNum):score{score}{
    setPixmap(QPixmap(":/images/groundS.png"));
    this->elementNum=elementNum;
    this->scene=scene;
    scene->addItem(this);
}

void Ground::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!isPlanted && isShooterSelectable){
       auto plant=new ShooterPlant(scene);
       plant->setPos(x(),y());
       scene->addItem(plant);

       isShooterSelectable=false;
      foreach (auto g,otherBlocks) {
          g->isShooterSelectable=false;
      }
       planted=plant;
       isPlanted=true;

    }else if(!isPlanted && isSunFSelectable){
        auto plant=new SunFlower(scene,score);
        plant->setPos(x(),y());
        scene->addItem(plant);
        isSunFSelectable=false;
       foreach (auto g,otherBlocks) {
           g->isSunFSelectable=false;
       }
        planted=plant;
        isPlanted=true;
    }else if( isOakSelectable){
        auto plant=new Oak(scene);
        plant->setPos(x(),y());
        scene->addItem(plant);
        isOakSelectable=false;
        foreach (auto g,otherBlocks) {
            g->isOakSelectable=false;
        }
    }else if(!isPlanted && isBombSelectable){
         auto plant=new CherryBomb(scene);
         plant->setPos(x(),y());
         scene->addItem(plant);
         isBombSelectable=false;
         foreach (auto g,otherBlocks) {
             g->isBombSelectable=false;
         }
        // isPlanted=true;
    }else if(isPlanted && isShovelSelectable){
         isShovelSelectable=false;
         foreach (auto g,otherBlocks) {
             g->isShovelSelectable=false;
         }
        scene->removeItem(planted);
        delete planted;
        isPlanted=false;
    }

}
void Ground::setOtherBlocks(const QList<Ground *> &value)
{
    otherBlocks = value;
}

void Ground::removePlant()
{
    scene->removeItem(planted);
    delete planted;
    isPlanted=false;
}
