#include <stdio.h>

int a(int i){
    if (i>0)  
       a(--i);  
    else  
       printf("i has reached zero ");  
    return;  
}

int main(){
    a(1);
}


/*

a(1)   
─── Stack
[0] from 0x000000000040052e in main+4 at fillstack.c:12

inside a(1)
─── Stack
[0] from 0x0000000000400501 in a+11 at fillstack.c:4
arg i = 1
[1] from 0x0000000000400538 in main+14 at fillstack.c:12

inside a(0), here is where printf is called
>>> info stack
#0  a (i=0) at fillstack.c:4
#1  0x0000000000400515 in a (i=0) at fillstack.c:5
#2  0x0000000000400538 in main () at fillstack.c:12

after return from a(0)
>>> info stack
#0  a (i=0) at fillstack.c:8
#1  0x0000000000400538 in main () at fillstack.c:12

after return from a(1)
>>> info stack
#0  main () at fillstack.c:13
   */
