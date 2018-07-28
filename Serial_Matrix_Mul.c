/*****************************************************************************
	Desc: Simple serial matrix multiplication program 
	this program can multiply m*n matrix with one dimensional array of size n.
	Author: Efriem Desalew, efidesalew@gmail.com
	

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
int main(void)
{
	int col;row;
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
	mul(array,x,y,col,row);
	
	/* printing the result */
  printf("output 1D array \n");
  print(y,row);
	
	return 0;
}
/* initializing one dimensional array */
void init(int * array, int size){
	srand(1);
	for(int i=0;i<size;i++){
		array[i] = rand();	
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
			array[i][j]= rand();
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


