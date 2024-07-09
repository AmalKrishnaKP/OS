#include<stdio.h>
#include<stdlib.h>
int initial,p[10],temp[10],n,size;


void fcfs()
{
        int current=initial;
        int seak=0,i;

        for(i=0;i<n;i++)
        {
                seak+=abs(current-p[i]);
                current=p[i];
        }
        printf("FCFS total seak time=%d",seak);
}

void scan()
{
        int i,j,index;
        int current=initial;
        int seak=0;
        int temp_v;
        for(i=0;i<n;i++)
        {
                for(j=0;j<n-1-i;j++)
                {
                        if(temp[j]>temp[j+1])
                        {
                                temp_v=temp[j];
                                temp[j]=temp[j+1];
                                temp[j+1]=temp_v;
                        }
                }
        }
        for(i=0;i<n;i++)
        {
                if(current<temp[i])
                {
                        index=i;
                        break;
                }
        }
        for(i=index;i<n;i++)
        {
                seak+=abs(current-temp[i]);
                current=temp[i];
        }
        seak+=abs(current-(size-1));
        current=(size-1);
        for(i=(index-1);i>=0;i--)
        {
                seak+=abs(current-temp[i]);
                current=temp[i];
        }
        seak+=abs(current-0);
        printf(" SCAN total seak time:%d/n",seak);
}
void cscan()
{
        int i,j,index;
        int current=initial;
        int seak=0;
        int temp_v;
        for(i=0;i<n;i++)
        {
                for(j=0;j<n-1-i;j++)
                {
                        if(temp[j]>temp[j+1])
                        {
                                temp_v=temp[j];
                                temp[j]=temp[j+1];
                                temp[j+1]=temp_v;
                        }
                }
        }
        for(i=0;i<n;i++)
        {
                if(current<temp[i])
                {
                     index=i;

                        break;
                }
        }
        for(i=index;i<n;i++)
        {
                seak+=abs(current-temp[i]);
                current=temp[i];
        }
        seak+=abs(current-(size-1));
        current=(size-1);
        seak+=abs(current-0);
        current=0;
        for(i=0;i<index;i++)
        {
                seak+=abs(current-temp[i]);
                current=temp[i];
        }

        printf("C_SCAN total seak time:%d\n",seak);
}
void main()
{
        int i;
        printf("enter the number of cilynders\n");
        scanf("%d",&n);
        printf("enter the cilinders in order\n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&p[i]);
        }
        printf("enter the maximum size\n");
        scanf("%d",&size);
        for(i=0;i<n;i++)
        {
                temp[i]=p[i];
        }
        fcfs();
        scan();
        cscan();
}
