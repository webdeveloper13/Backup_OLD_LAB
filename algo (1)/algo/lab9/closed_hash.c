#include<stdio.h>
#include<stdlib.h>

void print_hash(int **arr,int n)
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	int n;
	printf("Enter the size of hash table:");scanf("%d",&n);
	int m;
	printf("Enter number of elements to be hashed:(<=%d)",n);scanf("%d",&m);
	int *arr=(int*)calloc(m,sizeof(int));
	printf("Enter array elements\n");
	for(int i=0;i<m;i++)
		scanf("%d",&arr[i]);
	int **list=(int**)calloc(2,sizeof(int));
	for(int i=0;i<2;i++)
		list[i]=(int*)calloc(n,sizeof(int));
	int ele;
	for(int i=0;i<n;i++)
	{
		list[0][i]=i;
	}
	for(int i=0;i<n;i++)
	{
		list[1][i]=-1;
	}
	int f=0;
	for(int i=0;i<m;i++)
	{
		ele=arr[i]%n;
		if(list[1][ele]!=-1)
		{
			int j=1;
			while((j!=n)&&(list[1][ele+j]!=-1))
			{
				j++;
			}
			if(j==n)
			{
				f=1;printf("\n%d ",j);
				printf("\nCannot accept more elements to be hashed\n");
				break;
			}
			else
			{
				list[1][(ele+j)%n]=arr[i];
			}
		}
		else
			list[1][ele]=arr[i];
	}
	print_hash(list,n);


}