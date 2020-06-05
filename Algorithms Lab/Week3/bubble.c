#include<stdio.h>
#define max 20

int bubblesort(int arr[],int size){
	int opcount=0;
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-1-i;j++){
			opcount++;
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}	
	return opcount;
}

void disp(int arr[],int size){
	printf("\n");
	for(int i=0;i<size;i++)
		printf("%d\t",arr[i]);
}

int main(){
	int size,arr[max];
	printf("Enter size:");
	scanf("%d",&size);
	printf("Enter array:\n");
	for(int i=0;i<size;i++)
		scanf("%d",&arr[i]);
	int opcount=bubblesort(arr,size);
	disp(arr,size);
	printf("\nOpcount:%d\n",opcount);
	return 0;
}