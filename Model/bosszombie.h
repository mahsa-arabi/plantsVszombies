#ifndef BOSSZOMBIE_H
#define BOSSZOMBIE_H

#include "zombie.h"


class BossZombie : public Zombie
{
private:
    QTimer* bossTimer;
public:
    BossZombie(QGraphicsScene * scene,Score* score,QList<Ground*> blocks
               ,QList<Zombie*> controllerZombies,const int &pixPerMiliSec=2,const int& lives=6);
public slots:
    void moveToLeft()override;
};

#endif // BOSSZOMBIE_H
