#ifndef SUNFLOWERBOARD_H
#define SUNFLOWERBOARD_H

#include "ground.h"
#include "Model/score.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QGraphicsScene>
class SunFlowerBoard:public QGraphicsPixmapItem
{

private:
       QGraphicsScene * scene;
       bool isSelected=false;
       Score *score;
       QList<Ground*> blocks;
public:
    SunFlowerBoard(QGraphicsScene * scene,Score *score,QList<Ground*> blocks);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

};
#endif // SUNFLOWERBOARD_H
