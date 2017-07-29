#include <math.h>		
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

typedef enum { false, true } bool;
clock_t start, end;
double cpu_time_used;


void transpose_tmp(int *dst, int* src, int dim){
	int i,j;
	start = clock();
	int n; 
	int tmp;
	for ( i=0; i<dim; i++){
		n = i*dim;
		for( j=0; j<dim; j++)
			if (i==j) 
				tmp = src[n + j];
			else
				dst[j*dim + i] = src[n + j];
		dst[n + i] = tmp;
	}

	end = clock();

	cpu_time_used = ((double) (end - start));
	printf("%i\n", (int)cpu_time_used);	
}


void transpose_blocking(int *dst, int* src, int dim){
	int i,ii,k,kk;
	start = clock();
	
	int bsize = 4;
	int bd = bsize * dim;

	for ( ii=0; ii<dim; ii+=bsize)
		for ( kk=0; kk<dim; kk+=bsize)
			for( i=0; i<bsize; i++)
				for( k=0; k<bsize; k++)
					dst[ (kk + k)*dim + ii + i   ] =
					       	src[ (ii+i)*dim + kk + k ];

	end = clock();

	cpu_time_used = ((double) (end - start));
	printf("%i\n", (int)cpu_time_used);	
}


void transpose_unrolling(int *dst, int* src, int dim){
	int i,j;
	start = clock();

	int n = dim - 1;
	for ( i=0; i<dim; i++)
		for( j=0; j<n; j+=2){
			dst[j*dim + i] = src[i*dim + j];
			dst[(j+1)*dim + i] = src[i*dim + j+1];
		//	dst[(j+2)*dim + i] = src[i*dim + j+2];
		//	dst[(j+3)*dim + i] = src[i*dim + j+3];
		}
	end = clock();

	cpu_time_used = ((double) (end - start));
	printf("%i\n", (int)cpu_time_used);	
}

void transpose(int *dst, int* src, int dim){
	int i,j;
	start = clock();

	int tmp;
	for ( i=0; i<dim; i++){
		for( j=0; j<dim; j++){
			//tmp = src[i*dim + j];
			//dst[j*dim + i] = tmp;	
			dst[j*dim + i] = src[i*dim + j];
		}
	}
	end = clock();

	cpu_time_used = ((double) (end - start));
	printf("%i\n", (int)cpu_time_used);	
}

void random_matrix(int* matrix, int N){
	int i;
	double u1,u2,tmp1,tmp2;
	struct timeval  t_val;  
	struct timezone t_zone;  

	gettimeofday(&t_val,&t_zone);
	srandom(t_val.tv_usec);

	for(i=0;i<N;i+=2) {
	         u1 = ((double) random()  ) / ((double) RAND_MAX) ;
	         u2 = ((double) random()  ) / ((double) RAND_MAX) ;
	         tmp1 = sqrt(-2.0*log(u1));
	         tmp2 = 2.0*M_PI*u2;
	         matrix[i] = (int) (tmp1*cos(tmp2)*1000);
	         matrix[i+1] = (int) (tmp1*sin(tmp2)*1000);
	    }
}

void save_data(int *data, int N, char *fname)
{
	FILE * fid;

	fid = fopen(fname, "w");
	fwrite(data, sizeof(int), N, fid);
	fclose(fid);

}

int main(int argc, char *argv[] ){

	int n ;
	n = 5; 
	bool save = true;
	int algr  = 0;
	
	switch(argc){
		case(2):
			n = atoi(argv[1]);
			break;
		case(3):
			n = atoi(argv[1]);
			save =(atoi(argv[2])) != 0 ? true:false; 
			break;
		case(4):
			n = atoi(argv[1]);
			save =(atoi(argv[2])) != 0 ? true:false; 
			algr =  (atoi(argv[3])) ;	
			break;	
	}

	int *matrix = calloc( n*n, sizeof(int) );
	int *dst = calloc( n*n, sizeof(int) );

	random_matrix(matrix, n*n);

	switch (algr){
		case 0:
			transpose(dst, matrix, n);
			break;
		case 1: 
			transpose_tmp(dst, matrix, n);
			break;
		case 2: 
			transpose_blocking(dst, matrix, n);
			break;
		default:
			transpose(dst, matrix, n);
	}

	if (save) {
		save_data( matrix, n*n, "m.raw");
		save_data( dst, n*n, "t.raw");	
	}

	free(matrix);
	free(dst);
	return(1);
}


