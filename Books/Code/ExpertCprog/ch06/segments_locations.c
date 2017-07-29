 
#include <stdio.h>  

int a[] = {4,5};

const int b[] = {5,5};

int main()  
 { 
    int i;  
    printf("The stack top is near %p\n", &i);  

    printf("Data segment is near %p\n", &a[1]);

    printf("text segment is near %p\n", &b[1]);
    return 0;  
} 


/*
 
   The stack top is near 0x7ffefede879c
Data segment is near 0x601034
text segment is near 0x4005dc

using objdump -x
.data   0000000000601020 
.rodata 00000000004005d0

from gdb
0x00007ffff7a56511 in __libc_start_main () from /usr/lib/libc.so.6

 */
