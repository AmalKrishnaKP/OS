
#include <stdio.h>

void main()
{
    int n,m,i,j,k,y,av[5],max[10][10],need[10][10],alloc[10][10],avail[5],work[5],sequence[10],finish[10];
    int flag,ind=0;
    
    printf("enter the number of resources");
    scanf("%d",&m);
    printf("enter the number of process");
    scanf("%d",&n);
    // allocation metrix
    printf("enter the allocation metrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    //max metrix
    printf("enter the max metrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("enter the avail matrix");
    for(i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }
    //need metrix
    printf("need metrix is");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d  ",need[i][j]);
        }
        printf("\n");
    }
    //condition
        //work=avail
    for(i=0;i<m;i++)
    {
        work[i]=avail[i];
    }
        //finish=0
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    //checking
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
            flag=1;
            for(j=0;j<m;j++)
            {
                if(need[i][j]>work[j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                sequence[ind++]=i;
                for(y=0;y<m;y++)
                {
                    work[y]=work[y]+alloc[i][y];
                }
                finish[i]=1;
            }
            }
            
        }
    }
    int safe=1;
    for(i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
            safe=0;
            break;
        }
    }
    if(safe)
    {
        printf("safe sequence is \n");
        for(i=0;i<n;i++)
        {
            printf("p%d ",sequence[i]);
        }
    }
    else
    {
        printf("unsafe");
    }
    
    
}
