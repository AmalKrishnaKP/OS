#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#define size 20
char buffer[size];

int in=0,out=0;
int produce=1;  //synchronisation between producer
int s=1;        //synchronisation between producer and consumer
int e=size;
int f=0;

void wait(int *sem)
{
        while(*sem<=0);
        (*sem)--;
}
void sig(int *sem)
{
        (*sem)++;
}
void *producer(void *arg)
{
        printf("hello");
        int i;
        int *type=(int *)arg;
        char item;
        int start=(*type==1?1:2);
        if(start==1)
        {
                item='1';
        }
        else if(start==2)
        {
                item='a';
        }
        printf("hello");
        for(i=0;i<9;i++)
        {
                wait(&e);
                wait(&s);
                wait(&produce);
//              sleep(1);

                buffer[in]=item;
                printf("produce: %c",buffer[in]);
                in=(in+1)%size;
                item=item+1;

                sig(&produce);
                sig(&s);

                sig(&f);


        }
}
void *consumer(void *arg)
{
        printf("helloofe");
        int i;
        char item;
        for(i=0;i<9;i++)
        {
                wait(&f);
                wait(&s);

                        item=buffer[out];
                        out=(out+1)%size;
                        printf("consumed: %c",item);
                sig(&s);
                sig(&e);
//              sleep(1);
        }

}
void main()
{
        pthread_t numb,ch,con;
        int num=1,charo=2;

        pthread_create(&numb,NULL,producer,(void *)&num);
        pthread_create(&ch,NULL,producer,(void *)&charo);
        pthread_create(&con,NULL,consumer,NULL);

        pthread_join(numb,NULL);
        pthread_join(ch,NULL);
        pthread_join(con,NULL);
}
