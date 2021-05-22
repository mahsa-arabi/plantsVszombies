#include "shovel.h"


Shovel::Shovel(QGraphicsScene * scene)
{
    this->scene=scene;
     scene->addItem(this);
     setPixmap(QPixmap(":/images/Shovel.png"));
}

Shovel::~Shovel()
{
    scene->removeItem(this);
}
