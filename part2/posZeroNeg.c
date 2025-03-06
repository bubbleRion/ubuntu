//숫자를 입력 받아서 양수 , 제로 , 음수를 출력하는 프로그램
//if else 구문으로 만드세요.
// printf는 한 번만 쓰세요.
#include <stdio.h>
#include <stdlib.h>

int main(int argc , char* argv[]){
    int num = atoi(argv[1]);
    // char* whatIsNum = "제로";
    // if(num > 0){
    //     whatIsNum = "양수";
    // }
    // else if(num < 0){
    //     whatIsNum = "음수";
    // }
    // printf("입력한 숫자는 %s 입니다.\n" , whatIsNum);
    printf("입력한 숫자는 %s 입니다.\n" , num > 0 ? "양수" : num < 0 ? "음수" : "제로");
}