#include "bombboard.h"
#include "ground.h"

BombBoard::BombBoard(QGraphicsScene * scene,Score* score,QList<Ground*> blocks)
    :score{score},blocks{blocks}
{
   setPixmap(QPixmap(":/images/bombBord1.png"));
   setPos(260,8);

    this->scene=scene;
    scene->addItem(this);
}

void BombBoard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    isSelected=!isSelected;
   if(score->getScore() >= 50 && isSelected){
      setPixmap(QPixmap(":/images/bombBord2.png"));

          score->decreseScore(50);

          foreach (auto g,blocks) {
              g->isBombSelectable=true;
          }
   }else
       setPixmap(QPixmap(":/images/bombBord1.png"));
}

