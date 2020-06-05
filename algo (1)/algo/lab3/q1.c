#include<stdio.h>
#include<stdlib.h>

void bubble(int arr[],int n){

	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){

			if(arr[j]>arr[j+1]){
				int temp;
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}

		}
	}

	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}

}

int main(int argc, char const *argv[])
{
	int n;
	int t;
	printf("Enter the number of test cases\n");
	scanf("%d",&t);
	for(int i=0;i<t;i++){
	printf("Enter the number of elements in the Array\n");
	scanf("%d",&n);
	printf("Enter the Array elements\n");
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	printf("Unsorted array is\n");

	for(int i=0;i<n;i++){
	printf("%d\t",arr[i]);
	}

	printf("\n");

	printf("Sorted array is\n");

	bubble(arr,n);

	printf("\n");

}




	return 0;
}