#include "ground.h"
#include "sunflowerboard.h"


SunFlowerBoard::SunFlowerBoard(QGraphicsScene * scene,Score* score,QList<Ground*> blocks)
    :score{score},blocks{blocks}
{
   setPixmap(QPixmap(":/images/sunFBord1.png"));
   setPos(140,8);

    this->scene=scene;
    scene->addItem(this);
}

void SunFlowerBoard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected=!isSelected;
   if(score->getScore() >= 50 && isSelected){
      setPixmap(QPixmap(":/images/sunFBord2.png"));

          score->decreseScore(50);

         foreach (auto g,blocks) {
             g->isSunFSelectable=true;
         }
   }else
       setPixmap(QPixmap(":/images/sunFBord1.png"));
}

