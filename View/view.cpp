#include "view.h"
#include <QLabel>
#include <QMediaPlaylist>
#include <QWindow>
#include <iostream>
View::View()
{
    viewTimer=new QTimer();
    controller=new Controller();
    setScene(controller->scene);
    setFixedSize(800,750);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    controller->scene->addItem(controller->score);

    //add background music and play it in a loop
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/backGroundSound.mpeg"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

   backhgroundMusic= new QMediaPlayer();
    backhgroundMusic->setPlaylist(playlist);
    backhgroundMusic->play();


    backhgroundMusic->play();

    viewTimer->start(1000);
     g=new GameOvering();
     win=new Win();
     l1();

}

void View::l1()
{
    if(isGamedOverAlready){
        controller->scene->addItem(g);
    }
    secend=0;
    setBackgroundBrush(QBrush(QImage(":/images/BackGround 1.png")));
    controller->addBlocks(1);
    sp=new ShooterPlantBoard(controller->scene,controller->score,controller->blocks);
    sf=new SunFlowerBoard(controller->scene,controller->score,controller->blocks);
    shovel=new ShovelBoard(controller->scene,controller->score,controller->blocks);
    connect(viewTimer,SIGNAL(timeout()),this,SLOT(plusSecendl1()));
}

void View::s2l1()
{
    if(isGamedOverAlready){
        controller->scene->addItem(g);
    }else if(isWined){
        controller->scene->addItem(win);
    }
    secend=0;
     setBackgroundBrush(QBrush(QImage(":/images/BackGround 2.png")));
     controller->addBlocks(2);
    sp=new ShooterPlantBoard(controller->scene,controller->score,controller->blocks);
    sf=new SunFlowerBoard(controller->scene,controller->score,controller->blocks);
    shovel=new ShovelBoard(controller->scene,controller->score,controller->blocks);
    oak=new OakBoard(controller->scene,controller->score,controller->blocks);
     connect(viewTimer,SIGNAL(timeout()),this,SLOT(plusSecends2l1()));
}
void View::s2l2()
{
    if(isGamedOverAlready){
        controller->scene->addItem(g);
    }else{
         controller->scene->addItem(win);
    }
    secend=0;
    setBackgroundBrush(QBrush(QImage(":/images/BackGround 2.png")));
     controller->addBlocks(2);
     sp=new ShooterPlantBoard(controller->scene,controller->score,controller->blocks);
     sf=new SunFlowerBoard(controller->scene,controller->score,controller->blocks);
     shovel=new ShovelBoard(controller->scene,controller->score,controller->blocks);
     oak=new OakBoard(controller->scene,controller->score,controller->blocks);

    connect(viewTimer,SIGNAL(timeout()),this,SLOT(plusSecends2l2()));
}

void View::s3l1()
{
    if(isGamedOverAlready){
        controller->scene->addItem(g);
    }else if(isWined){
        controller->scene->addItem(win);
    }
    secend=0;
    setBackgroundBrush(QBrush(QImage(":/images/BackGround 3.png")));
    controller->addBlocks(3);
    sp=new ShooterPlantBoard(controller->scene,controller->score,controller->blocks);
    sf=new SunFlowerBoard(controller->scene,controller->score,controller->blocks);
    shovel=new ShovelBoard(controller->scene,controller->score,controller->blocks);
    oak=new OakBoard(controller->scene,controller->score,controller->blocks);
    bomb=new BombBoard(controller->scene,controller->score,controller->blocks);
    connect(viewTimer,SIGNAL(timeout()),this,SLOT(plusSecends3l1()));
}

