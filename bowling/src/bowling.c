#include "bowling.h"

int* score(int oneFrameScore , int twoFrameScore){
    int score[3] = {0};
    if (oneFrameScore == 10){
        score[0] = 10;
        score[1] = 1;
        score[2] = 0;
    }
    else if(oneFrameScore + twoFrameScore == 10)
    {
        score[0] = 10;
        score[1] = 0;
        score[2] = 1;
    }
    else{
        score[0] = oneFrameScore + twoFrameScore;
        score[1] = 0;
        score[2] = 0;
    }

    return score;
}

char scoreCheck(score , isStrike , isSpare){
    char scoreLiteral[10];
    if(isStrike){
        return "X";
    }
    else if(isSpare){
        return "/";
    }
    else{
        sprintf(scoreLiteral , "%s" , score);
        return scoreLiteral;
    }
}