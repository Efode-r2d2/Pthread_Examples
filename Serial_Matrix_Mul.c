/*Simple serial matrix multiplication program */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* initializing one dimensional array */
void init(int * array, int size);
/* initializing two dimensional array */
void init(int * array, int col, int row);
/* printing one dimensional array */
void print(int * array, int size);
/* printing two dimensional array */
void print(int* array, int col, int row);

int main(void)
{
	
	return 0;
}
/* initialization function */
void init(int * array, int size){
	srand(1);
	for(int i=0;i<size;i++){
		array[i] = rand();	
	}
}
/* a function to print an array */
void print(int * array, int size){
	for(int i=0;i<
}

