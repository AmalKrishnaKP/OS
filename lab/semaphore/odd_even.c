#include<stdio.h>KTOP-HVHV3TP:~/S4/OS/EXAM$ cat 5_semaphore.c
#include<stdlib.h>
#include<unistd.h>
#include <pthread.h>
#define max 10

int s=1;
int turn=0;

void wait(int *arg)
{
        while(s<=0 || turn!=*arg);
        s--;
}
void signal()
{
        s++;
        turn=1-turn;
}
void *print_num(void *arg)
{
        int *type=(int *)arg;
        int i;
        int start=(*type==0?0:1);
        for(i=start;i<max;i=i+2)
        {
                wait(&start);

                if(start==0)
                {
                        printf("even nmuber :%d\n",i);
                }
                else
                {
                        printf("odd number:%d\n",i);
                }
                signal();

                sleep(2);
        }
}


void main()
{
        pthread_t ot,et;
        int even_arg=0,odd_arg=1;

        pthread_create(&et,NULL,print_num,(void *)&even_arg);
        pthread_create(&ot,NULL,print_num,(void *)&odd_arg);
        pthread_join(et,NULL);
        pthread_join(ot,NULL);

}
