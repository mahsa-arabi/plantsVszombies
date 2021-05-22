#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>

class Score: public QGraphicsTextItem
{
private:
    int score;
     QMediaPlayer* scoreMusic;
public:
    Score();
    ~Score();
    void increseScore();
    void decreseScore(int s);
    int getScore();
};

#endif // SCORE_H
