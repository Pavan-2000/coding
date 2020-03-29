#include<stdio.h>
#include<string.h>

char process[10][5],temp[5];
int pt[10],wt[10],tot_wait=0,pr[10],temp1,no;
float avg_wait;
    
void main()
{
   printf("----------------------->PROJECT OF OPERATING SYSTEM<-------------------------------\n\n\n\n");
    printf("Enter no of processes:  ");
    scanf("%d",&no);
    printf("\n\n");
    int i;
    for(i=0;i<no;i++)
    {
        printf("\nEnter process%d name:",i+1);
        scanf("%s",&process[i]);
        printf("enter process time:");
        scanf("%d",&pt[i]);
        printf("enter priority:");
        scanf("%d",&pr[i]);
    }
    int j;
    for(i=0;i<no-1;i++)
    {
        for(j=i+1;j<no;j++)
        {
            if(pr[i]>pr[j])
            {
                temp1=pr[i];
                pr[i]=pr[j];
                pr[j]=temp1;
                temp1=pt[i];
                pt[i]=pt[j];
                pt[j]=temp1;
                strcpy(temp,process[i]);
                strcpy(process[i],process[j]);
                strcpy(process[j],temp);
            }
        }
    }
    wt[0]=0;
    for(i=1;i<no;i++)
    {
        wt[i]=wt[i-1]+wt[i-1];
        tot_wait=tot_wait+wt[i];
    }
    avg_wait=(float)tot_wait/no;
    printf("p_name\t p_time\t priority\t w_time\n");
    for(i=0;i<no;i++)
    {
       printf(" %s\t %d\t %d\t     \t%d\n" ,process[i],pt[i],pr[i],wt[i]);
    }
    printf("total waiting time=%d\naverage waiting time=%f",tot_wait,avg_wait);
   
    int ts,pid[10],need[10],wt1[10],tat[10],i1,j1,n2,n1;
    int bt[10],flag[10],ttat=0,twt=0;
    float awt,atat;
    printf("\nEnter the number of Processors \n");
    scanf("%d",&no);
    n1=no;
    printf("\nEnter the Timeslice \n");
    scanf("%d",&ts);
    for(i=1;i<=no;i++)
    {
        printf("\nEnter the process ID %d",i);
        scanf("%d",&pid[i]);
        printf("\nEnter the Burst Time for the process");
        scanf("%d",&bt[i]);
        need[i]=bt[i];
    }
    for(i=1;i<=no;i++)
    {
        flag[i]=1;
        wt[i]=0;
    }
    while(no!=0)
    {
        for(i=1;i<=no;i++)
        {
            if(need[i]>=ts)
            {
                for(j=1;j<=no;j++)
                {
                    if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
                    wt[j]+=ts;
                }
                need[i]-=ts;
                if(need[i]==0)
                {
                    flag[i]=0;
                    no--;
                }
            }
            else
            {
                for(j=1;j<=no;j++)
                {
                    if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
                    wt[j]+=need[i];
                }
                need[i]=0;
                no--;
                flag[i]=0;
            }
        }
    }
    for(i=1;i<=n1;i++)
    {
        tat[i]=wt[i]+bt[i];
        twt=twt+wt[i];
        ttat=ttat+tat[i];
    }
    awt=(float)twt/n1;
    atat=(float)ttat/n1;
    printf("\n\n Process \t Process ID  \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
    for(i=1;i<=n1;i++)
    {
        printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d \n", i,pid[i],bt[i],wt[i],tat[i]);
    }
    printf("\n The average Waiting Time=%f",awt);
    printf("\n The average Turn around Time=%f",atat);
}
