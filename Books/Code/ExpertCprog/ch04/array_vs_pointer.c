#include <stdio.h>

int main(){
    char a[] = "abcd";
    char b;
    int i;
    b = a[2];
    b = a[i];
    printf("b = %d\n",b);

    char *p;
    p = a;

    b = *(p+2);
    b = *(p+i);
    printf("b = %d\n",b);

    printf("p size = %u, a size = %u \n", sizeof(p), sizeof(a));
}

