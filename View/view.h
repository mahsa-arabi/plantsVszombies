#ifndef VIEW_H
#define VIEW_H


#include "../Controller/controller.h"
#include <QGraphicsView>
#include <QPushButton>
#include "../Model/gameovering.h"
#include "../Model/bosszombie.h"
#include <QObject>
#include "Model/score.h"
#include "Model/sunflower.h"
#include "Model/shooterplant.h"
#include "../Model/zombie.h"
#include <QMediaPlayer>
#include <QScrollBar>
#include <Model/bombboard.h>
#include <Model/oakboard.h>

#include <Model/shooterplantboard.h>
#include <Model/shovelboard.h>
#include <Model/sunflowerboard.h>
#include <Model/win.h>

class View: public QGraphicsView
{
Q_OBJECT
private:
    int secend=0;
    QTimer* viewTimer;
    QMediaPlayer* backhgroundMusic;
    GameOvering* g;
    Win* win;
    ShooterPlantBoard* sp;
    SunFlowerBoard* sf;
    ShovelBoard* shovel;
    OakBoard* oak;
    BombBoard* bomb;
    bool isGamedOverAlready=false;
    bool isWined=false;
public:
    View();
    ~View();
    bool isGameOver();
    bool isWinned();
    Controller* controller;
    void clearScene();
public slots:
    void l1();
    void s2l1();
    void s2l2();
    void s3l1();
    void s3l2();
    void s3l3();
    void plusSecendl1();
    void plusSecends2l1();
    void plusSecends2l2();
    void plusSecends3l1();
    void plusSecends3l2();
    void plusSecends3l3();

};

#endif // VIEW_H
