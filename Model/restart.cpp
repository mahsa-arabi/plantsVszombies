#include "restart.h"
#include <iostream>

ReStart::ReStart(View * view)
{
 // controller->scene->addItem(this);
  setPixmap(QPixmap(":/images/restart.png"));
  auto g=new GameOvering();
  //view->controller->scene->addItem(this);
  view->controller->scene->addItem(g);
  setPos(300,350);
}

void ReStart::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout<<"hi1"<<std::endl;
    //view->clearScene();
    //view->l1();
}
