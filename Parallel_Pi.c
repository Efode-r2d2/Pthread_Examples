/*
	Author: Efriem Desalew
	Desc: this is a simple parallel c program which can calculate the value of pi.
  Compiling:
	Running: 
	Date july/29/2018 
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int thread_count;
int n;
double sum=0.0;
/* thread function */
void * Thread_sum(void* rank);
int main(int argc, char* argv[]){
	long thread;
	pthread_t* thread_handles;
	
	/* Get number of threads from command line */
	thread_count = strtol(argv[1],NULL,10);
	/* get n from command line */
	n = strtol(argv[2],NULL,10);
	
	thread_handles = malloc(thread_count*sizeof(pthread_t));
	for(thread=0;thread<thread_count;thread++)
		pthread_create(&thread_handles[thread],NULL,Thread_sum, (void*)thread);
	for(thread=0;thread<thread_count;thread++)
		pthread_join(thread_handles[thread],NULL);
	free(thread_handles);
	printf("The sum is: %f \n",sum*4.0);
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
		sum+=factor/(2*i+1);	
	}
	
	return NULL;
}
