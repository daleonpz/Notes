#include <stdio.h>
#include <time.h>

int main(){
    /*  time_t type as a signed  integer, 32-64 bit length*/
    time_t biggest = 0x7fffffff;

    printf("%s \n", ctime(&biggest) );

    printf("%s \n", asctime( gmtime(&biggest) ) );


    /* 1. Obtain the current time by calling time() */
    time_t current ;
    current = time(NULL);
    /* 2. Call difftime() to obtain the number of seconds between now and the highest
value of time_t . */

    double diff;
    diff = difftime( biggest, current );

    double years, months, week, day, hour, min;
    min     = diff/60.0;
    hour    = min/60.0;
    day     = hour/24.0;
    week    = day/7.0;
    months  = day/30.0;
    years   = months/12.0;

    printf("difftime = %f y %f m %f w %f d %f h %f min \n",
            years, months, week, day, hour, min);

}
