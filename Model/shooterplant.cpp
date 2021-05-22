#include "shooterplant.h"

ShooterPlant::ShooterPlant(QGraphicsScene * scene)
{
    this->scene=scene;
    level=1;
    time=new QTimer();
    setPixmap(QPixmap(":/images/ShooterPlant 1.png"));
    scene->addItem(this);
    shooting1();
}

ShooterPlant::~ShooterPlant()
{
    scene->removeItem(this);
    delete time;
}
void ShooterPlant:: shooting(){
    Bullet * bullet = new Bullet(scene);
    bullet->setPos(x()+120,y());
    level++;
    switch (level) {
    case 1:
        setPixmap(QPixmap(":/images/ShooterPlant 1.png"));
        break;
    case 2:
        setPixmap(QPixmap(":/images/ShooterPlant 2.png"));
        break;
    case 3:
        setPixmap(QPixmap(":/images/ShooterPlant 3.png"));
        break;
    case 4:
        setPixmap(QPixmap(":/images/ShooterPlant 4.png"));
        level=0;
    } if(level%4==0){
        level=0;
    }

}

void ShooterPlant::shooting1()
{
    double blocksLeft=(800-x())/100;
    int n=0;
    for (int i=0;i<8;i++) {
        if(n<=blocksLeft){
            n++;
        }
    }
    time->start(250*n);
     connect(time,SIGNAL(timeout()),this,SLOT(shooting()));
}
