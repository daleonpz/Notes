#include <stdio.h>

int main (){
    typedef struct foo {
        int foo;
        char a,b;
    } foo;
    
    printf("sizeof(foo) = %u \n",(unsigned int)sizeof(foo));
}
