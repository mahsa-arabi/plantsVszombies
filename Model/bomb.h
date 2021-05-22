#ifndef BOMB_H
#define BOMB_H
#include "buyingthings.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QMediaPlayer>


class Bomb:public QObject,public BuyingThings
{
    Q_OBJECT
private:
     QMediaPlayer* bombMusic;
    QGraphicsScene * scene;
    QTimer* time;
public slots:
    void explode();
public:
    Bomb(QGraphicsScene * scene);
    ~Bomb();
};

#endif // BOMB_H
