#include <stdio.h>
#include <setjmp.h>
#include <string.h>

jmp_buf buf;

void favorite_fruit (char * fruit) {
    
    if (fruit == NULL) 
        longjmp(buf,2);

    if (strcmp("apple",fruit) == 0)
        longjmp (buf,1);
    printf("nice choice\n");
}


int main(int argc, char ** argv){

    printf("your fruit choice: %s\n", argv[1]);

    switch ( setjmp(buf)){
    case 1: 
        printf("bad choice\n");
        return 1;
    case 2:
        printf("NO INPUT\n");
        return 2;
    default:
        favorite_fruit(argv[1]);
    }

}

