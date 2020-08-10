#include "score.h"

Score::Score()
{
    score=0;
}

void Score::increseScore()
{
    score+=25;
}

int Score::getScore()
{
    return score;
}
