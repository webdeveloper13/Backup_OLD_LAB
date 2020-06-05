#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 5

void disp(int ps[][max+2],int size){
	for(int i=0;i<pow(2,size);i++){
		printf("\n");
		for(int j=0;j<=ps[i][0]+1;j++)
			printf("%d\t",ps[i][j]);
	}
}

void genpowset(int *set,int size,int ps[][max+2]){
	int powsetsize=pow(2,size);
	for(int i=0;i<powsetsize;i++)
		ps[i][0]=ps[i][1]=0;
	//disp(ps,size);
	for(int i=0;i<powsetsize;i++){
		for(int j=0,k=1;j<size;j++){
			if(i & (1<<j)){
				//printf("%d\t",set[j]);
				ps[i][0]++;
				ps[i][1]+=set[j];
				ps[i][++k]=set[j];
			}
		}
		//printf("\n");

	}
	//disp(ps,size);
}

void disp2(int *set1,int *set2){
	printf("\nSet 1:\t");
	for(int i=2;i-1<=set1[0];i++)
		printf("%d\t",set1[i]);
	printf("\nSet 2:\t");
	for(int i=2;i-1<=set2[0];i++)
		printf("%d\t",set2[i]);
	printf("\n\n\n\n");
}


void partition(int *set,int size){
	int ps[(int)pow(2,max)][max+2];
	genpowset(set,size,ps);
	//disp(ps,size);
	for(int i=0;i<pow(2,size)-1;i++)
		for(int j=i+1;j<pow(2,size);j++)
			if(ps[i][1]==ps[j][1])
				disp2(ps[i],ps[j]);
}


int main(){
	int arr[max],size;
	printf("Enter size:");
	scanf("%d",&size);
	printf("Enter elements:");
	for(int i=0;i<size;i++)
		scanf("%d",&arr[i]);
	partition(arr,size);
	return 0;
}