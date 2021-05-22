#ifndef START_H
#define START_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>


class Start:public QGraphicsView
{
private:
    QGraphicsScene* scene;
public:
    Start();
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // START_H
