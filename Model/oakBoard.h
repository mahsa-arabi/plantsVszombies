#ifndef OAKBOARD_H
#define OAKBOARD_H


#include "ground.h"
#include "score.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QGraphicsScene>
class OakBoard:public QGraphicsPixmapItem
{

private:
      QGraphicsScene * scene;
       bool isSelected=false;
       Score* score;
       QList<Ground*> blocks;
public:
    OakBoard(QGraphicsScene * scene,Score* score,QList<Ground*> blocks);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);


};
#endif // OAKBOARD_H
