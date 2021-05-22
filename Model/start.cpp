#include "start.h"

#include <View/view.h>

Start::Start()
{
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,800,750);
    setFixedSize(800,750);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    auto photo=new QGraphicsPixmapItem();
     photo->setPixmap(QPixmap(":/images/start.jpg"));
     photo->setPos(0,0);
     scene->addItem(photo);
}

void Start::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    auto myView=new View();
    myView->show();
}
