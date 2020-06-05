#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int lim, i, j, k, l, nos, arr[100], s1[100], s2[100], sum = 0, ss1 = 0, ss2 = 0;
	printf("Enter the array limit : \n");
	scanf("%d", &lim);
	printf("Enter the elements : ");
	for(i = 0; i < lim; ++i){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	if(sum%2 == 1 || lim == 0){
		printf("Partition not possible...\n");
		return 0;
	}
	
	nos = pow(2,lim);
	for(i = 1; i < nos; ++i){
		ss1 = 0; ss2 = 0; k = -1; l = -1;
		for(j = 0; j < lim; ++j){
			if(i & (1 << j)){
				ss1 += arr[j];
				s1[++k] = arr[j];
				printf("ss1 %d ", arr[j]);
			}
			else{
				ss2 += arr[j]; 
				s2[++l] = arr[j];
				printf("ss2 %d ", arr[j]);
			}
		}
		printf("\n");
		if(ss1 == ss2 && ss1 == sum/2){
			printf("Partition possible! Sum is %d\n", sum);
			printf("Subset 1 : \n");
			for(int i = 0; i <= k; ++i){
				printf("%d ", s1[i]);
			}
			printf("\nSubset 2 : \n");
			for(int i = 0; i <= l; ++i){
				printf("%d ", s2[i]);
			}
			printf("\n");
			return 0;
		}
	}
	return 0;
}
