#include <setjmp.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

jmp_buf buf;

typedef void handler_t(int);

static void segmentation_fault(int c){
    int *p = 0;
    *p = 17;
}

static void bus_error(int c)
{
        __asm__("pushf\n"
                "orl $0x40000, (%rsp)\n"
                "popf");

        union { char a[5];
                int i;
              } u;
        int *p= (int*) &(u.a[1]);
        *p = 17;
}

static void saved(int sig, siginfo_t *dont_care, void *dont_care_either)
{
   longjmp(buf, 1);
}


static void *Signal (int signum, handler_t* handler){
    struct sigaction action, old_action;

    action.sa_handler = handler;
    sigemptyset(&action.sa_mask); // block sigs of type being handle
    action.sa_flags = SA_RESTART;
    action.sa_sigaction = saved;
    
    if(sigaction(signum, &action, NULL) < 0 ) 
        puts("signal error");
}

int main ( int argc, char ** argv){

    char a = (*argv[1]);

    switch (a){
        case 's':
            puts("SIGSEGV test");
            Signal ( SIGSEGV , segmentation_fault );
            break;
        case 'b':
            puts("SIGBUS test");
            Signal( SIGBUS, bus_error );
            break;
    }

    if( setjmp(buf) == 1) fprintf(stderr, "done\n");
    else printf("OK\n");

    return 0;

}
