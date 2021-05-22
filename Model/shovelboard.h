#ifndef SHOVELBOARD_H
#define SHOVELBOARD_H


#include "ground.h"
#include "score.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QGraphicsScene>
class ShovelBoard:public QGraphicsPixmapItem
{

private:
      QGraphicsScene * scene;
       bool isSelected=false;
       Score* score;
       QList<Ground*> blocks;
public:
    ShovelBoard(QGraphicsScene * scene,Score* score,QList<Ground*> blocks);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

};

#endif // SHOVELBOARD_H
