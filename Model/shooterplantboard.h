#ifndef SHOOTERPLANTBOARD_H
#define SHOOTERPLANTBOARD_H

#include "ground.h"
#include "Model/score.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QGraphicsScene>
class ShooterPlantBoard:public QGraphicsPixmapItem
{

private:
       QGraphicsScene * scene;
       bool isSelected=false;
       Score *score;
       QList<Ground*> blocks;
public:
    ShooterPlantBoard(QGraphicsScene * scene,Score *score,QList<Ground*> blocks);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

};
#endif // SHOOTERPLANTBOARD_H
