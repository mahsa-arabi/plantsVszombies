#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H

#include "BuyingThings.h"
#include "zombie.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QMediaPlayer>


class CherryBomb: public QObject,public BuyingThings
{
    Q_OBJECT
private:
    QMediaPlayer* bombMusic;
    QGraphicsScene * scene;
    QTimer* time;
public slots:
    void explode();
public:
    CherryBomb(QGraphicsScene * scene);
    ~CherryBomb();
};

#endif // CHERRYBOMB_H
