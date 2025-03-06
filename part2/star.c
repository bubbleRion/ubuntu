#include <stdio.h>

int main(){
    char* star = "*";
    for(int i = 1; i <= 5; ++i){
        for(int j = 1; j <= i; ++j){
            printf("%s" , star) ;
        }
        printf("\n");
    }

    for(int i = 1; i <= 9; ++i){
        if(i % 2 != 0){
            for(int n = 0; n <= (9 - i) / 2; n++){
                printf(" ");
            }
            for(int j = 1; j <= i; ++j){
                printf("%s" , star) ;
            }
            printf("\n");
        }
    }

    return 1;
}