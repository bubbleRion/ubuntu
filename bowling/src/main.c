#include "bowling.h"
#include <stdio.h>

int main(void)
{
    MYSQL *conn;
    char *host = "localhost";
    char *user = "myuser";
    char *pass = "0000";
    char *db = "ballwing";
    int port = 3306;


    int frame = 1;
    int oneFrameScoreNum;
    int twoFrameScoreNum;


    // 연결
    conn = mysql_init(NULL); // DB 연결 요청 준비
    if (mysql_real_connect(conn, host, user, pass, db, port, NULL, 0))
        printf("MySQL 연결 성공\n");
    else
    {
        printf("MySQL 연결 실패\n");
        return 1;
    }
    while (frame < 10)
    {
        for(int i = 0; i < 10; ++i){
            printf("|%d " , frame);
        }
        printf("|\n");
        for(int i = 0; i < 10;  ++i){
            printf("|%c " ,  "");
        }
        // printf("1 , 2 번 고르세요!");
        scanf("%d%*c", &oneFrameScoreNum);
        if(oneFrameScoreNum == 10){
            score(10 , 0);
        }
        else{
            score(oneFrameScoreNum , twoFrameScoreNum);
        }
        

        frame++;
    }

    mysql_close(conn);

    return 0;
}