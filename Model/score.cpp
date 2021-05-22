#include "score.h"
#include <QFont>
Score::Score()
{
    score=0;
    scoreMusic=new QMediaPlayer();
    scoreMusic->setMedia(QUrl("qrc:/sounds/score.mp3"));
    setPlainText(QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",7));
    setPos(4,53);
}

Score::~Score()
{
    delete scoreMusic;
}

void Score::increseScore()
{
    scoreMusic->play();
    score+=25;
    setPlainText(QString::number(getScore()));
}
void Score::decreseScore(int s)
{
    score-=s;
    setPlainText(QString::number(getScore()));
}

int Score::getScore()
{
    return score;
}
