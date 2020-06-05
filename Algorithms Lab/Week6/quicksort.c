#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define max 10

int arr[max+1]; int n;

int part(int l,int r){
	int p=arr[l];
	int i=l,j=r+1;
	do{
		do{
			i++;
		}while(arr[i]<p);
		
		do{
			j--;
		}while(arr[j]>p);
		
		int t=arr[i];
		arr[i]=arr[j];
		arr[j]=t;
	}while(i<j);
	
	int t=arr[i];
	arr[i]=arr[j];
	arr[j]=t;

	t=arr[l];
	arr[l]=arr[j];
	arr[j]=t;
	printf("\n%d",j);
	return j;

}

void quicksort(int l,int r){
	if(l<r){
		printf("%d %d",l,r);
		int s=part(l,r);
		quicksort(l,s-1);
		quicksort(s,r);
	}
	return;
}




int main(){
	
	printf("Enter size:");
	scanf("%d",&n);
	printf("Enter array:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	arr[n+1]=INT_MAX;
	quicksort(0,n-1);
	printf("Sorted array:\n");
	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("Sorted array:\n");
	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);

	
}
