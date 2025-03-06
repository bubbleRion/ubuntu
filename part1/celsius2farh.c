#include <stdio.h>
int main(){
    int celsius;
    scanf("%d" , &celsius);
    //celsius = fahr * 1.8 + 32;
    double farh;
    farh = 9.0 / 5.0 * celsius + 32;
    printf("%f\n" , farh);
    return 0;
    //
}