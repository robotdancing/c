#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define MAXSIZE 100
int stack[MAXSIZE];
sem_t sem;

void provider()
{
	int i;
	for(i=0;i<MAXSIZE;i++)
	{
		stack[i]=i;
		sem_post(&sem);
	}
}

void handler()
{
	int i=0;
	while((i++)<MAXSIZE)
	{	
		sem_wait(&sem);
		printf("mutiply:stack[i]=%d*%d=%d\n",stack[i],stack[i],stack[i]*stack[i]);
		sleep(1);	
	}
}

int main()
{
	sem_t sem;
	sem_init(&sem,0,0);
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,(void *)&provider,NULL);
	pthread_create(&thread2,NULL,(void *)&handler,NULL);
	
	pthread_join(thread1,NULL);
	printf("%d",pthread_self());
	pthread_join(thread2,NULL);
	
	sem_destroy(&sem);	
}
