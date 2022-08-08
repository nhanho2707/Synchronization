//Compile: gcc -o vd vd.c -lpthread

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
sem_t mutexH, mutexO;
int isLoop=1;

void *MakeH(void *arg)
{
	printf("H\n");
	sem_post(&mutexH); 
	return NULL;
}
void *MakeO(void *arg)
{
	printf("O\n");
	sem_post(&mutexO); 
	return NULL;
}

void *MakeH2O(void *arg)
{
	sem_wait(&mutexH); 
	sem_wait(&mutexO); 
	sem_wait(&mutexH); 
	printf("H2O\n"); 
	return NULL;
}
int main(void)
{
	
	 while (isLoop)
    {
		sem_init(&mutexH, 1, 0);
		sem_init(&mutexO, 1, 0);
		pthread_t pt1, pt2, pt3, pt4;	
		
		pthread_create(&pt1,NULL,MakeH,NULL);
		pthread_create(&pt4,NULL,MakeH,NULL);
		pthread_create(&pt2,NULL,MakeO,NULL);
		pthread_create(&pt3,NULL,MakeH2O,NULL);
		pthread_join(pt1,NULL);
		pthread_join(pt2,NULL);
		pthread_join(pt3,NULL);
		pthread_join(pt4,NULL);
		
		sem_destroy(&mutexH);
		sem_destroy(&mutexO);
    }
	return 0;
}