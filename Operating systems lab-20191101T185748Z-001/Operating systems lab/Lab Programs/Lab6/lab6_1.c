
#include <stdio.h>
#include <stdlib.h>


struct PRO
{
	int pno;
	int arrival_time;
	int burst_time;
	int priority;
};

int main ()
{
	int p;
	int wait[p],turn[p],finish[p],avg_wait=0,avg_turn=0;
	finish[0]=0;

	printf("Enter the number of processes:");
	scanf("%d",&p);
	struct PRO process[p],temp;
	printf("Enter details: ");
	for(int i=0;i<p;i++)
	{
		printf("\nProcess P%d",i+1);
		process[i].pno=i+1;
		printf("\nArrival time: ");
		scanf("%d",&process[i].arrival_time);
		printf("Burst time: ");
		scanf("%d",&process[i].burst_time);
		printf("Priority: ");
		scanf("%d",&process[i].priority);

	}


	/*for(int i=0;i<p;i++)
		for(int j=0;j<p-i-1;j++)
			if(process[j].arrival_time>process[j+1].arrival_time)
			{
				temp=process[j];
				process[j]=process[j+1];
				process[j+1]=temp;
			}*/

	
	for(int i=0;i<p;i++)
	{
		int j=i-1;
		wait[i]=0;

		finish[i]=process[i].burst_time+finish[i-1];
		
		
		while(j>=0)
		{
			wait[i]+=process[j].burst_time;
			j--;
		}
		
		wait[i]-=process[i].arrival_time;
		avg_wait+=wait[i];
		turn[i]=process[i].burst_time+wait[i];
		avg_turn+=turn[i];
	}

	avg_wait/=p;
	avg_turn/=p;

	printf("Entered processes:");
	printf("\nProcess\t Arrival time\t Burst time\t Priority\t Finish Time\t Turn around time\t Waiting time");
	for(int i=0;i<p;i++)
		printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",process[i].pno,process[i].arrival_time,process[i].burst_time,process[i].priority,finish[i],turn[i],wait[i]);
	printf("\nAverage waiting time= %d",avg_wait);
	printf("\nAverage turnaround time= %d\n",avg_turn);
	return 0;
}