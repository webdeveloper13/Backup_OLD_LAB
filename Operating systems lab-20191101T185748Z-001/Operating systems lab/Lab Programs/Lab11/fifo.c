#include<stdio.h>
#include<stdlib.h>
void main ()
{
	int p;
	printf("Enter page size");
	scanf("%d",&p);
	int a[p],count=0,n,marker=0,flag;
	for(int i=0;i<p;i++)
		a[i]=-1;
	do{
		flag=0;
		printf("\nEnter page numbers (-1 to stop):");
		scanf("%d",&n);
		for(int i=0;i<p;i++)
			if(a[i]==n)
			{
				flag=1;
				printf("Page found at position %d",i+1);
				break;
			}
		if( (!flag) && (n!=-1) )
		{
			a[marker]=n;
			count++;
			marker+=1;
			if(marker==p)
				marker=0;
			for(int i=0;i<p;i++)
				printf("%d ",a[i]);
		}

	}while(n!=-1);
	printf("Total page faults= %d\n",count);
}