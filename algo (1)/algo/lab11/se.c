#include <stdio.h>
#include <stdlib.h>

int a[50][50],t[50][50],root[50],parent[50],n,i,j,value,e=0,k=0;
int ivalue,jvalue,cost=0,mincost=0,TV[50],count=0,present=0;
int main(int argc, char const *argv[])
{
	printf("\n\t\t\t PRIMS ALGORITHM\n");
	TV[++count]=1;
	read_cost();
	prims();
	display();
	//getch();

	return 0;
}
read_cost()
{
	printf("\nEnter the number of vertices");
	scanf("%d",&n);
	printf("\nEnter cost adjacency matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;)
}