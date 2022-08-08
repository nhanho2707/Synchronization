#include <pthread.h>
#include <stdio.h>

void *ProcessP1(void *arg)
{
	sleep(1);
	printf("A1\n");
	sleep(1);
	printf("A2\n");
	return NULL;
}

void *ProcessP2(void *arg)
{
	sleep(1);
	printf("B1\n");
	sleep(1);
	printf("B2\n");
	
	return NULL;
}

int main()
{
	pthread_t pt1, pt2;

	
	pthread_create(&pt1,NULL,ProcessP1,NULL);
	pthread_create(&pt2,NULL,ProcessP2,NULL);
	
	pthread_join(pt2,NULL);
	pthread_join(pt1,NULL);
	
	return 0;
}