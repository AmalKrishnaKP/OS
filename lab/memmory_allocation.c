#include<stdio.h>

void first(int p,int p_block[],int m,int m_block[])
{
    int i,j,pblock[10],mblock[10];
    for(i=0;i<p;i++)
    {
        pblock[i]=p_block[i];
    }
    for(j=0;j<m;j++)
    {
        mblock[i]=m_block[i];
    }
    for(i=0;i<p;i++)
    {
        int flag=0;
        for(j=0;j<m;j++)
        {
            if(pblock[i]<=mblock[j])
            {
                printf("%d allocated in %d",pblock[i],mblock[j]);
                mblock[j]-=pblock[i];
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("process %d cannot allocate",pblock[i]);
        }
    }
}
void bestfit(int p,int p_block[],int m,int m_block[])
{
    int i,j,pblock[10],mblock[10];
    for(i=0;i<p;i++)
    {
        pblock[i]=p_block[i];
    }
    for(i=0;i<m;i++)
    {
        mblock[i]=m_block[i];
    }
    for(i=0;i<p;i++)
    {
        int loc=-1;
        for(j=0;j<m;j++)
        {
            if(pblock[i]<=mblock[j])
            {
                if(loc==-1)
                {
                    loc=j;
                }
                else if(mblock[loc]>mblock[j])
                {
                    loc=j;
                }
            }
        }
        if(loc!=-1)
        {
            printf("%d located in %d",pblock[i],mblock[loc]);
            mblock[loc]-=pblock[i];
        }
        else
        {
            printf("%d cannot allocate",pblock[i]);
        }
    }
}
void worstfit(int p,int p_block[],int m,int m_block[])
{
    int i,j,pblock[10],mblock[10];
    for(i=0;i<p;i++)
    {
        pblock[i]=p_block[i];
    }
    for(i=0;i<m;i++)
    {
        mblock[i]=m_block[i];
    }
    for(i=0;i<p;i++)
    {
        int max=0;
        int loc=-1;
        for(j=0;j<m;j++)
        {
            if(max<mblock[j])
            {
                max=mblock[j];
                loc=j;
            }
        }
        if(pblock[i]<=mblock[loc])
        {
            printf("%d allocated in %d block",pblock[i],mblock[loc]);
            mblock[loc]-=pblock[i];
        }
        else
        {
            printf("%d cannote allocate",pblock[i]);
        }
    }
    
}
void main()
{
    int p,m,i,j,p_block[10],m_block[10];
    printf("enter the number of process");
    scanf("%d",&p);
    printf("enter the number of memory block");
    scanf("%d",&m);
    printf("enter process sizes");
    for(i=0;i<p;i++)
    {
        scanf("%d",&p_block[i]);
    }
    printf("enter memory block sizes");
    for(i=0;i<m;i++)
    {
        scanf("%d",&m_block[i]);
    }
    printf("\n FIRST FIT \n");
    first(p,p_block,m,m_block);
    printf("\n BEST FIT \n");
    bestfit(p,p_block,m,m_block);
    printf("\n WORST FIT \n");
    worstfit(p,p_block,m,m_block);
}
