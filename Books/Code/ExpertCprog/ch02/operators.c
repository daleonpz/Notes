#include <stdio.h>

int main(){

    float p[] = {10.0, 5.0};
            
    int n = sizeof*p;
    
    puts("float p[] = {x, y}");
       
    printf("sizeof*p = %d\n",n); 

    n = sizeof(p);
    printf("sizeof(p) = %d\n",n); 

    n = sizeof(int)*n;
    printf("sizeof (int)*n = %d\n",n);
    
    n = sizeof((short)*p);
    printf("sizeof((short)*p) = %d\n",n);

    int a, b=2, c=3;

    a=b=c;

    printf("a=%d\tb=%d\tc=%d\n",a,b,c);

}
