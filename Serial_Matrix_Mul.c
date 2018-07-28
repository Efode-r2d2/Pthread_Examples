/*****************************************************************************
	
	Desc: Simple serial matrix multiplication program 
	this program can multiply m*n matrix with one dimensional array of size n.
	Author: Efriem Desalew, efidesalew@gmail.com
	Compiling: gcc -o [object file name] [source file name]
	Running: ./[object file name] [row size] [col size]

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* initializing one dimensional array */
void init(int * array, int size);
/* initializing two dimensional array */
void init2D(int ** array, int col, int row);
/* printing one dimensional array */
void print(int * array, int size);
/* printing two dimensional array */
void print2D(int** array, int col, int row);
/* set an array to zero*/
void setZero(int * array, int size);
/*multiplication function m*n array with n size array */
void mult(int **array, int *x, int *y, int col, int row);
/* calculate time elapsed */
void timeElapsed(clock_t begin, clock_t end);
int main(int argc, char * argv[])
{
	int col,row;
	int ** array;
	int * y, x;
	
	/* getting row size from command line */
	row = strtol(argv[1],NULL,10);
	/* getting col size from command line */
  col = strtol(argv[1],NULL,10);
	
	/*allocating memory for the two dimensional array */
  array = malloc(row*sizeof(int*));
	for(int i=0;i<row;i++){
	array[i] = malloc(col*sizeof(int));
	}
	/* allocating memory for one dimensional array */
	x = malloc(sizeof(int)*col);
	y = malloc(sizeof(int)*row);
	
	/*initializing a two dimenstional array*/
  init2D(array,col,row);
	/*initializing one dimensional array */
  init(x,col);
  /*setting values of an array y to zero */
	setZero(y,row);
  
	/*printing input 2D array */
  printf("input 2D array \n");
  print2D(array,col,row);
  /* printing input 1D array*/
  printf("input 1D array \n");
  print(x,col);
  /* printing output1D array*/
  printf("output 1D array \n");
  print(y,row); 
	
	/*multiplication */
	clock_t begin = clock();
	mult(array,x,y,col,row);
	clock_t end = clock();
	
	/* printing the result */
  printf("output 1D array \n");
  print(y,row);
	
	/* calculate time elapsed */
	timeElapsed(begin,end);
	return 0;
}
/* initializing one dimensional array */
void init(int * array, int size){
	srand(1);
	for(int i=0;i<size;i++){
		array[i] = i+1;	
	}
}
/* printing one dimensional array */
void print(int * array, int size){
	for(int i=0;i<size;i++){
		printf("%d \n",array[i]);
	}
}
/* initializing two dimensional array */
void init2D(int ** array, int col, int row){
	srand(1);
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			array[i][j]= i*j+1;
		}	
	}
}
/* printing two dimensional array */
void print2D(int** array, int col, int row){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d ,", array[i][j]);		
		}	
    printf("\n");
	}
}
/*multiplication function m*n array with n size array */
void mult(int **array, int *x, int *y, int col, int row){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			y[i]+=array[i][j]*x[j];
		}	
	}
}
/* set values of an array to zero */
void setZero(int * array, int size){
	for(int i=0;i<size;i++){
		array[i]=0;
	}
}
/* calculate time elapsed */
void timeElapsed(clock_t begin, clock_t end){
	float time_elapsed = (float)(((end-begin)*(1000.0))/CLOCKS_PER_SEC);
	printf("Time Elapsed is %f ms \n", time_elapsed);
}


