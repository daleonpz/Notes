#include <stdio.h>

int x[1000] = {5};

int main(){
    printf("hello world\n");
    printf("%i\n", x[5]);

    /*
    only the printf
     $ ls -l a.out 
       -rwxr-xr-x 1 dnl dnl 8368 19.05.2017 15:14 a.out*
     $  size a.out 
       text	   data	    bss	    dec	    hex	filename
       1155	    552	      8	   1715	    6b3	a.out
     */
    
    /*
     After adding int x[1000] as global
    $  ls -l a.out 
       -rwxr-xr-x 1 dnl dnl 10904 19.05.2017 15:17 a.out*

    $  size a.out
       text	   data	    bss	    dec	    hex	filename
       1155	    552	   4032	   5739	   166b	a.out

        text is the same size
        data is the same size
        bss has increase since we add a  uninitialized global variable
      */

}
