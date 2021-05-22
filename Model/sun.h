#ifndef SUN_H
#define SUN_H

#include "score.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
class Sun: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Sun(QGraphicsScene * scene,Score* sunScore,QGraphicsItem* parent,
        QTimer* timer);
  //  ~Sun();
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
signals:
public slots:
    void moveToDown();
private:
    int timeInterval;
    QGraphicsScene * scene;
    Score* sunScore;
};

#endif // SUN_H
