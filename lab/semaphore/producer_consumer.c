#include<stdio.h>
#include<pthread.h>


#define BUFFER_SIZE 5
int in=0;
int out=0;
int buffer[BUFFER_SIZE];
int s=1; //mutual exclution semaphore
int e=BUFFER_SIZE;//total empty space semaphore
int f=0;//totoal filled space semaphore

void wait(int *sem)
{
        while(*sem<=0);
        (*sem)--;
}
void signal(int *sem)
{
        (*sem)++;
}
void *produce(void *arg)
{
        int item=1;
        while(1)
        {
                wait(&e);
                wait(&s);

                buffer[in]=item;
                in=(in+1)%BUFFER_SIZE;
                printf("produced:%d\n",item);
                item++;

                signal(&s);
                signal(&f);
                if(item==10)
                {
                        break;
                }
        }
}
void *consume(void *arg)
{
        int item;
        while(1)
        {
                wait(&f);
                wait(&s);

                item=buffer[out];
                out=(out+1)%BUFFER_SIZE;
                printf("cunsumed:%d\n",item);

                signal(&s);
                signal(&e);
        }
}


void main()
{
        pthread_t producer,consumer;

        pthread_create(&producer,NULL,produce,NULL);
        pthread_create(&consumer,NULL,consume,NULL);

        pthread_join(producer,NULL);
        pthread_join(producer,NULL);
}
