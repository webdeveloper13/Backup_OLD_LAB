#include <stdio.h>
#define MAX 1000

struct PRO
{
	int pno,at,bt,ft,tat,wt;
};

int least_of(int *array,int n){
	int small=0;
	for(int i=1;i<n;i++)
		if(array[i]<array[small])
			small=i;
	return small;
}

int do_the_job(struct PRO *process,int *btdup,int processes_arrived,int *processes_done,int *time_counter,int *gantt_pro,int *gantt_time,int *gantt_counter,int *time_total){
	if(processes_arrived==*processes_done){
		(*time_counter)++;
		(*time_total)++;
		return 0;
	}
	int i=least_of(btdup,processes_arrived);
	btdup[i]--;
	if(btdup[i]==0){
		process[i].ft=(*time_counter)+1;
		btdup[i]=MAX;
		(*processes_done)++;
	}
	gantt_pro[*gantt_counter]=i+1;
	gantt_time[*gantt_counter]=*time_counter;
	(*gantt_counter)++;
	(*time_counter)++;
	return i;
}

int strf(struct PRO *process,int *gantt_pro,int * gantt_time,int *gantt_counter,int *time_counter){
	int i,ch,ch1,processes_arrived=0,processes_done=0,time_total=0,prev;
	int btdup[MAX]; 
	do{
		printf("\nTime: %dms\n",*time_counter);
		do{
			printf("Any process arriving?\n1.Yes  2.No\nEnter choice:");
			scanf("%d",&ch);
			if(ch==1){
				process[processes_arrived].pno=processes_arrived;
				printf("Enter bt:");
				process[processes_arrived].at=*time_counter;
				scanf("%d",&process[processes_arrived].bt);
				btdup[processes_arrived]=process[processes_arrived].bt;
				time_total+=process[processes_arrived].bt;
				processes_arrived++;
			}
		}while(ch==1);
		do_the_job(process,btdup,processes_arrived,&processes_done,time_counter,gantt_pro,gantt_time,gantt_counter,&time_total);
		printf("\nHave all the processes arrived?If no press 3: ");	
		scanf("%d",&ch1);
	}while(ch1==3);

	while(*time_counter<time_total){
		prev=do_the_job(process,btdup,processes_arrived,&processes_done,time_counter,gantt_pro,gantt_time,gantt_counter,&time_total);
	}
	
	gantt_pro[*gantt_counter]=prev+1;
	gantt_time[*gantt_counter]=*time_counter;
	return processes_arrived;
}

int main(){
	printf("\nSHORTEST TIME REMAINING FIRST\n\n");
	struct PRO process[MAX];
	float avg_tat=0,avg_wt=0;
	int gantt_pro[MAX],gantt_time[MAX],gantt_counter=0,time_counter=0,i;
	int n_processes=strf(process,gantt_pro,gantt_time,&gantt_counter,&time_counter);

	printf("\n\n\n\nGantt chart:\n");
	printf("\nStart:\nProcess:%d Time:%d   ",gantt_pro[0],gantt_time[0]);
	for(i=1;i<gantt_counter;i++){
		if(gantt_pro[i]!=gantt_pro[i-1])
			printf("\nProcess:%d Time:%d",gantt_pro[i],gantt_time[i]);
	}
	printf("\nEnd Time:%d",time_counter);

	printf("\n\nP\tAT\tBT\tFT\tTAT\tWT\n");
	for(int i=0;i<n_processes;i++){
		process[i].tat=process[i].ft-process[i].at;
		process[i].wt=process[i].tat-process[i].bt;
		avg_tat+=process[i].tat;
		avg_wt+=process[i].wt;
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",process[i].pno,process[i].at,process[i].bt,process[i].ft,process[i].tat,process[i].wt);
	}
	avg_tat/=n_processes;
	avg_wt/=n_processes;
	printf("\nAvg TAT=%f  Avg WT=%f\n",avg_tat,avg_wt);
}