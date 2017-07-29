#include <stdio.h>

#define MAX 50
#define max(x,y) x>=y?x:y

int main (){

    int x = MAX;
    int y = 5;

    int m =  max(x,y);

    printf("%d\n", m);
    
    return 0;
}
