#include "bosszombie.h"
#include "cherrybomb.h"


CherryBomb::CherryBomb(QGraphicsScene * scene)
{
    bombMusic=new QMediaPlayer();
    bombMusic->setMedia(QUrl("qrc:/sounds/bomb.mp3"));
    this->scene=scene;
    scene->addItem(this);
    time=new QTimer;
    setPixmap(QPixmap(":/images/bomb.png"));
    time->start(2000);
    bombMusic->play();
    connect(time,SIGNAL(timeout()),this,SLOT(explode()));

}

void CherryBomb::explode()
{

//    for(auto zombie:zombies){
//                if(zombie->x()>x()-100 && zombie->x()<x()+100){
//                    zombie->die();
//                }
//            }
    QList<QGraphicsItem *> colliding_items = collidingItems();


    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Zombie)
                || typeid(*(colliding_items[i])) == typeid(BossZombie)){

            scene->removeItem(colliding_items[i]);
            colliding_items[i]->setX(1000);
            scene->removeItem(this);
            delete this;
            return;
        }
    }
     scene->removeItem(this);
     delete this;
}
CherryBomb::~CherryBomb()
{
     delete time;
     delete bombMusic;
}
