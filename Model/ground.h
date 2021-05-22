#ifndef GROUND_H
#define GROUND_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "Model/oak.h"
#include "Model/shovel.h"
#include "Model/sunflower.h"
#include "Model/zombie.h"

class Ground:public QGraphicsPixmapItem
{
private:
    QGraphicsScene * scene;
    BuyingThings* planted;
    Score* score;
    QList<Ground*> otherBlocks;
    int elementNum;
public:
      bool isOakSelectable=false;
      bool isShooterSelectable=false;
      bool isSunFSelectable=false;
      bool isBombSelectable=false;
      bool isShovelSelectable=false;
      bool isPlanted=false;
     Ground(QGraphicsScene * scene,Score* score,int elementNum);
     void mousePressEvent(QGraphicsSceneMouseEvent* event);
     void setOtherBlocks(const QList<Ground *> &value);
     void removePlant();
};

#endif // GROUND_H
