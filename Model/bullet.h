#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    QTimer* bulletTimer;
    int walkLevel;
    int pixPer50MiliSec;
public:
    Bullet(QGraphicsScene * scene,const int& pixPerMiliSec=20);

    ~Bullet();
public slots:
    void move();
};

#endif // BULLET_H
