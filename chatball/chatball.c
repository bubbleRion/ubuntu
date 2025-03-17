#include "bowling.h"


int* score(int oneFrameScore, int twoFrameScore) {
    int* score = (int*)malloc(3 * sizeof(int));  // 동적 메모리 할당
    if (!score) {
        printf("메모리 할당 실패!\n");
        exit(1);
    }

    if (oneFrameScore == 10) {  // 스트라이크
        score[0] = 10;
        score[1] = 1;
        score[2] = 0;
    } else if (oneFrameScore + twoFrameScore == 10) {  // 스페어
        score[0] = 10;
        score[1] = 0;
        score[2] = 1;
    } else {  // 일반 점수
        score[0] = oneFrameScore + twoFrameScore;
        score[1] = 0;
        score[2] = 0;
    }

    return score;
}


char* scoreCheck(int score, int isStrike, int isSpare) {
    static char scoreLiteral[10];

    if (isStrike) {
        return "X";
    } else if (isSpare) {
        return "/";
    } else {
        sprintf(scoreLiteral, "%d", score);
        return scoreLiteral;
    }
}