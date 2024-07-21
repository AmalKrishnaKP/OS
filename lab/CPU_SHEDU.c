#include<stdio.h>
#include<stdlib.h>

struct process
{
        int at,bt,ct,tt,wt,rem,complete,pid,prio;
}p[10],temp;
int i,j,n;

void fcfs()
{
        float avg_wt=0,avg_tt=0;
        int currenttime=0;
        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-1-i;j++)
                {
                        if(p[j].at>p[j+1].at)
                        {
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }
        printf("| PID | AR_T | BT_T | CP_T | TN_T | WT_T |\n");
        for(i=0;i<n;i++)
        {
                while(currenttime<p[i].at)
                {
                        currenttime++;
                }
                p[i].ct=currenttime+p[i].bt;
                currenttime=p[i].ct;
                p[i].tt=p[i].ct-p[i].at;
                p[i].wt=p[i].tt-p[i].bt;
                avg_wt+=p[i].wt;
                avg_tt+=p[i].tt;
                printf("|  %d |  %d |  %d |  %d |  %d |  %d |\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
        }
        printf("average turnaround time:%f\n",(avg_tt/n));
        printf("average waiting time:%f\n",(avg_wt/n));
}

void sjf()
{
        float avg_wt=0,avg_tt=0;
        int current=0;
        for(i=0;i<n;i++)
        {
                p[i].complete=0;
        }
        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-1-i;j++)
                {
                        if(p[j].at>p[j+1].at)
                        {
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }
        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-1-i;j++)
                {
                        if(p[j].at==p[j+1].at && p[j].bt>p[j+1].bt)
                        {
                                temp=p[i];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }
        int complete=0;
        printf("| PID | AR_T | BT_T | CP_T | TN_T | WT_T |");
        while(complete!=n)
        {
                int mintime=1000;
                int min_index=-1;
                for(i=0;i<n;i++)
                {
                        if(p[i].at<=current && p[i].complete==0)
                        {
                                if(p[i].bt<mintime)
                                {
                                        mintime=p[i].bt;
                                        min_index=i;
                                }
                                if(p[i].bt==mintime)
                                {
                                        if(p[i].at<p[min_index].at)
                                        {
                                                mintime=p[i].bt;
                                                min_index=i;
                                        }
                                }
                        }
                }
                if(min_index==-1)
                {
                        current++;
                }
                else
                {
                        p[min_index].ct=current+p[min_index].bt;
                        p[min_index].tt=p[min_index].ct-p[min_index].at;
                        p[min_index].wt=p[min_index].tt-p[min_index].bt;
                        avg_tt+=p[min_index].tt;
                        avg_wt+=p[min_index].wt;
                        complete++;
                        p[min_index].complete=1;
                        current=p[min_index].ct;
                        printf("| %d |  %d |  %d |  %d |  %d |  %d |\n",p[min_index].pid,p[min_index].at,p[min_index].bt,p[min_index].ct,p[min_index].tt,p[min_index].wt);
                }
        }
        printf("average turnaround time:%f\n",(avg_tt/n));
        printf("average waiting time:%f\n",(avg_wt/n));
}


void priority()
{
        float avg_tt=0,avg_wt=0;
        int current=0;
        for(i=0;i<n;i++)
        {
                p[i].complete=0;
        }
        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(p[j].at>p[j+1].at)
                        {
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }
        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(p[j].at==p[j+1].at && p[j].bt>p[j+1].bt)
                        {
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }
        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        if(p[j].prio>p[j+1].prio)
                        {
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }
        int complete=0;
        printf("| PID | AR_T | BT_T | CP_T | TN_T | WT_T |");
        while(complete!=n)
        {
                int max_prio=100;
                int min_index=-1;
                for(i=0;i<n;i++)
                {
                        if(p[i].at<=current && p[i].complete==0)
                        {
                                if(p[i].prio<max_prio)
                                {
                                        max_prio=p[i].prio;
                                        min_index=i;
                                }
                        }
                }
                if(min_index==-1)
                {
                        current++;
                }
                else
                {
                        p[min_index].ct=p[min_index].bt+current;
                        p[min_index].tt=p[min_index].ct-p[min_index].at;
                        p[min_index].wt=p[min_index].tt-p[min_index].bt;
                        avg_wt+=p[min_index].wt;
                        avg_tt+=p[min_index].tt;
                        p[min_index].complete=1;
                        complete++;
                        current=p[min_index].ct;
                        printf("| %d |  %d |  %d |  %d |  %d |  %d |\n",p[min_index].pid,p[min_index].at,p[min_index].bt,p[min_index].ct,p[min_index].tt,p[min_index].wt);
                }
        }
        printf("average turnaround time:%f\n",(avg_tt/n));
        printf("average waiting time:%f\n",(avg_wt/n));
}

void roundrobin()
{
        int slice,flag=0;
        float avg_tt=0,avg_wt=0;
        printf("enter the time slice\n");
        scanf("%d",&slice);

        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-1-i;j++)
                {
                        if(p[j].at>p[j+1].at)
                        {
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }
         for(i=0;i<n;i++)
        {
                p[i].rem=p[i].bt;
        }
        int remain=n;
        int time;
        for(time=0,i=0;remain!=0;)
        {
                if(p[i].rem<=slice && p[i].rem>0)
                {
                        time+=p[i].rem;
                        p[i].rem=0;
                        flag=1;
                }
                else if(p[i].rem>0)
                {
                        p[i].rem=p[i].rem-slice;
                        time=slice+time;
                }
                if(p[i].rem==0 && flag==1)
                {
                        p[i].ct=time;
                        p[i].tt=p[i].ct-p[i].at;
                        p[i].wt=p[i].tt-p[i].bt;
                        avg_wt+=p[i].wt;
                        avg_tt+=p[i].tt;
                        printf("|  %d |  %d |  %d |  %d |  %d |  %d |\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
                        remain--;
                        flag=0;
                }
                if(i==(n-1))
                {
                        i=0;
                }
                else if(p[i+1].at<=time)
                {
                        i=i+1;
                }
                else
                {
                        i=0;
                }
        }
        printf("average turnaround time:%f\n",(avg_tt/n));
        printf("average waiting time:%f\n",(avg_wt/n));
}

void main()
{
        printf("enter the number of process");
        scanf("%d",&n);
        printf("enter the pid,at,bt,prio");
        for(i=0;i<n;i++)
        {
                scanf("%d %d %d %d",&p[i].pid,&p[i].at,&p[i].bt,&p[i].prio);
        }
        printf("\n----fcfs----\n");
        fcfs();
        printf("\n----sjf-----\n");
        sjf();
        printf("\n----priority-----\n");
        priority();
        printf("\n----roundrobin-----\n");
        roundrobin();
}
