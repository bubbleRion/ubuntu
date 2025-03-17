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

// 점수 변환 함수
const char *scoreCheck(int score, int isStrike, int isSpare) {
    if (isStrike) return "X";   // 스트라이크
    if (isSpare) return "/";    // 스페어
    if (score == 0) return "-"; // 0점(미스)
    
    static char buffer[3];  // 변환된 점수 저장
    snprintf(buffer, sizeof(buffer), "%d", score);
    return buffer;
}

void game_start(MYSQL *conn){
    int frame = 0;
    int scores[FRAMES][3] = {0};  // 각 프레임 점수 저장
    int totalScore[FRAMES] = {0}; // 총 점수 저장
    int runningTotal = 0;         // 누적 점수

    printf("이름을 적어주세요. 기록을 저장하겠습니다.");
    char name[64];
    scanf("%s", name);
    if(name){
        
        while (frame < FRAMES) {
            printf("\n=== %d 프레임 ===\n", frame + 1);

            // 첫 번째 투구 입력
            printf("첫 번째 투구 점수를 입력하세요: ");
            scanf("%d", &scores[frame][0]);
            while (getchar() != '\n');  // 입력 버퍼 비우기

            if (scores[frame][0] == 10 && frame < 9) {  // 10프레임 제외 스트라이크
                printf("스트라이크!\n");
                scores[frame][1] = 0;  // 두 번째 투구 없음 (초기값 변경)
            } else {
                // 두 번째 투구 입력
                printf("두 번째 투구 점수를 입력하세요: ");
                scanf("%d", &scores[frame][1]);
                while (getchar() != '\n');  // 입력 버퍼 비우기

                if (scores[frame][0] + scores[frame][1] == 10) {
                    printf("스페어!\n");
                }
            }

            // 10프레임 처리 (추가 투구 가능)
            if (frame == 9 && (scores[frame][0] == 10 || scores[frame][0] + scores[frame][1] == 10)) {
                printf("세 번째 투구 점수를 입력하세요: ");
                scanf("%d", &scores[frame][2]);
                while (getchar() != '\n');  // 입력 버퍼 비우기
            }

            // 점수 계산 (보너스 점수 포함)
            for (int i = 0; i <= frame; i++) {
                totalScore[i] = scores[i][0] + scores[i][1] + scores[i][2];  // 기본 점수

                // 스트라이크 보너스
                if (i < 9 && scores[i][0] == 10) {
                    if (scores[i+1][0] != 0) {  // 다음 프레임 첫 번째 투구가 입력되었을 경우만 보너스 계산
                        totalScore[i] += scores[i+1][0];
                        if (scores[i+1][1] != 0) {  // 두 번째 투구도 입력되었을 경우 추가
                            totalScore[i] += scores[i+1][1];
                        } else if (i+2 < FRAMES) {  // 다음 프레임이 스트라이크라면 i+2 프레임의 첫 번째 투구 참조
                            totalScore[i] += scores[i+2][0];
                        }
                    }
                }

                // 스페어 보너스
                else if (i < 9 && scores[i][0] + scores[i][1] == 10) {
                    if (scores[i+1][0] != 0) {  // 다음 프레임 첫 번째 투구가 입력된 경우만 보너스 점수 계산
                        totalScore[i] += scores[i+1][0];
                    }
                }
            }

            // 점수 출력 부분
            printf("|");
            for (int i = 0; i < FRAMES; i++) {
                printf("  %s |", scoreCheck(scores[i][0], scores[i][0] == 10, 0));
            }
            printf("\n|");

            for (int i = 0; i < FRAMES; i++) {
                // 10프레임에서는 두 번째 투구도 스트라이크가 될 수 있음
                if (i == 9) printf("  %s |", scoreCheck(scores[i][1], scores[i][1] == 10, scores[i][0] + scores[i][1] == 10));
                else if (scores[i][1] == 0) printf("    |");  // 스트라이크로 인해 빈 공간
                else printf("  %s |", scoreCheck(scores[i][1], 0, scores[i][0] + scores[i][1] == 10));
            }
            printf("\n|");

            for (int i = 0; i < FRAMES; i++) {
                // 10프레임의 세 번째 투구 처리 (스페어나 스트라이크 반영)
                if (i == 9) printf("  %s |", scoreCheck(scores[i][2], scores[i][2] == 10, scores[i][1] + scores[i][2] == 10));
                else printf("    |");
            }
            printf("\n+----+----+----+----+----+----+----+----+----+----+\n");

            // 누적 점수 계산
            runningTotal = 0;
            printf("|");
            for (int i = 0; i < FRAMES; i++) {
                runningTotal += totalScore[i];
                printf(" %3d |", runningTotal);
            }
            printf("\n+----+----+----+----+----+----+----+----+----+----+\n");
            

            frame++;
        }
        char query[512];
        sprintf(query, "INSERT INTO bowlingScore (name, score , date) VALUES ('%s', %d , now())", name, runningTotal);
        
        if (mysql_query(conn, query)) {
            fprintf(stderr, "INSERT 쿼리 실행 실패: %s\n", mysql_error(conn));
        } else {
            printf("점수가 데이터베이스에 저장되었습니다.\n");
        }
    }
    else{
        printf("이름이 있어야 게임할수 있습니다.");
    }
    
}

