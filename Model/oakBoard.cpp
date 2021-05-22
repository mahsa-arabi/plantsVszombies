#include "ground.h"
#include "oakboard.h"
#include <iostream>

OakBoard::OakBoard(QGraphicsScene *scene,Score* score,QList<Ground*> blocks):score{score}
  ,blocks{blocks}
{
    setPixmap(QPixmap(":/images/oakBord1.png"));
    setPos(200,8);

     this->scene=scene;
     scene->addItem(this);
}

void OakBoard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected=!isSelected;
   if(score->getScore() >= 100 && isSelected){
      setPixmap(QPixmap(":/images/aokBord2.png"));

          score->decreseScore(100);
          foreach (auto g,blocks) {
              g->isOakSelectable=true;
          }
   }else
       setPixmap(QPixmap(":/images/oakBord1.png"));
}

