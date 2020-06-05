#include<stdio.h>
#include<stdlib.h>
int c[20][20];
int min(int a,int b){
	if(a<b){
		return a;
	}

	return b;
}
void binomial(int n,int k){
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=min(i,k);j++)
		{
			if(j==0||j==i)
				c[i][j]=1;

			else
				c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
}



int main(int argc, char const *argv[])
{
	int n,k;
	int i,j;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	printf("Enter the value of k\n");
	scanf("%d",&k);
	if(n<k||k<0){
		printf("Invalid values\n");
	}
	else{

		binomial(n,k);
		printf("Computed matrix is\n");
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=min(i,k);j++)
				printf("%d\t",c[i][j]);
			printf("\n");

		}
		printf("binomial coefficient c[%d %d]=%d\n",n,k,c[n][k]);

	}
	return 0;
}