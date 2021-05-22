#ifndef ZOMBIE_H
#define ZOMBIE_H



#include "score.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>

class Ground;
class Zombie : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    QGraphicsScene * scene;
    QTimer* zombieTimer;

    int pixPermiliSec;
    int walkLevel;
    Score* score;
    QList<Ground*> blocks;
    Ground* block;
    QList<Zombie*> controllerZombies;

public:
    Zombie(QGraphicsScene * scene,Score* score,QList<Ground*> blocks,QList<Zombie*> controllerZombies
           ,const int& pixPermiliSec=3,const int& lives=4);
    ~Zombie();
    void shooted();
    void die();
    int lives;
signals:

public slots:
    virtual void moveToLeft();
};


#endif // ZOMBIE_H
