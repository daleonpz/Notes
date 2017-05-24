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
Compilation workflow:
1. Preprocessor: cpp, generate `*.i` text file. `gcc -E file.c -o file.i`
2. Compiler: ccl, generate `*.s` text file (Syntax, semantic analysis and code generation). `gcc -S file.c`
3. Assembler: as, generate `*.o` binary file a.k.a. relocatable object program. `gcc -O file.c -o file.o`
4. Link-loader: ld, generate an executable (binary).

Generate linker map: `gcc -Xlinker -Map=output.map file.c`


The object file `*.o` **is not ** an executable, the linker identifies the main routine and binds symbolic references to memory address. In the following example it is clear the job of linker.

```c
/* Original code */
#include <stdio.h>

#define MAX 50
#define max(x,y) x>=y?x:y

int main (){

    int x = MAX;
    int y = 5;

    int m =  max(x,y);

    printf("%d\n", m);
    
    return 0;
}


/* Preprocessor example */
// it is a part of linker.i
// # 6 "linker.c"
int main (){

    int x = 50;
    int y = 5;

    int m = x>=y?x:y;

    printf("%d\n", m);

    return 0;
}


/* After Compiler example*/
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$50, -4(%rbp)
	movl	$5, -8(%rbp)
	movl	-8(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	cmovge	-4(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc

/* *.o and the executable are binaries
but we can use objdump
*/

/* Object file *.o */

Disassembly of section .text:

0000000000000000 <main>:
   0:	48 83 ec 08          	sub    $0x8,%rsp
   4:	be 32 00 00 00       	mov    $0x32,%esi
   9:	bf 00 00 00 00       	mov    $0x0,%edi
   e:	b8 00 00 00 00       	mov    $0x0,%eax
  13:	e8 00 00 00 00       	callq  18 <main+0x18>
  18:	b8 00 00 00 00       	mov    $0x0,%eax
  1d:	48 83 c4 08          	add    $0x8,%rsp
  21:	c3                   	retq  


/* Executable */
00000000004004f6 <main>:
  4004f6:	55                   	push   %rbp
  4004f7:	48 89 e5             	mov    %rsp,%rbp
  4004fa:	48 83 ec 10          	sub    $0x10,%rsp
  4004fe:	c7 45 fc 32 00 00 00 	movl   $0x32,-0x4(%rbp)
  400505:	c7 45 f8 05 00 00 00 	movl   $0x5,-0x8(%rbp)
  40050c:	8b 45 f8             	mov    -0x8(%rbp),%eax
  40050f:	39 45 fc             	cmp    %eax,-0x4(%rbp)
  400512:	0f 4d 45 fc          	cmovge -0x4(%rbp),%eax
  400516:	89 45 f4             	mov    %eax,-0xc(%rbp)
  400519:	8b 45 f4             	mov    -0xc(%rbp),%eax
  40051c:	89 c6                	mov    %eax,%esi
  40051e:	bf c4 05 40 00       	mov    $0x4005c4,%edi
  400523:	b8 00 00 00 00       	mov    $0x0,%eax
  400528:	e8 c3 fe ff ff       	callq  4003f0 <printf@plt>
  40052d:	b8 00 00 00 00       	mov    $0x0,%eax
  400532:	c9                   	leaveq 
  400533:	c3                   	retq   
  400534:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40053b:	00 00 00 
  40053e:	66 90                	xchg   %ax,%ax

```


## Dynamic vs static linking
- dynamic doesn't load all the functions of a library, only the ones that have references in the c file.
- A dynamically linked executable is smaller than its statically linked counterpart.
- All executables dynamically linked to a particular library share a single copy of the library at
runtime.
- Dynamic linking permits easy versioning of libraries. The user will have access to the inferface, `*.h` in most cases, but the code itself `*.c` will be a black box and it can be updated without needing to be relinked.
- It's possibly to link againts custom libraries, tuned for speed or memory management for example.

```c
/* dynamic linking example using printf*/
  40051e:	bf c4 05 40 00       	mov    $0x4005c4,%edi
  400523:	b8 00 00 00 00       	mov    $0x0,%eax
  400528:	e8 c3 fe ff ff       	callq  4003f0 <printf@plt>
  40052d:	b8 00 00 00 00       	mov    $0x0,%eax

/* reference to printf at address 0x400528 */
```

## Some issues may be:
- if you compile a program against library `/usr/bin/stdio.h` but in other computer `stdio.h` is in `/usr/local/bin/stdio.h` it won't run unless it will recompiled or by using a symbolic link to the compiled folder (`/usr/bin/stdio.h`)


## How to compile

