#include<stdio.h>


void fifo(int frames,int p,int page[])
{
        int frame[10],i,j,hit=0,falt=0,k=0;
        for(i=0;i<frames;i++)
        {
                frame[i]=-1;
        }

        for(i=0;i<p;i++)
        {
                int found=0;
                for(j=0;j<frames;j++)
                {
                        if(page[i]==frame[j])
                        {
                                found=1;
                                hit++;
                                printf("hit\n");
                                break;
                        }
                }
                if(found==0)
                {
                        frame[k]=page[i];
                        k=(k+1)%frames;
                        falt++;
                        for(j=0;j<frames;j++)
                        {
                                if(frame[j]!=-1)
                                        printf("%d ",frame[j]);
                        }printf("\n");

                }
        }
        printf("fault:%d\n",falt);
        printf("hit:%d\n",hit);
}
void lru(int frames,int p,int page[])
{
        struct frame{
                int content,count;
        }frame[10];
        int i,j,hit=0,falt=0,ind=0,cnt=1;
        for(i=0;i<frames;i++)
        {
                frame[i].content=-1;
                frame[i].count=0;
        }
        for(i=0;i<p;i++)
        {
                int found=0;
                for(j=0;j<frames;j++)
                {
                        if(page[i]==frame[j].content)
                        {
                                found=1;
                                hit++;
                                frame[j].count=cnt++;
                                printf("hit\n");
                                break;
                        }

                }
                if(found==0)
                {
                        if(ind<frames)
                        {
                                frame[ind].content=page[i];
                                frame[ind].count=cnt++;
                                ind++;

                        }
                        else
                        {
                                int min=0;
                                for(j=0;j<frames;j++)
                                {
                                        if(frame[min].count>frame[j].count)
                                        {
                                                min=j;
                                        }
                                }
                                frame[min].content=page[i];
                                frame[min].count=cnt++;

                        }
                        falt++;
                        for(j=0;j<frames;j++)
                        {
                                if(frame[j].content!=-1)
                                {
                                        printf("%d ",frame[j].content);
                                }
                        }printf("\n");
                }
        }
        printf("fault:%d\n",falt);
        printf("hit:%d\n",hit);
}

void lfu(int frames,int p,int page[])
{
        struct frame{
                int content,count,freq;
        }frame[10];
        int i,j,hit=0,falt=0,ind=0,cnt=1;
        for(i=0;i<frames;i++)
        {
                frame[i].content=-1;
                frame[i].count=0;
                frame[i].freq=0;
        }
        for(i=0;i<p;i++)
        {
                int found=0;
                for(j=0;j<frames;j++)
                {
                        if(frame[j].content==page[i])
                        {
                                hit++;
                                printf("hit\n");
                                frame[j].freq++;
                        //      frame[j].count=cnt++;
                                found=1;
                                break;
                        }
                }
                if(found==0)
                {
                        if(ind<frames)
                        {
                                frame[ind].content=page[i];
                                frame[ind].count=cnt++;
                                frame[ind].freq=1;
                                ind++;
                        }
                        else
                        {
                                int min=0;
                                for(j=0;j<frames;j++)
                                {
                                        if(frame[min].freq>frame[j].freq||frame[min].freq==frame[j].freq &&
                                                 frame[min].count>frame[j].count)
                                        {
                                                min=j;
                                        }
                                }
                                frame[min].content=page[i];
                                frame[min].count=cnt++;
                                frame[min].freq=1;
                        }
                        falt++;
                        for(j=0;j<frames;j++)
                        {
                                if(frame[j].content!=-1)
                                {
                                        printf("%d ",frame[j].content);
                                }
                        }printf("\n");
                }
        }
        printf("fault:%d\n",falt);
        printf("hit:%d\n",hit);
}
void main()
{
        int i,p,frames,page[100];
        printf("enter the number of page \n");
        scanf("%d",&p);
        printf("enter the pages \n");
        for(i=0;i<p;i++)
        {
                scanf("%d",&page[i]);
        }
        printf("enter the number of frames");
        scanf("%d",&frames);
        printf("---FIFO----\n");
        fifo(frames,p,page);
        printf("--LRU---\n");
        lru(frames,p,page);
        printf("---LFU----\n");
        lfu(frames,p,page);
}