void View::s3l2()
{
    if(isGamedOverAlready){
        controller->scene->addItem(g);
    }else if(isWined){
        controller->scene->addItem(win);
    }
    secend=0;
    setBackgroundBrush(QBrush(QImage(":/images/BackGround 3.png")));
    controller->addBlocks(3);
    sp=new ShooterPlantBoard(controller->scene,controller->score,controller->blocks);
    sf=new SunFlowerBoard(controller->scene,controller->score,controller->blocks);
    shovel=new ShovelBoard(controller->scene,controller->score,controller->blocks);
    oak=new OakBoard(controller->scene,controller->score,controller->blocks);
    bomb=new BombBoard(controller->scene,controller->score,controller->blocks);
    connect(viewTimer,SIGNAL(timeout()),this,SLOT(plusSecends3l2()));
}

void View::s3l3()
{
    if(isGamedOverAlready){
        controller->scene->addItem(g);
    }else if(isWined){
        controller->scene->addItem(win);
    }
    secend=0;
    setBackgroundBrush(QBrush(QImage(":/images/BackGround 3.png")));
    controller->addBlocks(3);
    sp=new ShooterPlantBoard(controller->scene,controller->score,controller->blocks);
    sf=new SunFlowerBoard(controller->scene,controller->score,controller->blocks);
    shovel=new ShovelBoard(controller->scene,controller->score,controller->blocks);
    oak=new OakBoard(controller->scene,controller->score,controller->blocks);
    bomb=new BombBoard(controller->scene,controller->score,controller->blocks);
    connect(viewTimer,SIGNAL(timeout()),this,SLOT(plusSecends3l3()));
}

void View::plusSecendl1()
{
    controller->scene->removeItem(g);
    controller->scene->removeItem(win);
   ++secend;
     if (!isGameOver()) {
        if(secend%6==0||secend==1){
            auto sun=new Sun(controller->scene,controller->score,controller->holder,viewTimer);
        }
  if(secend==50||secend==54||secend==57||secend==59||secend==60){
       auto z=new Zombie(controller->scene,controller->score,controller->blocks,controller->zombies);
       controller->addZombie(z);
       z->setPos(800,500);
    }
    if(secend==76){
        isWined=true;
        clearScene();
        s2l1();
         isGamedOverAlready=false;
    }
}else{
         ++secend;
         isWined=false;
         isGamedOverAlready=true;
         clearScene();
         l1();
    }

}
void View::plusSecends2l1()
{
    controller->scene->removeItem(g);
    controller->scene->removeItem(win);
          ++secend;
    if (!isGameOver()) {
          int a=rand();
          if(secend%5==0||secend==1){
              auto sun=new Sun(controller->scene,controller->score,controller->holder,viewTimer);
          }
          if(secend==50||secend==58||secend==62||secend==63){
               auto z=new Zombie(controller->scene,controller->score,controller->blocks,controller->zombies);
              controller->addZombie(z);
              if(a%2==0)
                 {
                  z->setPos(800,350);
              }
              else{ z->setPos(800,500);
                  }
          }
          if(secend==55||secend==60||secend==63||secend==64){
            auto z=new Zombie(controller->scene,controller->score,controller->blocks,controller->zombies);
              controller->addZombie(z);
              if(a%2==0)
                 {
                  z->setPos(800,500);
                 }
              else{ z->setPos(800,350);
                }
          }
          if(secend==78){
              isWined=true;
              isGamedOverAlready=false;
              clearScene();
              s2l2();

          }
    }else{
        ++secend;
        isWined=false;
        isGamedOverAlready=true;
        clearScene();
        s2l1();
        }

}

void View::plusSecends2l2()
{
    controller->scene->removeItem(g);
    controller->scene->removeItem(win);
          ++secend;
    if (!isGameOver()) {
          int a=rand();
          if(secend%5==0||secend==1){
              auto sun=new Sun(controller->scene,controller->score,controller->holder,viewTimer);
          }
          if(secend==45||secend==50||secend==54||secend==56){
               auto z=new Zombie(controller->scene,controller->score,controller->blocks,controller->zombies);
              controller->addZombie(z);
              if(a%2==0)
                 {
                  z->setPos(800,350);
              }
              else{ z->setPos(800,500);
                  }
          }
          if(secend==52||secend==56||secend==58||secend==60){
            auto z=new Zombie(controller->scene,controller->score,controller->blocks,controller->zombies);
              controller->addZombie(z);
              if(a%2==0)
                 {
                  z->setPos(800,500);
                 }
              else{ z->setPos(800,350);
                }
          }
          if(secend==77){
              isWined=true;
              isGamedOverAlready=false;
              clearScene();
              s3l1();

          }
    }else{
        ++secend;
        isWined=false;
        isGamedOverAlready=true;
        clearScene();
        s2l2();
        }
}

