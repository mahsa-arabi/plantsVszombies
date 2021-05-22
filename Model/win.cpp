#include "win.h"

#include <QFont>

Win::Win()
{
    setPlainText("next level...");
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",18));
    setPos(250,250);
}
