#include <stdio.h>
#include <stdlib.h>
#define max 10

int sorted[max];

void merge(int *,int *,int *,int,int);

void mergesort(int arr[],int n){
	if(n>1){
		int n1=n/2;
		int n2=n-n1;
		int i;
		int arr1[max],arr2[max];
		
		for(i=0;i<n1;i++){
			arr1[i]=arr[i];
		}
		
		for(int j=0;j<n2;j++,i++){
			arr2[j]=arr[i];
		}

		

		mergesort(arr1,n1);
		mergesort(arr2,n2);
		merge(sorted,arr1,arr2,n1,n2);

	}
}

void merge(int arr[],int arr1[],int arr2[],int n1,int n2){
	int i=0,j=0,k=0;

	printf("\n");
		for(i=0;i<n1;i++)
			printf("%d\t",arr1[i]);
		printf("\n");
		for(i=0;i<n2;i++)
			printf("%d\t",arr2[i]);
	i=0;	
	while(j<n1 && k<n2){
		if(arr1[j]<arr2[k]){
			arr[++i]=arr1[j++];
		}
		else
			arr[++i]=arr2[k++];	
	}

	while(j<n1){
		arr[++i]=arr1[j++];
	}

	while(k<n2){
		arr[++i]=arr2[k++];
	}

	//printf("\nSorted array:\n");
	//for(i=0;i<n1+n2;i++)
	//	printf("%d\t",arr[i]);
}

int main(){
	int n,arr[max];
	printf("Enter size:");
	scanf("%d",&n);
	printf("Enter array:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	mergesort(arr,n);
	
}