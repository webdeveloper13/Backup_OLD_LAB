#include<stdio.h>

int a[50][50], t[50][50], root[50], parent[50];
int n, i, j, value, e=0, k=0;
int ivalue, jvalue, cost=0, mincost=0, TV[50], count=0, present=0;

void read_cost(){
	printf("\nEnter # vertices: ");
	scanf("%d", &n);
	printf("\nEnter cost of Adj. Mat:\n");
	for(i=1;i<=n;i++)
		for(j=1; j<=n; j++){
			if(i<j){
				printf("(%d, %d):", i, j);
				scanf("%d", &value);
				a[i][j]=value;
				if(value) e++;
			}
			else if(i>j) a[i][j]=a[j][i];
			else a[i][j]=0;				
		}		
}

int check_reach(int v){
	int p;
	for(p=1; p<=count; p++)
		if(TV[p]==v) return 1;
	return 0;
}

void prims(){
	while(e && k<n-1){
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++){
				if(a[i][j]){
					int x,y;
					x=check_reach(i);
					y=check_reach(j);
					if((x==1) && (y==0)){
						present=1;
						if((a[i][j]<cost)|| (cost==0)){
							cost=a[i][j];
							ivalue=i;
							jvalue=j;
						}
					}
				}
			}
		if(present==0)break;
		a[ivalue][jvalue]=0;
		a[jvalue][ivalue]=0;
		e--;
		TV[++count]=jvalue;
		t[ivalue][jvalue]=cost;
		k++;
		present=cost=0;	
	}
}

void display(){
	if(k==n-1){
		printf("\nMin. Cost Spanning Tree:\n");
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++){
				if(t[i][j])
					printf("\n(%d, %d): %d", i, j, t[i][j]);
				mincost+=t[i][j];
			}
		printf("\n\nCost of Spanning Tree is: %d\n\n", mincost);	
	}
	else
		printf("\n\nGraph is not connected\n\n");
}

void main(){
	printf("\n\t\t\t PRIMS ALGORITHM\n");
	TV[++count]=1;
	read_cost();
	prims();
	display();
}

