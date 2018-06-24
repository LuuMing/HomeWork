/* ==================================================
 * Reader Writer problem
 * @filename:"reader_wirter.c"
 * @author: MingLu
 * @time: 18/6/24
====================================================*/
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
/* CONSTANTS =======================================*/
#define NUM_READERS 5
#define NUM_READS 10
#define NUM_WRITERS 5
#define NUM_WRITES 10

/* GLOBAL SHARED DATA ==============================*/
int sharedValue = 0;
pthread_mutex_t sharedMemoryLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t readPhase = PTHREAD_COND_INITIALIZER;
pthread_cond_t writePhase = PTHREAD_COND_INITIALIZER;
int waitingReaders = 0;
int readers = 0;

/* THREAD ==========================================*/
void * reader(void *id);
void * writer(void *id);

int main()
{
	int i;
	
	int readerNum[NUM_READERS];
	int writerNum[NUM_WRITERS];
	
	pthread_t readerThreadIDs[NUM_READERS];
	pthread_t writerThreadIDs[NUM_WRITERS];
	
	for(i = 0; i < NUM_READERS; i++)
	{
		readerNum[i] = i;
		pthread_create(&readerThreadIDs[i], NULL, reader, &readerNum[i]);
	}
	
	for(i = 0; i < NUM_WRITERS; i++)
	{
		writerNum[i] = i;
		pthread_create(&writerThreadIDs[i], NULL, writer, &writerNum[i]);
	}
	for(i = 0; i < NUM_READERS; i++)
	{
		pthread_join(readerThreadIDs[i], NULL);	
		pthread_join(writerThreadIDs[i], NULL);
	}
	return 0;
}

void * reader(void *id)
{
	int i = 0, numReaders = 0;
	for(i = 0; i < NUM_READS; i++)
	{
		usleep(1000 * (random() % NUM_READERS + NUM_WRITERS));
		// Enter critical section
		pthread_mutex_lock(&sharedMemoryLock);
			waitingReaders++;
			while(readers == -1) // when writer is writing, wait
			{
				pthread_cond_wait(&readPhase, &sharedMemoryLock);
			}
			waitingReaders--;
			numReaders = ++readers; 
		pthread_mutex_unlock(&sharedMemoryLock);
		printf("[r%d] reading %d [raders: %d]\n", *((int*)id), sharedValue, numReaders); 
		fflush(stdout);
		
		// Exit critical section
		pthread_mutex_lock(&sharedMemoryLock);
			readers--;
			if( readers == 0)
			{
				pthread_cond_signal(&writePhase);
			}
		pthread_mutex_unlock(&sharedMemoryLock);
	}
	pthread_exit(0);
}
void * writer(void *id)
{
	int i = 0, numReaders = 0;
	for(i = 0; i < NUM_WRITES; i++)
	{
		usleep(1000 * (random() % NUM_READERS + NUM_WRITERS));
		
		// Enter critical section
		pthread_mutex_lock(&sharedMemoryLock);
			while( readers != 0)
			{
				pthread_cond_wait(&writePhase, &sharedMemoryLock);
			}
			readers = -1;
			numReaders = readers;
		pthread_mutex_unlock(&sharedMemoryLock);
		
		printf("[w%d] wirting %d* [readers: %d]\n", *((int*)id), ++sharedValue, numReaders);
		fflush(stdout);
		//Exit critical section
		pthread_mutex_lock(&sharedMemoryLock);
			readers = 0;
			if(waitingReaders > 0) //if multi readers waiting writer's finish, broadcast 
			{
				pthread_cond_broadcast(&readPhase);  
			}
			else
			{
				pthread_cond_signal(&writePhase);
			}
		pthread_mutex_unlock(&sharedMemoryLock);
	}
	pthread_exit(0);
}

