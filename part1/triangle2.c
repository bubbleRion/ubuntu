#include <stdio.h>

int main(void){
    const double length;
    double height;
    double area;
    printf("Enter triangle's length\n");
    scanf("%lf" , &length);
    printf("Enter triangle's height\n");
    scanf("%lf" , &height);
    area = length * height / 2.0;
    printf("Enter triangle's area is %.2lf\n" , area);
    return 1;
}
