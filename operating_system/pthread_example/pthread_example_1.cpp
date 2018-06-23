#include<stdio.h>
#include<pthread.h>
#define NUM_THREADS 4

void * threadFunc(void * pArg)
{
	int * p = (int * )pArg; //these two step has problem
	int myNum = *p;         //the data of address i could be change before store it to myNum
	printf("Thread number %d\n",myNum);
	return 0;
}
int main()
{
	int i;
	pthread_t tid[NUM_THREADS];
	for(i = 0; i < NUM_THREADS;i++)
	{
		pthread_create(&tid[i],NULL,threadFunc,&i);//pass the address of i
	}
	for(i = 0; i < NUM_THREADS;i++)
	{
		pthread_join(tid[i],NULL);
	}
	return 0;
}
