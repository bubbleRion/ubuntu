#include <stdio.h>
#include <stdlib.h>


int main(int argc , char* argv[]){
    if(argc < 2){
        printf("인자를 하나 넣어서 실행히세요. \n");
        return 0;
    }
    printf("score : %s --- %s\n" , argv[1]  , atoi(argv[1]) >= 60 ? "합격" : "실패");
    return 0;
}