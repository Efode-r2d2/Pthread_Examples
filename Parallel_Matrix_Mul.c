/*****************************************************************************
	
	Desc: Parallel matrix-vector multiplication program using pthread
	this program can multiply m*n matrix with one dimensional array of size n.
	Author: Efriem Desalew, efidesalew@gmail.com
	Compiling: gcc -o [object file name] [source file name] -lpthread
	Running: ./[object file name] [row size] [col size]

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

int ** array;
int * x;
int * y;
int row,col;
int thread_count;

/* matric vector multiplication function*/
void * Pth_mat_vect(void * rank);
/* initializing one dimensional array */
void init(int * array, int size);
/* initializing two dimensional array */
void init2D(int ** array, int col, int row);
/* printing one dimensional array */
void print(int * array, int size);
/* printing two dimensional array */
void print2D(int** array, int col, int row);
/* calculate time elapsed */
void timeElapsed(clock_t begin, clock_t end);
int main(int argc, char * argv[]){
	
	long thread;
	pthread_t* thread_handles;

	/* getting row size from command line */
	row = strtol(argv[1],NULL,10);

	/* getting col size from command line */
  col = strtol(argv[2],NULL,10);

	/* getting number of threads from command line*/
	thread_count = strtol(argv[3],NULL,10);

	/* memory allocation for the 2D array*/
  array = malloc(sizeof(int *)*row);
  for(int i=0;i<row;i++){
		array[i]=malloc(sizeof(int)*col);	
	}
	
	/*memory allocation for 1D array*/
  y= malloc(sizeof(int)*row);
  x= malloc(sizeof(int)*col);
	
	/*memory allocation for thread_handles */
	thread_handles = malloc(thread_count*sizeof(pthread_t));
	
  /* initializing 2D array*/
	init2D(array,col,row);
	
	/* initializing 1D array*/
	init(x,col);

  /* printing input 2D array */
	//printf("Input 2D array \n");
  //print2D(array,col,row);
	
	/* printing input 1D arrray*/
	//print(x,col);
	
	/* creating threads*/
  clock_t begin = clock();
	for(thread=0;thread<thread_count;thread++)
		pthread_create(&thread_handles[thread],NULL,Pth_mat_vect, (void*)thread);
	
	/* waiting threads to finish*/
	for(thread=0;thread<thread_count;thread++)
		pthread_join(thread_handles[thread],NULL);
	clock_t end = clock();

	/* printing the final result*/
	//printf("Output 1D array \n");
  //print(y,row);
  
  /* calculating elapsed time */
  timeElapsed(begin,end);
	free(array);
	free(x);
	free(y);
  free(thread_handles);
	return 0;
}
/* matric vector multiplication function*/
void * Pth_mat_vect(void * rank){
	long my_rank = (long)rank;
  int i,j;
	int local_row = row/thread_count;
	int my_first_row = my_rank*local_row;
	int my_last_row = (my_rank+1)*local_row-1;
	
	for(i=my_first_row;i<=my_last_row;i++){
		y[i]=0;
		for(j=0;j<col;j++){
			y[i]+=array[i][j]*x[j];		
		}
	}
	return NULL;
}
/* initializing one dimensional array */
void init(int * array, int size){
	srand(1);
	for(int i=0;i<size;i++){
		array[i] = 1;	
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
			array[i][j]= 1;
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
/* calculate time elapsed */
void timeElapsed(clock_t begin, clock_t end){
	float time_elapsed = (float)(((end-begin)*(1000.0))/CLOCKS_PER_SEC);
	printf("Time Elapsed is %f ms \n", time_elapsed);
}
