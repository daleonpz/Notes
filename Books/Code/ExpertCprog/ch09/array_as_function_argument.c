#include <stdio.h>

void funct( char c[5]){
    printf("%s\n", c);

    // array are passed by reference 
    c[4] = 'X';
}


int main (){

    char c[] = "aoeudtnshsnt";

    funct(c);

    /**
     this code works since array c is treated as pointer when passing to 
     funct
     */

    printf("%s\n",c);
}
