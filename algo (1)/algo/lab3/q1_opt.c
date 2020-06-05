#include <stdio.h>
#include <stdlib.h>
int opcount;
void b_sort(int a[],int n)
{
	int swap=0;
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swap=1;
			}
			opcount++;
		}
		if(swap==0)
			break;
	}
}
int main()
{
	int n,i;
	printf("enter n:");
	scanf("%d",&n);
	int a[n];
	printf("enter elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	b_sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n%d",opcount);
}