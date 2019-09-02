#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int share=0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
void numincrease()
{
	int i,tmp;
	for(i=0;i<1000000;i++)
	{
		if(pthread_mutex_lock(&mutex)!=0)
		{
			printf("lock fail");
			exit(0);
		}
		tmp=share;
		tmp+=1;
		share=tmp;
		if(pthread_mutex_unlock(&mutex)!=0)
		{
			printf("unlock fail");
			exit(0);
		}
	}
}

int main()
{
	int ret;
	pthread_t thread1,thread2,thread3;
	ret=pthread_create(&thread1,NULL,(void *)&numincrease,NULL);
	ret=pthread_create(&thread2,NULL,(void *)&numincrease,NULL);
	ret=pthread_create(&thread3,NULL,(void *)&numincrease,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);	
	pthread_join(thread3,NULL);
	
	printf("share=%d\n",share);
}
