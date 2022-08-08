#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t mutex;
int X = 0;

void *Process(void *arg)
{
	do
	{
		sem_wait(&mutex); // down
		X = X + 1;
		if(X == 20) 
		{	
			sleep(1);
			X = 0;
		}
		else if(X > 20)
		{
			printf("%d\n", X);
			break;
		}
		printf("%d\n", X);
		sem_post(&mutex); // up
		
	}while(1);
	return NULL;
}

int main(void)
{
	sem_init(&mutex, 0, 1);
	pthread_t pt1, pt2;
	int x = 0;
	pthread_create(&pt2,NULL,Process,NULL);
	pthread_create(&pt1,NULL,Process,NULL);
	
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	sem_destroy(&mutex);
	return 0;
}