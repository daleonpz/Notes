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

/* classify_string
look at the current token and
return a value of "type" "qualifier" or "identifier"
in this.typei */
enum type_tag classify_string(void){
    char *s = this.string;
    
    if (!strcmp(s,"const")) {
        strcpy(s,"read-only");
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

/* 
   read_to_first_identifier
gettoken and push it onto the stack until the first
identifier is read.
Print "identifier is", this.string
gettoken
*/

void read_to_first_identifier(void){
    
    gettoken();
    while(  this.type != IDENTIFIER ) {
        push(this);
        gettoken();
    }

    printf("identifier is %s ", this.string);
    gettoken();
}

/********************************/
/*   parsing routines    */
/********************************/

/*
   deal_with_function_args
read past closing ')' print out "function returning"
*/
void deal_with_function_args(void){
    // this.type + gettoken works
    // as (c == getchar() ) != ')'
    while( this.type != ')' ) 
        gettoken();

    gettoken(); // needed to refresh `this `
    printf("function returning ");
}

/*
   deal_with_arrays
while you've got "[size]" print it out and read past
it
 */
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
}

/*
   deal_with_any_pointers
while you've got "*" on the stack print "pointer to"
and pop it
   */

void deal_with_any_pointers(void){
    while ( stack[top].type == '*' ){
        // #define pop stack[top--] 
        printf("%s ",pop.string);
    }
}

/*
   deal_with_declarator
if this.type is '[' deal_with_arrays
if this.type is '(' deal_with_function_args
deal_with_any_pointers
while there's stuff on the stack
if it's a '('
pop it and gettoken; it should be the closing ')'
deal_with_declarator
else pop it and print it
   */

void deal_with_declarator(void){
    if (this.type == '[')
        deal_with_arrays();
    else if (this.type == '(')
        deal_with_function_args();

    deal_with_any_pointers();

    while (top != -1) {
        if (stack[top].type == '('){
            top--;
            gettoken();
            deal_with_declarator();
        }
        else
            printf("%s",pop.string);
    }
}

/********************************/
/*   main routine    */
/********************************/

/*
   main
read_to_first_identifier
deal_with_declarator
   */

int main(){
    read_to_first_identifier();
    deal_with_declarator();

    printf("\n");
    return 0;
}
