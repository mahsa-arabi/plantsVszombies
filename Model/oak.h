#ifndef OAK_H
#define OAK_H

#include "buyingthings.h"

#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

class Oak: public QObject,public BuyingThings
{
    Q_OBJECT
    const  int price=150;
private:
    QGraphicsScene * scene;
    QTimer* oakTimer;
    int pixPermiliSec;
    int walkLevel;

public:
   Oak(QGraphicsScene * scene,const int& pixPermiliSec=10);
   ~Oak();

signals:

public slots:
    void moveToRight();
};

#endif // OAK_H
