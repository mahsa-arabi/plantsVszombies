#ifndef SHOOTERPLANT_H
#define SHOOTERPLANT_H

#include "BuyingThings.h"
#include "ground.h"

#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include"Model/bullet.h"
class ShooterPlant : public QObject,public BuyingThings
{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    QTimer* time;
    int level;
    int pixPer50miliSec;
public:
    ShooterPlant(QGraphicsScene * scene);
    ~ShooterPlant();
public slots:
    void shooting();
    void shooting1();
};

#endif // SHOOTERPLANT_H
