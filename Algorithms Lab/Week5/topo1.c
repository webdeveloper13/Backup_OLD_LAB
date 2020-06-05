#include<stdio.h>
#include<stdlib.h>
#define length 6

int matrix[length][length]={0};
int visited[length];
char pop[length];
int ind=0;

void dispmat(int mat[][length]){
	printf("\n\t");
	for(int i=0;i<length;i++)
		printf("%c\t",'a'+i);
	printf("\n");
	printf("\n");
	for(int i=0;i<length;i++){
		printf("%c\t",'a'+i);
		for(int j=0;j<length;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
}


void addEdgemat(int matrix[][length],char x,char y){
	matrix[x-'a'][y-'a']=1;
}

void DFS(int i)
{	
    int j;
    //printf("%c ",i+'a');
    visited[i]=1;
    
    for(j=0;j<length;j++)
       if(!visited[j]&&matrix[i][j]==1){
            DFS(j);
            
            //printf("\nPop %c",i+'a');

       }
    pop[ind++]=i+'a';   
}



void Sort(){
	for(int i=0;i<length;i++)
		if(visited[i]==0)
			DFS(i);
	printf("\nDFS:\t");
	for(int i=length;i>=0;i--)
		printf("%c\t",pop[i]);
	printf("\n");

}

void Sort2(){
	printf("\nSource removal:\t");
	int i,j,removed=0;
	int rem[length]={0};
	for(i=0;i<length;i++){
		if(rem[i]==1)
			continue;
		for(j=0;j<length;j++){
			if(matrix[j][i]==1)
				break;
		}
		if(j==length){
			printf("%c\t",'a'+i);
			for(j=0;j<length;j++)
				matrix[i][j]=0;
			removed++;
			rem[i]=1;
		}
		if(removed<length)
			i=0;	
	}	

}


int main(){
	int ch=0;
	while(ch!=3){
		printf("\n1:Add edge\n2:Sort\n3:Exit\nEnter choice:");
		scanf("%d",&ch);
		if(ch==1){
			char x[2],y[2];
			printf("Enter edge to add:\n");
			scanf("%s",x);
			scanf("%s",y);
			
			addEdgemat(matrix,x[0],y[0]);
		}
		if(ch==2){
			Sort();
			Sort2();
			
		}
	}
return 0;	
}