#ifndef SHOVEL_H
#define SHOVEL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>


class Shovel :public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Shovel(QGraphicsScene * scene);
    ~Shovel();
private:
    QGraphicsScene * scene;
};

#endif // SHOVEL_H
