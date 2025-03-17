#include "bowling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FRAMES 10

int main(void) {
    MYSQL *conn;
    char *host = "localhost";
    char *user = "myuser";
    char *pass = "0000";
    char *db = "bowling";
    int port = 3306;

    int frame = 0;
    int scores[FRAMES][3] = {0};  // 각 프레임 점수 저장
    int totalScore[FRAMES] = {0}; // 총 점수 저장
    int runningTotal = 0;         // 누적 점수

    // MySQL 연결
    conn = mysql_init(NULL);
    if (!conn) {
        printf("MySQL 초기화 실패\n");
        return 1;
    }

    if (!mysql_real_connect(conn, host, user, pass, db, port, NULL, 0)) {
        printf("MySQL 연결 실패: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }
    printf("MySQL 연결 성공\n");

    while (frame < FRAMES) {
        printf("\n=== %d 프레임 ===\n", frame + 1);

        // 첫 번째 투구
        char input[10];
        printf("첫 번째 투구 점수를 입력하세요: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &scores[frame][0]);
        if (scores[frame][0] == 10 && frame < 9) {  // 10프레임 제외 스트라이크
            printf("스트라이크!\n");
            scores[frame][1] = -1;  // 두 번째 투구 없음
        } else {
            // 두 번째 투구
            printf("두 번째 투구 점수를 입력하세요: ");
            scanf("%d", &scores[frame][1]);

            if (scores[frame][0] + scores[frame][1] == 10) {
                printf("스페어!\n");
            }
        }

        // 10프레임 처리 (추가 투구 가능)
        if (frame == 9 && (scores[frame][0] == 10 || scores[frame][0] + scores[frame][1] == 10)) {
            printf("세 번째 투구 점수를 입력하세요: ");
            scanf("%d", &scores[frame][2]);
        }

        // 점수 계산 (보너스 점수 포함)
        for (int i = 0; i <= frame; i++) {
            totalScore[i] = scores[i][0] + scores[i][1] + scores[i][2];  // 기본 점수
            
            // 스트라이크 보너스
            if (i < 9 && scores[i][0] == 10) {
                if (scores[i+1][0] != -1) {  // 다음 프레임 첫 번째 투구가 입력되었을 경우만 보너스 계산
                    totalScore[i] += scores[i+1][0];
                    if (scores[i+1][1] != -1) {  // 두 번째 투구도 입력되었을 경우 추가
                        totalScore[i] += scores[i+1][1];
                    } else if (i+2 < FRAMES) {  // 다음 프레임이 스트라이크라면 i+2 프레임의 첫 번째 투구 참조
                        totalScore[i] += scores[i+2][0];
                    }
                }
            }
        
            // 스페어 보너스
            else if (i < 9 && scores[i][0] + scores[i][1] == 10) {
                if (scores[i+1][0] != -1) {  // 다음 프레임 첫 번째 투구가 입력된 경우만 보너스 점수 계산
                    totalScore[i] += scores[i+1][0];
                }
            }
        }
        
        

        printf("|");
        for (int i = 0; i < FRAMES; i++) {
            if (scores[i][0] == 10) printf("  X |");  // 스트라이크
            else if (scores[i][0] == 0) printf("  - |"); 
            else printf(" %2d |", scores[i][0]);
        }
        printf("\n|");

        for (int i = 0; i < FRAMES; i++) {
            if (scores[i][1] == -1) printf("    |");  // 스트라이크로 인해 빈 공간
            else if (scores[i][0] + scores[i][1] == 10 && scores[i][1] != 0) printf("  / |");  // 스페어
            else if (scores[i][1] == -1) printf("  X |");
            else printf(" %2d |", scores[i][1]);
        }
        printf("\n|");

        for (int i = 0; i < FRAMES; i++) {
            if (i == 9) printf(" %2d |", scores[i][2]);  // 10프레임에서 세 번째 투구 출력
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

    mysql_close(conn);
    return 0;
}
