#include <stdio.h>
void hello();

int main(){
    hello();
    int hellomyfriend = 39;
    float hello = 1.4;
    char world = 'A';
    char* friend = "hello , world!";
    char my;
    printf("%f\n" , hello);
    scanf("%c" , &my);
    printf("%c\n" , world);
    printf("%s\n" , friend);
    return 1;
}

void hello(){
    printf("hello , my friend\n");
    
}