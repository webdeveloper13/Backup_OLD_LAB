#include <stdio.h>
#include <stdlib.h>
void insertionSort(int *a,unsigned int n)
{
	int i,j,v;
	int opcount=0;
	for(i=1;i<n;i++)
	{
		v=a[i];
		j=i-1;
		while(++opcount && j>=0 && a[j]>v)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=v;

	}
	printf("\nOperation count %d\n",opcount);

}
int main(int argc, char const *argv[])
{
	int *a;
	int i,n=5;
	for(int j=0;j<4;j++)
	{
		a=(int *)malloc(sizeof(int)*n);
		for(int k=0;k<n;k++)
			a[k]=n-k;
		printf("Elements are\n");
		for(int i=0;i<n;i++)
			printf("%d\n",a[i]);
		insertionSort(a,n);
		printf("Elements after selection sort\n");
		for(i=0;i<n;i++)
			printf("%d\n",a[i]);
		free(a);
		n=n+5;
	}
	
	return 0;
}