#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 7

void partition(int *set,int size){
	int powsetsize=pow(2,size);
	int sum=0;
	for(int i=0;i<size;i++)
		sum+=set[i];
	
	if(sum%2==1){
		printf("\nNo solution\n");
		return;
	}
	

	for(int i=0;i<powsetsize;i++){
		int arr[max],k=0,sum2=0,arr2[max],l=0;
		for(int j=0;j<size;j++){
			if(i & (1<<j)){
				arr[k++]=set[j];
				sum2+=set[j];
			}
			else
				arr2[l++]=set[j];
		}
		if(sum2==sum/2){
			printf("\n\n");
			printf("\nSet 1:");
			for(int x=0;x<k;x++)
				printf("%d\t",arr[x]);
			printf("\nSet 2:");
			for(int x=0;x<l;x++)
				printf("%d\t",arr2[x]);
		}
			

	}
		
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
