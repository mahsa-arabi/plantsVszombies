#ifndef RESTART_H
#define RESTART_H

#include <QGraphicsPixmapItem>

#include <Controller/controller.h>

#include <View/view.h>



class ReStart : public QGraphicsPixmapItem
{
private:
   // Controller* controller;
    View * view;
public:
    ReStart(View * view);
     void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // RESTART_H
