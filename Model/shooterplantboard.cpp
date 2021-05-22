#include "shooterplantboard.h"

#include "ground.h"

ShooterPlantBoard::ShooterPlantBoard(QGraphicsScene * scene,Score* score
                                     ,QList<Ground*> blocks)
    :score{score},blocks{blocks}
{
   setPixmap(QPixmap(":/images/ShooterBord1.png"));
   setPos(80,8);

    this->scene=scene;
    scene->addItem(this);
}

void ShooterPlantBoard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     isSelected=!isSelected;
   if(score->getScore() >= 100 && isSelected){
      setPixmap(QPixmap(":/images/ShooterBord2.png"));

          score->decreseScore(100);

         foreach (auto g,blocks) {
             g->isShooterSelectable=true;
         }
   }else
       setPixmap(QPixmap(":/images/ShooterBord1.png"));
}