void View::plusSecends3l1()
{
    ++secend;
     controller->scene->removeItem(g);
     controller->scene->removeItem(win);
    if (!isGameOver()) {

          int a=rand();
          if(secend%5==0 || secend==1){
              auto sun=new Sun(controller->scene,controller->score,controller->holder,viewTimer);
          }
          if(secend==40||secend==48||secend==54||secend==57){
              auto z=new Zombie(controller->scene,controller->score,controller->blocks,controller->zombies);
              controller->addZombie(z);
              z->setPos(800,500);

          }
          if(secend==44||secend==48||secend==53||secend==56){
             auto z=new Zombie(controller->scene,controller->score,controller->blocks,controller->zombies);
              controller->addZombie(z);

              z->setPos(800,350);

          }
          if(secend==46||secend==50||secend==54||secend==56){
             auto z=new Zombie(controller->scene,controller->score,controller->blocks,controller->zombies);
              controller->addZombie(z);
              z->setPos(800,200);

          }
          if(secend==62){
              auto bz1=new BossZombie (controller->scene,controller->score,controller->blocks,controller->zombies);
              controller->addBossZombie(bz1);
              bz1->setPos(800,200);
              auto bz3=new BossZombie (controller->scene,controller->score,controller->blocks,controller->zombies);
              controller->addBossZombie(bz3);
              bz3->setPos(800,350);

          }if(secend==64){
              auto bz2=new BossZombie (controller->scene,controller->score,controller->blocks,controller->zombies);
              controller->addBossZombie(bz2);
              bz2->setPos(800,500);
          }if(secend==66){
              auto bz3=new BossZombie (controller->scene,controller->score,controller->blocks,controller->zombies);
              controller->addBossZombie(bz3);
              bz3->setPos(800,350);
          }

          if(secend==84){
              isWined=true;
               isGamedOverAlready=false;
              clearScene();
              s3l2();
          }
    }
          else{
               isWined=false;
                  isGamedOverAlready=true;
                  clearScene();
                  s3l1();
                  }
}

void View::plusSecends3l2()
{
    ++secend;
 controller->scene->removeItem(g);
 controller->scene->removeItem(win);
   if (!isGameOver()) {

         if(secend%5==0 || secend==1){
             auto sun=new Sun(controller->scene,controller->score,controller->holder,viewTimer);
         }
         if(secend==40||secend==48||secend==52||secend==61){
             auto z=new Zombie(controller->scene,controller->score,controller->blocks,controller->zombies);
             controller->addZombie(z);
             z->setPos(800,500);

         }
         if(secend==44||secend==48||secend==54||secend==61){
            auto z=new Zombie(controller->scene,controller->score,controller->blocks,controller->zombies);
             controller->addZombie(z);

             z->setPos(800,350);

         }
         if(secend==43||secend==50||secend==54||secend==61){
            auto z=new Zombie(controller->scene,controller->score,controller->blocks,controller->zombies);
             controller->addZombie(z);
             z->setPos(800,200);

         }
         if(secend==71){
             auto bz1=new BossZombie (controller->scene,controller->score,controller->blocks,controller->zombies,3,10);
             controller->addBossZombie(bz1);
             bz1->setPos(800,200);

         }if(secend==78){
             auto bz2=new BossZombie (controller->scene,controller->score,controller->blocks,controller->zombies,3,10);
             controller->addBossZombie(bz2);
             bz2->setPos(800,500);
         }if(secend==72){
             auto bz3=new BossZombie (controller->scene,controller->score,controller->blocks,controller->zombies,3,10);
             controller->addBossZombie(bz3);
             bz3->setPos(800,350);
         }
         if(secend==92){
             isWined=true;
              isGamedOverAlready=false;
            clearScene();
             s3l3();
         }
   }else{
       isWined=false;
       isGamedOverAlready=true;
       clearScene();
       s3l2();
       }

}

