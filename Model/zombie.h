#ifndef ZOMBIE_H
#define ZOMBIE_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Zombie : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QTimer* zombieTimer;
    int lives;
    int pixPermiliSec;
    int walkLevel;
public:
    Zombie(const int& pixPermiliSec);

signals:

public slots:
    void moveToLeft();
};


#endif // ZOMBIE_H
