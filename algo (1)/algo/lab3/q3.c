#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSubsetSum(int arr[],int n,int psum){
	if(psum==0){
		return true;
	}

	if(n==0 && psum!=0){
		return false;
	}

	if(arr[n-1]>psum){
		return isSubsetSum(arr,n-1,psum);
	}


	return isSubsetSum(arr,n-1,psum)||isSubsetSum(arr,n-1,psum-arr[n-1]);


}



bool findPartition(int arr[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum=sum+arr[i];
	}

	if(sum%2!=0){

		return false;
	}

	return isSubsetSum(arr,n,sum/2);
}



int main(int argc, char const *argv[])
{
	int t;
	printf("Enter the number of test cases\n");
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;
		printf("Enter the number of elements\n");
		scanf("%d",&n);
		int arr[n];
		printf("Enter the array elements\n");
		for (int i = 0; i <n ; ++i)
		{
			scanf("%d",&arr[i]);
		}

		printf("Your array is\n");
		for (int i = 0; i <n ; ++i)
		{
			printf("%d\t",arr[i]);
		}

		printf("\n");

		if(findPartition(arr,n)){
			printf("The array can be divivded into two subsets of equal sums\n");
		}

		else{
			printf("Cannot be divided into subsets of equal sums\n");
		}



}
	return 0;
}