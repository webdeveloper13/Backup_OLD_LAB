#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int knapsack(unsigned int *w,unsigned int *v,unsigned int n,unsigned int B)
{
	unsigned int i,temp;
	unsigned int maxVal=0,maxSequence=0;
	unsigned int totalWeight,totalValue;
	int opc=0;
	unsigned int index=0;

	for(i=1;i<pow(2,n);i++)
	{
		opc++;
		temp=i;
		totalWeight=totalValue=0;
		index=0;
		while(temp)
		{
			if(temp & 0x1)
			{
				totalWeight=totalWeight + w[index];
				totalValue=totalValue + v[index];
			}
			index++;
			temp=temp >> 1;
		}
	if(totalWeight <= B && totalValue > maxVal)
	{
		maxVal=totalValue;
		maxSequence=i;
	}
}
printf("\n opn count : %d\n",opc);
return maxSequence;
}

int main()
{
	unsigned int *v,*w,i,n,knaps,B;
	printf("enter the no. of ele: \n");
	scanf("%d",&n);
	v=(unsigned int*)calloc(n,sizeof(unsigned int));
	w=(unsigned int*)calloc(n,sizeof(unsigned int));
	printf("Please enter the weights : \n");
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	printf("Please enter the values : \n");
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	printf("Please enter the knapsack capacity : \n");
	scanf("%d",&B);
	knaps=knapsack(w,v,n,B);
	printf("Knapsack contains the following items \n");
	i=0;
	while(knaps)
	{
		if(knaps & 0x1)
			printf("item %u\t value %u\n",(i+1),v[i]);
		i++;
		knaps=knaps >> 1;
	}
	return 0;
}