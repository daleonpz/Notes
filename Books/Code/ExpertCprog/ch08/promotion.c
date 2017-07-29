#include <stdio.h>

int main (){
    printf("%d", sizeof'A');

    /*
     
       char 'A'  is promoted to int, that's why
       sizeof'A' is 4
     
     */
}
