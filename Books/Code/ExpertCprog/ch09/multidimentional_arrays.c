#include <stdio.h>

int main(){

    int apricot[2][3][5];

    int (*r)[5] = apricot[0];
    int *t = apricot[0][0];


    printf("r = %x\tt = %x\n",r,t);
    
    r++;
    t++;
    
    printf("r = %x\tt = %x\n",r,t);

    /*
    r is a pointer to array[5] of int
    sizeof(r) = 5*4 
    r++ > apricot[0]+20 > apricot[5] 

    t++ > apricot[0][0]+4 > apricot[1]

       */


    int a[2][3] = {1,2,3,4,5,6};

    // array of arrays decays into pointer to array (ch10)
    int (*b)[3] = a[0];

    printf("%d \n",a[1][0]);
    printf("%d \n",(*++b)[0]);
}