```sh
% cat tomato.c
    #include <stdio.h>
    void my_lib_function() {printf("library routine called\n"); }
% gcc -c -Wall -Werror -fPIC tomato.c
% gcc -shared -fPIC -o libfruit.so tomato.c

% cat test.c
    main() { my_lib_function(); }
% cc test.c -L/home/linden -R/home/linden -lfruit
```

The `-L/home/linden` `-R/home/linden` options tell the linker in which directories to look
for libraries at linktime and at runtime, respectively. You will probably also want to use the `-fPIC` compiler option to produce position-independent code for your libraries.

A rule of thumb is to always use PIC (Position independent code) for libraries. Position-independent code is especially useful for shared libraries because each process that uses a shared library will generally map it at a different virtual address (though sharing one physical copy).

## Five Special Secrets of Linking with Libraries

1. Dynamic libraries are called `libsomething.so` , and static libraries are called `libsomething.a`
2. You tell the compiler to link with, for example, `libthread.so` by giving the option `-lthread` 
3. The compiler expects to find the libraries in certain directories. For example, `/usr/lib/` or you can set a path by using `-Lpathname`.
4. Identify your libraries by looking at the header files you have used. For example `<thread.h>` has a Library Pathname `/usr/lib/libthread.so` and compiler option to use is `-lthread`.
5. Symbols from static libraries are extracted in a more restricted way than symbols from dynamic libraries. When working with static libraries, the linker is fussy about where libraries are mentioned, and in what order, since symbols are resolved looking from left to right. For example, if `liba.a` depends on `libb.a` then you should compile as `gcc liba.a libb.a`. 

## Be careful with Interposing
Interpositioning (some people call it "interposing") is the practice of supplanting a library function by a user-written function of the same name. This is a technique only for people who enjoy a good walk on the wild side of the fast lane without a safety net. It enables a library function to be replaced in a particular program, usually for debugging or performance reasons. But like a gun with no safety catch, while it lets experts get faster results, it also makes it very easy for novices to hurt themselves. 

If an identifier is **reserved**, it means that the user is not allowed to redefine it. However, this is not a **constraint**, so it does not require an error message when it sees it happen.

## Genereting linking reports files 
Check this [link](https://www.codeproject.com/Articles/3472/Finding-crash-information-using-the-MAP-file)

# Ch6:

# The `auto` and `static` keywords
if you need to return a pointer to something defined in a function, then define the thing as `static`. This will ensure that space for the variable is allocated in the data segment instead of on the stack. The lifetime of the variable is thus the lifetime of the program, and as a side effect it retains its value even after the function that defines it exits. That value will still be available when the function is next entered. 


# `setjmp` and `longjmp`
use this functions **ONLY** for error recovery. They are similar to `try` and `catch` in C++.

```c
jmp_buf buf;

void favorite_fruit (char * fruit) {
    
    if (fruit == NULL) 
        longjmp(buf,2);

    if (strcmp("apple",fruit) == 0)
        longjmp (buf,1);
    printf("nice choice\n");
}


int main(int argc, char ** argv){

    printf("your fruit choice: %s\n", argv[1]);

    switch ( setjmp(buf)){
    case 1: 
        printf("bad choice\n");
        return 1;
    case 2:
        printf("NO INPUT\n");
        return 2;
    default:
        favorite_fruit(argv[1]);
    }

}
```

Output 
```sh
$  ./a.out 
your fruit choice: (null)
NO INPUT
$  ./a.out apple
your fruit choice: apple
bad choice
$  ./a.out banan
your fruit choice: banan
nice choice
```

# Ch07:

## Virtual Memory
VM is organized into pages, typically a few of Kbytes. Whenn a memory image travels between disk and physical memory (RAM) we say is being paged.

The swap area will that contains all the processes that are unlikely to run soon. So it is taken away from physical memory and backed up into the disk.

A process can only operate on pages that are in memory.

## Segmentation fautls
Common immediate causes of segmentation fault: 
- dereferencing a pointer that doesn't contain a valid value 
- dereferencing a null pointer (often because the null pointer was returned from a system routine, and used without checking) 
- accessing something without the correct permission—for example, attempting to store a value into a read-only text segment would cause this error 
- running out of stack or heap space (virtual memory is huge but not infinite) 

# Ch08:
## Promotions in 

Table of promotions in C:

- `bit-field`, `enum`, `(unsigned) char`, ` (unsigned)short` :  `int`
- `float`: `double`
- array of : pointer to
 
## Function prototypes
If you use a function prototype, the default argument promotions do not occur. If you prototype something as a `char`, a `char` actually gets passed.

Be careful, **do not mixed up**  old C and ANSI C declaration and definitions

.



