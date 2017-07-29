#include <stdio.h>

char main;

void p2(){
	printf("0x%x\n",&p2);
	printf("0x%x\n",p2);
	printf("0x%x\n",*(&main+1));
	/* when printing main it prints the opcode of the first instruction
	 * push %rbp -> 0x55 ,note that main is called from _start 
	 * maybe that's why main contains the first opcode instead of the address
	 * but in case of p2, it print the address of the first 
	 * assembler instruction
	 * */
	printf("0x%x\n",main);
}
