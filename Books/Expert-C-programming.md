---
layout: post
title: Expert C notes
---

# Ch1:

# Ch2:

## sins of commission

things that the language does, that it shouldn't do

* By the way, since the keyword const doesn't really mean constant in C,


```
const int two=2;

switch (i) {
    /*case const-expr: statements*/
    case 1: printf("case 1 \n");
    case two: printf("case 2 \n");
    **error** ^^^ integral constant expression expected
    case 3: printf("case 3 \n");
    default: ; }
```

* Do not forget to `break` if you don't want to _fall throught_ other `case`.

* "interpositioning—I should learn more about that.Interpositioning is the practice of supplanting a library function by a user-written function of the same
name
With the benefit of practical experience, default global visibility has been conclusively and repeatedly
demonstrated to be a mistake. Software objects should have the most limited scope by default.
Programmers should explicitly take action when they intend to give something global scope.

## sins of mission
covers things in C that just seem misdirected, or a bad fit to the
language
* Overloading issues
sizeof is an operator, not a function
```c
#include <stdio.h>

int main(){
    float p[] = {10.0, 5.0};
            
    int n = sizeof*p;
    
    puts("float p[] = {x, y}");
       
    printf("sizeof*p = %d\n",n); 

    n = sizeof(p);
    printf("sizeof(p) = %d\n",n); 
    
    n = sizeof(int)*n;
    printf("sizeof (int)*n = %d\n",n);
    
    n = sizeof((short)*p);
    printf("sizeof((short)*p) = %d\n",n);
}
```

```c
float p[] = {x, y}
sizeof*p = 4
sizeof(p) = 8
sizeof (int)*n = 32
sizeof((short)*p) = 2
```

buffer overflow 


## sins of ommission
covers things that the language doesn't do that it should.

### spaces

error
```
z = y+++++x;

 lvalue required as increment operand
i+++++j
   ^~

```

that `/*y` is considered as comment opener.
```
ratio = *x/*y;
```

To last post: avoid when possible this kind of things

```
int *foo(){
    int *x;

    x = (int*) malloc(10);
    
    return x;
}
```
# Chapter 3
## Declarations

The Precedence Rule for Understanding C Declarations
* Declarations are read by starting with the name and then reading in precedence order.
* The precedence, from high to low, is:
** Parentheses grouping together parts of a declaration
** the postfix operators: parentheses () indicating a function, and square brackets [] indicating an array.
** the prefix operator: the asterisk denoting "pointer to".
* C If a const and/or volatile keyword is next to a type specifier (e.g. int, long , etc.) it applies to the type specifier. Otherwise the const and/or volatile keyword applies to the pointer asterisk on its immediate left.

From "Expert C Programming: Deep C secrets" by Peter van der Linden

```c
/* pointer to const int */
const int * grape;
int const * grape;

/* const pointer to int */
int * const grape_jelly;

/* array of pointers to int*/
int *p[3]

/* pointer to a int array */
int (*p)[3]

/* pointer to a function */
int (*p)()

/* fut in a function that returns
a pointer to function that returns an int */
int (* fun())()

/*  next is a pointer to function
that returns a pointer to const pointer to char  */
char* const *(*next)();

/* x is a array of pointers to a function
that returns a pointer to char array  */
char (*(*x[3])())[5]

/* c is an array of pointers to function
that recieve  a pointer to a pointer to int
and returns a pointer to char*/
char *(*c[10])(int **p);

```

## typedef

Since a typedef looks exactly like a variable declaration, it is read exactly like one

```c
typedef void (*ptr_to_func) (int);
/* this says that ptr_to_func is a pointer to a function
* that takes an int argument, and returns void
*/
```

### typedef vs macros
`typedef` cannot be extended with a specifier

```c
#define peach int
unsigned peach i; /* works fine */
typedef int banana;
unsigned banana i; /* Bzzzt! illegal */
```

Second, a typedef 'd name provides the type for every declarator in a declaration.

```c
#define int_ptr int *
int_ptr chalk, cheese;
```

After macro expansion, the second line effectively becomes:
`int * chalk, cheese;`
This makes chalk and cheese as different as chutney and chives: chalk is a pointer-to-an-integer, while
cheese is an integer. In contrast, a typedef like this:

```c
typedef char * char_ptr;
char_ptr Bentley, Rolls_Royce;
```

declares both `Bentley` and `Rolls_Royce` to be the same. The name on the front is different, but they are
both a pointer to a char.


## struct


```c
#include <stdio.h>

int main (){
    typedef struct foo {
        int foo;
        char a,b;
    
    } foo;

    printf("sizeof(foo) = %u \n",sizeof(foo));
}

/* output */

sizeof(foo) = 8 

```

so it use foo as the struct

be careful:

```c
typedef struct fruit {int weight, price_per_lb } fruit; /*
statement 1 */
struct veg
{int weight, price_per_lb } veg;
/*
statement 2 */
```

very different things are happening. Statement 1 declares a structure tag "fruit" and a
structure typedef "fruit"


```c
struct fruit mandarin; /* uses structure tag "fruit" */
fruit tangerine; /* uses structure type "fruit" */
```

Statement 2 declares a structure tag "veg" and a variable veg. Only the structure tag can be used in
further declarations,

```c
struct veg potato;
```

# Ch4:
## Array and Pointers are not the same

```c
char a[5] = "abcd";

c = a[2];

/*
in symtab: a is on 0x4000 
a = | a | b | c | d | '\0' |

in order to do: a[2] 
1. 0x4000 + 2 , directly!!
2. get value from 0x4002 

0x0000000000400509 main+19 movzbl -0x1e(%rbp),%eax
0x000000000040050d main+23 mov    %al,-0x1(%rbp)
*/

char *p = a;

c = *(p+2);

/*
0x000000000040052d main+55 mov    -0x10(%rbp),%rax
0x0000000000400531 main+59 movzbl 0x2(%rax),%eax
0x0000000000400535 main+63 mov    %al,-0x1(%rbp)

1. get address of p
2. p+2
3. get value from that address
*/

```

In general term, retrieving values using pointers implies more instructions

## in memory

The array definition of `mango` allocates space for 100 integers.

```c
// file 1:
int mango[100];
// file 2:
extern int mango[];
...
/* some code that references mango[i] */
```

In contrast, the pointer definition requests a place that holds a pointer.

```c
int *raisin;
```

`raisin` will be stored at the same address but it changes where to point. ** size of a pointer = wordsize **
`mango` will be filled with several values, and it will always have 100 consecutive memory locations. ** size of the array will depend on the number and type of elements **.


# Ch5

