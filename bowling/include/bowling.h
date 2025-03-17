#pragma once

#include <mysql.h>
#include <stdio.h>
#include <string.h>

#define FRAMES 10

typedef struct
{
    int id;
    char name[40];
    int score;
    char date[64];
} Ball;

typedef struct
{
    char name[40];
    int total;

} Total;

enum menu
{
    EGGS,
    GAME,
    CHECK,
    TOTAL,
    QUIT
};

int * score(int one , int two);
const char* scoreCheck(int score , int isStrike , int isSpare);
void game_start(MYSQL *conn);
void select_check(MYSQL * conn);
void total_check(MYSQL * conn);
void print_menu(void);
void easter_eggs();
void quit(MYSQL * conn);