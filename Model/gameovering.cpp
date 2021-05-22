#include "gameovering.h"
#include <QFont>



GameOvering::GameOvering():QGraphicsTextItem()
{
    setPlainText("Game Over");
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",18));
    setPos(250,250);
}
