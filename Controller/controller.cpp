#include "controller.h"
#include <iostream>
using namespace std;

int Controller::countZombies()
{
    return zombies.count();
}

int Controller::countBossZombies()
{
     return bossZombies.count();
}

Controller::Controller():QObject(){

    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,800,750);
    score=new Score();
    holder=new QGraphicsRectItem();
    holder->setRect(0,0,800,750);
    ctimer=new QTimer();
    ctimer->start();
    isGameOver=false;
}

void Controller::addSun()
{
    auto sun=new Sun{scene,score,holder,ctimer};
    suns.push_back(sun);
    scene->addItem(sun);
}

void Controller::addZombie(Zombie* z)
{
    zombies.push_back(z);
}

void Controller::addBossZombie(BossZombie *bz)
{
      bossZombies.push_back(bz);
}

void Controller::setIsGameOver(bool value)
{
    isGameOver = value;
}


void Controller::dieZombies()
{
    for(auto b:balls){
        for(auto z:zombies){
            if(b->x()==z->x()){
                z->shooted();
                scene->removeItem(b);
            }
        }
        for(auto z:bossZombies){
            if((b->x())==(z->x())){
                z->shooted();
                scene->removeItem(b);
            }
        }
    }
}

void Controller::addBlocks(int seoson)
{
    if(seoson==1){
        for (int i=0 ; i<8 ;++i) {
             auto ground=new Ground(scene,score,i);
             ground->setPos(100*i,550);
             blocks.push_back(ground);
        }
        for (int i=0 ; i<8 ;++i){
            QList<Ground*> other;
            for (int j=0;j<8;j++) {
                if(j==i){

                }else {
                    other.push_back(blocks[j]);
                 }

            }
               blocks[i]->setOtherBlocks(other);

        }

    }else if(seoson==2){
        for (int i=0 ; i<8 ;++i) {
             auto ground=new Ground(scene,score,i);
             ground->setPos(100*i,550);
             blocks.push_back(ground);
        }  for (int i=0 ; i<8 ;++i) {
            auto ground=new Ground(scene,score,(i+8));
            ground->setPos(100*i,400);
            blocks.push_back(ground);
       }
        for (int i=0 ; i<16 ;++i){
            QList<Ground*> other;
            for (int j=0;j<16;j++) {
                if(j==i){
                }else {
                    other.push_back(blocks[j]);
                 }

            }
               blocks[i]->setOtherBlocks(other);
        }

    }else if(seoson==3){
        for (int i=0 ; i<8 ;++i) {
             auto ground=new Ground(scene,score,i);
             ground->setPos(100*i,550);
             blocks.push_back(ground);
        }  for (int i=0 ; i<8 ;++i) {
            auto ground=new Ground(scene,score,(i+8));
            ground->setPos(100*i,400);
            blocks.push_back(ground);
       } for (int i=0 ; i<8 ;++i) {
            auto ground=new Ground(scene,score,(i+16));
            ground->setPos(100*i,250);
            blocks.push_back(ground);
       }
        for (int i=0 ; i<24 ;++i){
            QList<Ground*> other;
            for (int j=0;j<24;j++) {
                if(j==i){

                }else {
                    other.push_back(blocks[j]);
                 }

            }
               blocks[i]->setOtherBlocks(other);

        }

    }
}
Controller::~Controller()
{
    zombies.clear();
    foreach (auto z,zombies ) {
        delete z;
    }
   bossZombies.clear();
    foreach (auto z,bossZombies ) {
        delete z;
    }
    balls.clear();
    foreach (auto z,balls ) {
        delete z;
    }
     blocks.clear();
    foreach (auto z,blocks ) {
        delete z;
    }
   plants.clear();
    foreach (auto z,plants ) {
        delete z;
    }
    suns.clear();
    foreach (auto z,suns ) {
        delete z;
    }

//    delete scene;
//    delete holder;
 //   delete ctimer;
  //  delete score;

}
