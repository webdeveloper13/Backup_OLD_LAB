#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
 
void printArr(int a[],int n)
{
    for (int i=0; i<n; i++)
        printf("%d  ",(a[i]+1));
    printf("\n");
}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void heapPermutation(int * smallest_sum,int size,int b[],int a[],int n,int matrix[][n])
{
    if (size == 1)
    {        
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + matrix[i][a[i]];
        }
        if(sum< *(smallest_sum)){
            *(smallest_sum) = sum;
            for(int i=0;i<n;i++)
                b[i] = a[i];
        }
        return;
    }
 
    for (int i=0; i<size; i++)
    {
        heapPermutation(smallest_sum,size-1,b,a,n,matrix);
        if (size%2==1)
            swap(&a[0], &a[size-1]);
        else
            swap(&a[i], &a[size-1]);
    }
}
 
int main()
{
    int j,p;
    printf("Please enter number of jobs and number of people\n");
    scanf("%d %d",&j,&p);
    int matrix[p][j];
    printf("Please enter values into the matrix\n");
    for(int i=0;i<p;i++){
        for(int k=0;k<j;k++){
            scanf("%d",&matrix[i][k]);
        }
    }
    int b[j];
    int a[j];
    for(int i=0;i<j;i++){
        a[i] = i;
    }
    int smallest_sum = INT_MAX;
    heapPermutation(&smallest_sum,j, b,a,j,matrix);
    printf("\n%d\n",smallest_sum);
    printArr(b,j);
    return 0;
}