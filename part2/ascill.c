#include <stdio.h>

int main(void){
     int ASCII;

     for(ASCII = 0; ASCII <= 127; ASCII++){

         printf("%c", ASCII);

         if(ASCII % 8 == 0){

              printf("\n");

         }
     }

     return 0;

}
