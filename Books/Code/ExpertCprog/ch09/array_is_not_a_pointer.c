
int main(){

    // an array 
    char a[] = "hola";

    // a pointer 
    char *b;

    // a pointer to read-only memory
    char *c = "hallo";

    // b can point to a or c

    b = c;
    b = a;

    // c can point to a or c
    c = a;
    c = b;

    // but a cannot point to a or c, 
    // because it is not a FUCKING POINTER!!!!!

    a = b;
   // error: assignment to expression with array type   a = b;

}
