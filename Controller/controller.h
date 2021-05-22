#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model/bosszombie.h"
#include "Model/zombie.h"
#include <QMouseEvent>
#include <vector>
#include <QGraphicsRectItem>

#include "Model/score.h"
#include "Model/shooterplant.h"
#include "Model/sunflower.h"
#include "Model/oak.h"
#include <QObject>
#include <Model/ground.h>
class Controller : public QObject
{
    friend class View;
    Q_OBJECT
private:
    QList<Zombie*> zombies;
    QList<BossZombie*> bossZombies;
    QList<Sun*> suns;
    QGraphicsRectItem * holder;
    QTimer* ctimer;
    QList<Bullet*> balls;
    Score* score;
    bool isGameOver;
    QList<Ground*> blocks;
public:

    Controller();
    ~Controller();
    void addSun();
    void addZombie(Zombie* z);
    void addBossZombie(BossZombie* bz);
    QGraphicsScene* scene;
    void setIsGameOver(bool value);
    QList<ShooterPlant*> plants;
    void addBlocks(int seoson);
    int countZombies();
     int countBossZombies();
public slots:
        void dieZombies();

};

#endif // CONTROLLER_H
