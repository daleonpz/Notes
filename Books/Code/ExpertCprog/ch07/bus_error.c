#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
//     char *p;
// 
    /* Flags in EFLAGS(32bits) / RFLAGS(64bits) registers  
     
     https://en.wikipedia.org/wiki/FLAGS_register
     http://orchistro.tistory.com/206

     the bit 18 is the one that checks Alignment 
     so if we turn it on

     0100 0000 0000 0000 0000
     4    0    0    0    0

     Push Flag Register Onto Stack (pushf)
     Pop Stack into Flag (popf)
     */
    __asm__("pushf\n"
            "orl $0x40000, (%rsp)\n"
            "popf");




//     /* 
//      * malloc() always provides aligned memory.
//      * Do not use stack variable like a[9], depending on the compiler you use,
//      * a may not be aligned properly.
//      */
//     p = malloc(sizeof(int) + 1);
//     memset(p, 0, sizeof(int) + 1);
// 
//     /* making p unaligned */
//     p++;
// 
//     printf("%d\n", *(int *)p);
// 
//     return 0;
// 
// 

    union { char a[5];
            int i;
          } u;
    int *p= (int*) &(u.a[1]);
    *p = 17; /* the misaligned addr in p causes a bus error! */


    /*
      a = |a|a|a|a|a|
      i = |  i    |

      p points to a[1]

      a = |a|a|a|a|a|
             ^
             p

      u.a[1] is not int aligned, but a[0] is.
     */

} 