void select_check(MYSQL * conn){
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    strcpy(query, "select * from bowlingScore");

    // 쿼리 요청
    if (mysql_query(conn, query))
    {
        printf("쿼리 실패");
        return;
    }
    res = mysql_store_result(conn);
    if (!res)
    {
        printf("가져오기 실패!\n");
        return;
    }
    Ball *pBall;
    pBall = (Ball *)malloc(sizeof(Ball));
    int i = 0;
    // 데이터 베이스의 정보를 구조체에 저장 - ORM
    while (row = mysql_fetch_row(res))
    {
        (pBall + i)->id = atoi(row[0]);
        strcpy((pBall + i)->name, row[1]);
        (pBall + i)->score = atoi(row[2]);
        strcpy((pBall + i)->date, row[3]);
        ++i;
        pBall = realloc(pBall, sizeof(Ball) * (i + 1));
    };
    for (int j = 0; j < i; ++j)
    {
        printf("%d \t%s \t%d \t%s \n",
               (pBall + j)->id, (pBall + j)->name,
               (pBall + j)->score, (pBall + j)->date);
    }
    free(pBall);
    // TODO: 여기 엔터만 쳐도 넘어가게 변경
    
}

void total_check(MYSQL * conn){
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    strcpy(query, "select name , COUNT(name) from bowlingScore group by name;");

    // 쿼리 요청
    if (mysql_query(conn, query))
    {
        printf("쿼리 실패");
        return;
    }
    res = mysql_store_result(conn);
    if (!res)
    {
        printf("가져오기 실패!\n");
        return;
    }
    Total *pTotal;
    pTotal = (Total *)malloc(sizeof(Total));
    int i = 0;
    // 데이터 베이스의 정보를 구조체에 저장 - ORM
    while (row = mysql_fetch_row(res))
    {
        strcpy((pTotal + i)->name, row[0]);
        (pTotal + i)->total = atoi(row[1]);
        ++i;
        pTotal = realloc(pTotal, sizeof(Ball) * (i + 1));
    };
    for (int j = 0; j < i; ++j)
    {
        printf("%s \t%d \n",
               (pTotal + j)->name,
               (pTotal + j)->total);
    }
    free(pTotal);
    // TODO: 여기 엔터만 쳐도 넘어가게 변경
    
}

void easter_eggs(){
    printf(".................\n");
    printf(".................\n");
    printf(".................\n");
    printf("제작자 : 박재형\n");
    printf(".................\n");
    printf("개발자 : 지피티\n");
    printf(".................\n");
    printf(".................\n");
    printf(".................\n");
    
}

void print_menu(void)
{
    // system("clear");
    printf("=== Game Menu ===\n");
    printf("1. 게임 시작\n");
    printf("2. 기록 조회\n");
    printf("3. 횟수 조회\n");
    printf("4. 게임 종료\n");
}

void quit(MYSQL * conn){
    exit(0);
}