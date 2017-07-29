#include <stdio.h>


char * favorite_fruit () {
    static char deciduous [] = "apple";
    return deciduous;
}


int main(){
    char * a;

    a =    favorite_fruit();

    printf("%s\n",a);
}

/*
 without the keyword static the pointer becomes a dangling pointer,
 but static makes it be allocated at data segment, it can be used after 
 return from the function

 before static
 $  size a.out 
   text	   data	    bss	    dec	    hex	filename
   1231	    552	      8	   1791	    6ff	a.out

 after static
 $  size a.out
   text	   data	    bss	    dec	    hex	filename
   1215	    558	      2	   1775	    6ef	a.out
 */
