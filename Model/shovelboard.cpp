#include "shovelboard.h"
#include "ground.h"

ShovelBoard::ShovelBoard(QGraphicsScene * scene,Score* score,QList<Ground*> blocks)
    :score{score},blocks{blocks}
{
   setPixmap(QPixmap(":/images/shovelBoard1.jpg"));
   setPos(360,6);

    this->scene=scene;
    scene->addItem(this);
}

void ShovelBoard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected=!isSelected;
   if(isSelected){
      setPixmap(QPixmap(":/images/shovelBoard2.jpg"));

      foreach (auto g,blocks) {
          g->isShovelSelectable=true;
      }
   }else
       setPixmap(QPixmap(":/images/shovelBoard1.jpg"));

}

