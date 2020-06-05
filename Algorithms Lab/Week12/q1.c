/*
ALGORITHM Backtrack(X[1..i])
//Gives a template of a generic backtracking algorithm
//Input: X[1..i] specifies first i promising components of a solution
//Output: All the tuples representing the problem’s solutions
if X[1..i] is a solution write X[1..i]
else
//see Problem 9 in this section’s exercises
for each element x ∈ S i+1 consistent with X[1..i] and the constraints do
X[i + 1] ← x
Backtrack(X[1..i + 1])
*/

#include <stdio.h>
#include <stdlib.h>
#define n 5
int S[10],d;

void backtrack(int i,int X[]){
	int sum=0;
	if(i>n){
		return;
	}
	for(int j=1;j<=i;j++){
		sum+=X[j];
	}
	
	if(sum==d){
		printf("\n");
		for(int j=1;j<=i;j++){
			printf("%d\t",X[j]);
				
		}
		printf("\n");
		return;
	}
	
	else{
		for(int j=i;j<n;j++){
			int flag=1;
			for(int k=0;k<=i;k++)
				if(X[k]==S[j]){
					flag=0;
					break;
				}
			if(flag==1)
				X[i+1]=S[j];
			backtrack(i+1,X);
		}
	}	

}

int main(){
	scanf("%d",&d);
	for(int i=0;i<n;i++)
		scanf("%d",&S[i]);
	int arr[n+1];
	backtrack(0,arr);
}

