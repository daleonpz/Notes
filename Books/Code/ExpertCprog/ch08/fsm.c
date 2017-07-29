/********************************/
/*   includes    */
/********************************/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag { IDENTIFIER, QUALIFIER, TYPE};

struct token { 
    char type;
    char string[MAXTOKENLEN]; 
};

int top=-1;

#define pop stack[top--]
#define push(s) stack[++top]=s

/* holds tokens we read before reaching first
identifier */
struct token stack[MAXTOKENS];

/* holds the token just read */
struct token this;

/********************************/
/*   Utility routines    */
/********************************/
enum type_tag classify_string(void){
    char *s = this.string;
    
    if (!strcmp(s,"const")) {
        strcpy(s,"read-only ");
        return QUALIFIER;
    }

    if (!strcmp(s,"volatile")) return QUALIFIER;
    if (!strcmp(s,"void")) return TYPE;
    if (!strcmp(s,"char")) return TYPE;
    if (!strcmp(s,"signed")) return TYPE;
    if (!strcmp(s,"unsigned")) return TYPE;
    if (!strcmp(s,"short")) return TYPE;
    if (!strcmp(s,"int")) return TYPE;
    if (!strcmp(s,"long")) return TYPE;
    if (!strcmp(s,"float")) return TYPE;
    if (!strcmp(s,"double")) return TYPE;
    if (!strcmp(s,"struct")) return TYPE;
    if (!strcmp(s,"union")) return TYPE;
    if (!strcmp(s,"enum")) return TYPE;
    return IDENTIFIER;
}

/* gettoken 
read the next token into this.string
if it is alphanumeric, classify_string
else it must be a single character token
this.type = the token itself; terminate this.string
with a nul.
*/
void gettoken(void){
    
    char *p = this.string;

    while ((*p = getchar()) == ' ' ||  (*p == '\t') )
        ;

    if ( isalnum(*p)){
        while ( isalnum(*++p=getchar()) );
        /* ungetc since it is not alphanumeric and null character
       should be at the end  */
        ungetc(*p,stdin);
        *p = '\0';
        this.type=classify_string();
        return;
    }

    if (*p == '*'){
        this.type = '*';
        strcpy(this.string, "pointer to");
        return;
    }
    
    this.type = *p;
    this.string[0] = '\0';
    return;
}

/********************************/
/*   parsing routines    */
/********************************/
void (*nextstate)(); 

void read_identifier(void);
void deal_with_declarator(void);
void deal_with_function_args(void);
void deal_with_arrays(void);
void deal_with_any_pointers(void);
void deal_with_qualifiers(void);

/**********************
  INITIAL STATE
  **********************/
void read_identifier (void){
    
    nextstate =  deal_with_declarator;

    gettoken();
    while(  this.type != IDENTIFIER ) {
        push(this);
        gettoken();
    }

    printf("identifier is %s ", this.string);
    gettoken();
}

/***********************
  2nd STATE
   **********************/
void deal_with_declarator(void){
    if (this.type == '[')
        nextstate = deal_with_arrays;
    else if (this.type == '(')
        nextstate = deal_with_function_args;
    else 
        nextstate = deal_with_any_pointers;
}


void deal_with_arrays(void){

    while( this.type == '[' ){ 
        printf("array [");
        gettoken(); // check whether is [] or [0-9]

        if( isdigit(this.string[0]) ){
            printf("%d", atoi(&this.string[0] ) );
            gettoken();
        }
        
        gettoken();
        printf("] of ");
    }
    nextstate = deal_with_any_pointers;
}


void deal_with_function_args(void){
    while( this.type != ')' ) 
        gettoken();

    gettoken(); // needed to refresh `this `
    printf("function returning ");

    nextstate = deal_with_any_pointers;
}


/***********************
// 3rd STATE
************************/
void deal_with_any_pointers(void){
    while ( stack[top].type == '*' ){
        printf("%s ",pop.string);
    }
    nextstate = deal_with_qualifiers;
}

void deal_with_qualifiers(void){
    if( top != -1){
        if (stack[top].type == '('){
                    top--;
                // 4th state
                gettoken();
                nextstate = deal_with_declarator;
            }
        else
                // 5th state
                printf("%s",pop.string);
    }
    else
        nextstate = NULL;
}

/********************************/
/*   main routine    */
/********************************/
int main(){

    nextstate = read_identifier;
    while( nextstate != NULL)
        (*nextstate)();

    printf("\n");
    return 0;
}



/*
 
  intial state: Go to identifier

2nd:  check right for () or []

3rd:  check left for (  if true go to 2nd
   
4th:  check left for modifier such as const , volatile, *  if true go to second

5th:  check left for basic type go to 2nd
 
 */
