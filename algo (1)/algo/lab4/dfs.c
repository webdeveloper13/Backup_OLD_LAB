#include<stdio.h>
 
void DFS(int);
int G[10][10],visited[10],n,c;
 
void main()
{
    int i,j;
    printf("Enter number of vertices:");
   
	scanf("%d",&n);
 
	printf("\nEnter adjecency matrix of the graph:");
   
	for(i=0;i<n;i++)
       for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
 
   for(i=0;i<n;i++)
        visited[i]=0;
 
    DFS(0);
    printf("\n");
}
 
void DFS(int i)
{
    int j;
    c++;
    visited[i]=c;
    printf("pushing %d \n",i);

	for(j=0;j<n;j++)
       if(!visited[j] && G[i][j]==1)
            DFS(j);
       printf("pushing %d \n",i);
}
