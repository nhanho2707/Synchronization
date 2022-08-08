#include "stdio.h"
#include "semaphore.h"
#include "pthread.h"
#include "signal.h"
#include <stdlib.h>
#include <unistd.h>

pthread_t ThreadA;
pthread_t ThreadB;

sem_t Sem_1;
sem_t Sem_2;

int isLoop=1;
int X=0;

void *FunctionA(void *data)
{
    while (1)
    {
        X++;
        printf("%d\n",X);
        if (X==20)
        {
            X=0;
        }
    }
    
}


void *FunctionB(void *data)
{
    while (1)
    {
        sleep(1);
        X++;
        printf("%d\n",X);
        if (X==20)
        {
            X=0;
        }
        
    }
    
}
int main()
{
    sem_init(&Sem_1,1,0);
    sem_init(&Sem_2,1,10);
    pthread_create(&ThreadB,NULL,&FunctionB,NULL);
    pthread_create(&ThreadA,NULL,&FunctionA,NULL);
    while (isLoop)
    {
    
    }
    return 0;

}
