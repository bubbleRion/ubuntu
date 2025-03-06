#include <stdio.h>
#include <stdlib.h>

int main(int argc , char* argv[]){
    int score;
    char grade;

    if(argc < 2){
        printf("인자를 하나 넣어서 실행히세요. \n");
        return 0;
    }
    score = atoi(argv[1]);
    /*
    if(score >= 90){
        printf("score : %d === A\n" , score);
    }else if(score >= 80){
        printf("score : %d === B\n" , score);
    }
    else if(score >= 70){
        printf("score : %d === C\n" , score);
    }
    else if(score >= 60){
        printf("score : %d === D\n" , score);
    }
    else if(score >= 50){
        printf("score : %d === E\n" , score);
    }
    else{
        printf("score : %d === F\n" , score);
    }
    */
    switch (score/10)
    {
    case 10:
        grade = 'A';
        break;
    case 9:
        grade = 'A';
        break;
    case 8:
        grade = 'B';
        break;
    case 7:
        grade = 'C';
        break;
    case 6:
        grade = 'D';
        break;
    case 5:
        grade = 'E';
        break;
    default:
        grade = 'F';
        break;
    }
    printf("score : %c\n" , grade);
    return 0;
}