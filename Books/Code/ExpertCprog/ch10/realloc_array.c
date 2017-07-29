#include <stdlib.h>
#include <stdio.h>

int    current_element=127;  
int    total_element=128;  
 
void add_element(char c,char * dynamic) {


   if ( dynamic == NULL){ 
       dynamic = (char *) malloc(total_element);
       printf ("allocating memory\n");
   }

   if (current_element==total_element-1) { 
      total_element*=2;  
      dynamic = (char *) realloc(dynamic, total_element);  
      if (dynamic==NULL) fprintf(stderr, "Couldn't expand the table"); 
      else printf("Reallocation success\n"); 
   }  
   current_element++;  
   dynamic[current_element] = c;  
} 


int main(){

    char *dynamic;

    add_element('a', dynamic);

    free(dynamic);

}
