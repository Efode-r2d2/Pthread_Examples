/*****************************************************************************
	Desc: Simple serial matrix multiplication program 
	this program can multiply m*n matrix with one dimensional array of size n.
	Author: Efriem Desalew, efidesalew@gmail.com, +251932179081
	

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

int main(void)
{
	int col;row;
	int ** array;
	int * y, m;
	/* getting row size from command line */
	row = strtol(argv[1],NULL,10);
	/* getting col size from command line */
  col = strtol(argv[1],NULL,10);
	/*allocating memory for the two dimensional array */
  array = malloc(row*sizeof(int*));
	for(int i=0;i<row;i++){
	array[i] = malloc(col*sizeof(int));
	}
	
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
			printf("%d \n", array[i][j]);		
		}	
	}
}


