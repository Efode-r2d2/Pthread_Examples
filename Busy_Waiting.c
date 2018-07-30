/*
	Author: Efriem Desalew, efidesalew@gmial.com
	Desc: This is a simple parallel c program which can calculate the value of pi. This program demonstrate how to avoid race condition using 			busy waiting technique. 
	Compiling:gcc -o [object file name] [source file name] -lpthread
	Running: ./[object file name] [number of threads] [size of n]
	Date: july/29/2018 
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

int thread_count;
int n;
double sum=0.0;
int flag=0;
/* thread function */
void * Thread_sum(void* rank);
/* calculate time elapsed */
void timeElapsed(clock_t begin, clock_t end);
int main(int argc, char* argv[]){
	
	long thread;
	pthread_t* thread_handles;
	
	/* Get number of threads from command line */
	thread_count = strtol(argv[1],NULL,10);
	/* get n from command line */
	n = strtol(argv[2],NULL,10);
	
	thread_handles = malloc(thread_count*sizeof(pthread_t));
	clock_t begin=clock();
	
	/* creating threads */
	for(thread=0;thread<thread_count;thread++)
		pthread_create(&thread_handles[thread],NULL,Thread_sum, (void*)thread);
	
	/* waiting threads to finish */
	for(thread=0;thread<thread_count;thread++)
		pthread_join(thread_handles[thread],NULL);
	clock_t end = clock();
	free(thread_handles);
	printf("The sum is: %f \n",sum*4.0);

	/* printing time elapsed */
	timeElapsed(begin,end);
	return 0;
}
/* thread function */
void * Thread_sum(void* rank){
	long my_rank = (long)rank;
	double factor;
	long long i;
	long long my_n = n/thread_count;
	long long my_first_i = my_n*my_rank;
	long long my_last_i = my_first_i+my_n;
	
	if(my_first_i%2==0)
		factor=1.0;
	else
		factor = -1.0;
	
	for(i=my_first_i;i<my_last_i;i++,factor=-factor){
		/* busy waiting */
		while (flag != my_rank);
		sum+=factor/(2*i+1);
		flag = (flag+1) % thread_count;	
	}
	
	return NULL;
}
/* calculate time elapsed */
void timeElapsed(clock_t begin, clock_t end){
	float time_elapsed = (float)(((end-begin)*(1000.0))/CLOCKS_PER_SEC);
	printf("Time Elapsed is %f ms \n", time_elapsed);
}
