#include <stdio.h>
#include <stdlib.h>

void compTransitiveClosure(int n, int arr[][n]){

	int opcount = 0;
	int trans_arr[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			trans_arr[i][j] = arr[i][j];
		}
	}

	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				opcount++;
				trans_arr[i][j] = trans_arr[i][j] || trans_arr[i][k] && trans_arr[k][j];
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d\t", trans_arr[i][j]);
		}
		printf("\n");
	}

	printf("\nOpcount = %d\n", opcount);
}

int main(int argc, char const *argv[])
{
	int n;
	printf("\nEnter the number of nodes: ");
	scanf("%d", &n);

	int arr[n][n];
	printf("Enter the adjacency matrix: ");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			scanf("%d", &arr[i][j]);
	}

	compTransitiveClosure(n, arr);

	return 0;
}