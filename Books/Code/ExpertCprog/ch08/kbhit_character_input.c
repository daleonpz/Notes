#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>

int kbhit(){ 
     int i;  
     ioctl(0, FIONREAD, &i);  
     return i; /* return a count of chars available to read */  
}  


main() { 
     int i = 0;  
     int c = 'a';  
 
     system("stty raw -echo");  
     printf("enter 'q' to quit \n");  
     for (;c!='q';i++) { 
        if (kbhit()) { 
            c=getchar();  
           printf("\n got %c, on iteration %d", c,i);
        }
     }
     system("stty cooked echo");
}


/*  This code uses an ioctl to only do a read if there is a character waiting to be read

 */
