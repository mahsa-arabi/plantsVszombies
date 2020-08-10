#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model/bosszombie.h"
#include "Model/zombie.h"
#include <vector>
#include "View/level.h"
#include "Model/Score.h"
class Controller
{
private:
   std::vector<Zombie> zombies;
   std::vector<BossZombie> bossZombies;
   Level currentLevel;
   Score score;
   bool isGameOver;
public:
    Controller(Level currentLevel);
};

#endif // CONTROLLER_H
