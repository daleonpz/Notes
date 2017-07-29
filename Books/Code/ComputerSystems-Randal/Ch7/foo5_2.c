#include <stdio.h>

void f(void);

int x = 15213;
int y = 15212;

int main(){
	printf("x = 0x%x \t px=%p \ny = 0x%x \t py=%p \n", 
                x, (void *)&x, y, (void *)&y);
	f();
	/*
	 * the value of x=-0.0 will overwrite the value of 
	 * x and y since in bar5.c x is declared as double
	 * in foo5_2.c
	 *  | X X X X | 4 bytes
	 *  | Y Y Y Y | 4 bytes
	 *
	 * but in bar5.c
	 *  | X X X X X X X X | 8 bytes
	 *  since X is negative and 0
	 *  | 8 0 0 0 0 0 0 0 |
	 *  | Y Y Y Y X X X X |
	 * */
	printf("x = 0x%x \t px=%p \ny = 0x%x \t py=%p \n", 
                x, (void *)&x, y, (void *)&y);
	return 0;
}
