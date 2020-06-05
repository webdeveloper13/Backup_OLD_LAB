#include <stdio.h>
#include <stdlib.h>

int weight[10], value[10];
int mat[100][100];
int knapsack_val;

int max(int a, int b){
	return a>b?a:b;
}

int knapsack(int items, int wgt)
{
	for(int i=0;i<=items;i++)
	{
		for(int j=0;j<=wgt;j++)
		{
			if(i==0 || j==0)
			{
				mat[i][j]=0;
				continue;
			}
			mat[i][j]=mat[i-1][j];
			if(j>=weight[i-1])
			{
				mat[i][j]=max(mat[i][j],mat[i-1][j-weight[i-1]]+value[i-1]);
			}
		}
	}	
	return mat[items][wgt];
}

int main(){

	int wgt, items;
	int i,j;
	printf("\nEnter Total Knapsack Capacity: ");
	scanf("%d",&wgt);
	printf("\nEnter number of items: ");
	scanf("%d",&items);
	for(i=0;i<items;i++){
		printf("\nEnter weight of item %d: ",i);
		scanf("%d",&weight[i]);
		printf("\nEnter value of item %d: ",i);
		scanf("%d",&value[i]);
		printf("\n");
	}
	
	int result = knapsack(items,wgt);
	printf("\nFinal Knapsack Value = %d\n",result);
	return 0;
}