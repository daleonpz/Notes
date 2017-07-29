#include <stdlib.h>
#include <string.h>

#define DUMBCOPY for (i = 0; i < 65536; i++) \  
 destination[i] = source[i]  
 

#define SMARTCOPY memcpy(destination, source, 65536)

main()
{
    // 64Kb
    char source[65536], destination[65536];
    int i, j;
    for (j = 0; j < 100; j++)
        DUMBCOPY;

}

/**
  
  SMARTCOPY
  $  time ./a.out 

real	0m0.002s

  DUMBCOPY
$  time ./a.out 

real	0m0.058s
user	0m0.057s
sys	0m0.003s

  */
