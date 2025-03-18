#include "bowling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    MYSQL *conn;
    char *host = "localhost";
    char *user = "myuser";
    char *pass = "0000";
    char *db = "bowling";
    int port = 3306;
    int choice;
    

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
    printf(".................\n");
    printf(".................\n");
    printf(".................\n");
    printf("....볼링 게임....\n");
    printf(".................\n");
    printf(".................\n");
    printf(".................\n");
    printf("\n");
    while (true)
    {
        // printf("1 , 2 번 고르세요!");
        printf("...PRESS Enter!..\n");
        getchar();
        print_menu();
        scanf("%d%*c", &choice);
        switch (choice)
        {
        case EGGS:
            easter_eggs();
            break;
        case GAME:
            game_start(conn);
            break;
        case CHECK:
            select_check(conn);
            break;
        case TOTAL:
            total_check(conn);
            break;
        case QUIT:
            quit(conn);
            break;
        default:
            printf("값을 잘못 입력하셨습니다.\n");
            continue;
        }
        
    }
    
    
    mysql_close(conn);
    return 0;
}