void View::plusSecends3l3()
{
     controller->scene->removeItem(g);
     controller->scene->removeItem(win);
    ++secend;
     if (!isGameOver()) {
         if(secend%3==0 || secend==1){
             auto sun=new Sun(controller->scene,controller->score,controller->holder,viewTimer);
         }
         if(secend==40||secend==48||secend==56||secend==60){
             auto z=new BossZombie (controller->scene,controller->score,controller->blocks,controller->zombies,1,10);
             controller->addBossZombie(z);
             z->setPos(800,500);

         }
         if(secend==44||secend==52||secend==60||secend==68){
             auto z=new BossZombie (controller->scene,controller->score,controller->blocks,controller->zombies,1,10);
             controller->addBossZombie(z);

             z->setPos(800,350);

         }
         if(secend==46||secend==54||secend==62||secend==70){
             auto z=new BossZombie (controller->scene,controller->score,controller->blocks,controller->zombies,1,10);
             controller->addBossZombie(z);
             z->setPos(800,200);

         }
         if(secend==72){
             auto bz1=new BossZombie (controller->scene,controller->score,controller->blocks,controller->zombies,1,10);
             controller->addBossZombie(bz1);
             bz1->setPos(800,200);

         }if(secend==80){
             auto bz2=new BossZombie (controller->scene,controller->score,controller->blocks,controller->zombies,1,10);
             controller->addBossZombie(bz2);
             bz2->setPos(800,500);
         }if(secend==74){
             auto bz3=new BossZombie (controller->scene,controller->score,controller->blocks,controller->zombies,1,10);
             controller->addBossZombie(bz3);
             bz3->setPos(800,350);
         }
         if(secend==86){
             isWined=true;
             controller->scene->clear();
             auto win=new QGraphicsTextItem();
             win->setPlainText("You Win!!");
             win->setDefaultTextColor(Qt::green);
             win->setFont(QFont("times",18));
             win->setPos(250,250);
             controller->scene->addItem(win);
              isGamedOverAlready=false;
         }
     }else{
          isWined=false;
         isGamedOverAlready=true;
         clearScene();
         s3l3();
         }

}

void View::clearScene()
{
    controller->scene->clear();
    delete controller->scene;
    controller->scene=new QGraphicsScene();
    delete controller;
    controller=new Controller();
    setScene(controller->scene);
    setFixedSize(800,750);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    delete controller->score;
    controller->score=new Score();
    controller->scene->addItem(controller->score);
    delete viewTimer;
    viewTimer=new QTimer();
    viewTimer->start(1000);
}

bool View::isGameOver()
{
    for (int i=0;i<controller->countZombies();i++) {
        if(controller->zombies[i]->x()<=0 &&  controller->zombies[i]->lives!=0){
          return true;
        }
    }
    for (int i=0;i<controller->countBossZombies();i++) {
        if(controller->bossZombies[i]->x()<=0 &&  controller->bossZombies[i]->lives!=0){
          return true;
        }
    }
    return false;
}

bool View::isWinned()
{
    for (int i=0;i<controller->countZombies();i++) {
        if(controller->zombies[i]->lives!=0){
          return false;
        }
    }
    for (int i=0;i<controller->countBossZombies();i++) {
        if( controller->bossZombies[i]->lives!=0){
          return false;
        }
    }
    return true;
}
View::~View()
{
    delete controller;
    delete viewTimer;
    delete backhgroundMusic;
    delete g;
    delete sp;
    delete sf;
    delete shovel;
    delete oak;
    delete bomb;
}
