#include <stdio.h>

int main() {
    char *available_resources[] = {
        "color monitor",
        "big disk",
        "Cray" /*
        whoa! no comma! */
        "on-line drawing routines",
        "mouse",
        "keyboard",
        "power cables",
    };
    
    int x = sizeof(available_resources)/sizeof(available_resources[0]);;    

    int i;
    for( i=0; i<x; i++ )
        printf("%s \n", available_resources[i]);


    /*
        color monitor 
        big disk 
        Crayon-line drawing routines 
        mouse 
        keyboard 
        power cables 
     */
}
