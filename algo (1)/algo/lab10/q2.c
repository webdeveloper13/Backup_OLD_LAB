#include<stdio.h>
int V,opcount=0;
#define INF 99999

void printSolution(int dist[][V]);
void floydWarshall (int graph[][V]) {
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    } 
   
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++)
            {
              opcount++;
              if(dist[i][k]+dist[k][j]<dist[i][j])
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
        //printSolution(dist);
    }
    printSolution(dist);
}
void printSolution(int dist[][V]) {
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
} 

int main()
{
  printf("Enter no. of vertices: \n");
  scanf("%d",&V);
  int graph[V][V];
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
     graph[i][j] = INF;
    }
  }

  printf("Enter you adjacency matrix: (99999 for infinite distance)\n");
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      scanf("%d",&graph[i][j]);
    }
  }
  floydWarshall(graph);
  printf("opcount - %d\n",opcount);
  return 0;
}

/*
Enter no. of vertices: 
4
Enter you adjacency matrix: (99999 for infinite distance)
0 99999 3 99999
2 0 99999 99999
99999 7 0 1
6 99999 99999 0
Following matrix shows the shortest distances between every pair of vertices 
      0     10      3      4
      2      0      5      6
      7      7      0      1
      6     16      9      0
opcount - 64

*/
