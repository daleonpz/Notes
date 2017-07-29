#include <stdio.h>

int array[] = { 23, 34, 12, 17, 204, 99, 16 };

#define TOTAL_ELEMENTS (sizeof(array)/sizeof(array[0]))

main() {
    if ( -1 < (unsigned char) 1 )
        puts("-1 is less than (unsigned char) 1: ANSI semantics ");
    else
        puts("-1 NOT less than (unsigned char) 1: K&R semantics ");
    
    /* d = 0xFFFF  */
    int d = -1, x;

    /* ig d <= 5 
     TOTAL_ELEMENTS is unsigned int, return type of sizeof
    0x0000000000400558 <+18>:	movl   $0xffffffff,-0x8(%rbp)
    0x000000000040055f <+25>:	mov    -0x8(%rbp),%eax
    0x0000000000400562 <+28>:	cmp    $0x5,%eax
    ja
    it won't jump since  0x5 is not greater than 0xffff
    both should be signed int
     */
    if (d <= TOTAL_ELEMENTS-2)
        x = array[d+1];
    /* ... */

    printf("x = %d\n",x);
}

