#ifndef BOMBBOARD_H
#define BOMBBOARD_H


#include "ground.h"
#include "score.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QGraphicsScene>
class BombBoard:public QGraphicsPixmapItem
{

private:
      QGraphicsScene * scene;
      Score* score;
       bool isSelected=false;
       QList<Ground*> blocks;
public:
    BombBoard(QGraphicsScene * scene,Score* score,QList<Ground*> blocks);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

};

#endif // BOMBBOARD_H
