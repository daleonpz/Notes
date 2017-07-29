#include <stdlib.h>
#include <stdio.h> 

 main()  
 { 
     int c;  
 
 /* The terminal driver is in its ordinary line-at-a-time mode*/  
     system("stty raw");  
 
 /* Now the terminal driver is in character-at-a-time mode */  
     c = getchar();  
 
     system("stty cooked");  
 /* The terminal driver is back in line-at-a-time mode */  
 }
