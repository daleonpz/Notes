 
#include <curses.h>  
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>

int kbhit(){ 
     int i;  
     ioctl(0, FIONREAD, &i);  
     return i; /* return a count of chars available to read */  
}  

int main(){ 
     int c=' ', i=0;  
 
     initscr(); /* initialize curses functions */  
     cbreak();  
     noecho(); /* do not echo pressed character */  
 
     mvprintw(0, 0, "Press 'q' to quit\n");  
     refresh();  
 
     while (c!='q')  
     if (kbhit()) { 
        c = getch(); /* won't block, as we know a character is waiting */  
        mvprintw(1, 1, "got char '%c' on iteration %d \n",c, ++i);  
        refresh();  
     }  
 
     nocbreak();  

     echo();
     endwin(); /* finish curses */
}

