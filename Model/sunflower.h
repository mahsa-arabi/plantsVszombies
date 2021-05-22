#ifndef SUNFLOWER_H
#define SUNFLOWER_H
#include <QObject>
#include "buyingthings.h"
#include <QTimer>
#include <QGraphicsScene>

#include "sun.h"

class SunFlower:public QObject,public BuyingThings
{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    QTimer* time;
    int level;
    Score* score;
public:
    SunFlower(QGraphicsScene * scene,Score* score);
    //SunFlower(QGraphicsScene * scene);
    ~SunFlower();

public slots:
   void move();
   void sun();

};

#endif // SUNFLOWER_H
