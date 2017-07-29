#include <stdio.h>
#include <string.h>

typedef unsigned char* byte_pointer;

void show_bytes( byte_pointer start, int len){
	int i;
	for (i=0; i<len; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

void show_int( int x){
	show_bytes( (byte_pointer) &x, sizeof(int) );
}

void show_float( float x){
	show_bytes( (byte_pointer) &x, sizeof(float) );
}

void show_pointer( void *x){
	show_bytes( (byte_pointer) &x, sizeof(void *) );
}

float sum_elements( float a[], unsigned length){
	int i;
	float result = 0;

	for( i=0; i<= length-1; i++)
		result += a[i];
	return result;
}

float sum_elements_fix( float a[], unsigned length){
	int i;
	float result = 0;

	for( i=0; i<= (int)length-1; i++)
		result += a[i];
	return result;
}
int main(){

	printf("Figure 2.3:\n");
	// hex rep 12345 = 0x00003039
	// floating rep  = 0x4640E400
	int x = 12345;
	show_int(x);
	show_float( (float) x  );
	show_pointer(&x);

	/*
	 * int and float have same len
	 * but pointer has word length
	 * 
	 * also, 
	 *  my memory uses LE(little endian) 
	 *  pointer -> other encoding
	 * */
	
	printf("\n Problem 2.4:\n"); 
	// text doesn't depend on the platform like in the case of numbers
        // it should print 41 42 43 44 45 46 00 
	// but when using strlen it won't consider the null character
	char* s = "ABCDEF";
	show_bytes( s, sizeof(s) );
	show_bytes( s, strlen(s) );
	
	printf("\n Practice Problem 2.16:\n");
	float a[4] = {1, 2, 3, 4}; 
	for( int i=4; i>=0;i--){
		printf("length: %d \t result: %d \n ", i, sum_elements_fix(a , i) );
		// The segmentation fault is due to when length = 0
		//  length-1 = -1 if it were signed
		//  but length it is unsigned. Thus, length-1 = MaxIntVal
		//  i = 0 ; i <= length-1  is similar to 0 < MaxIntVal
		//  so a[MaxIntVal] it larger than array size of a
//		printf("length: %d \t result: %d \n ", i, sum_elements(a , i) ); // Uncomment this line to test
	}
}


