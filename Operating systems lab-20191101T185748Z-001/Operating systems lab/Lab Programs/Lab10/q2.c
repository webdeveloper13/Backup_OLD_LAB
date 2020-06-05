#include<stdio.h>
#include<stdlib.h>

void dec2bin(int c, int n)
{
	int x[10];
	for(int i=0; i<n; i++)
	{
		x[i] = c%2;
		c = c/2;
	}
	for(int i = n-1; i>=0; i--)
		printf("%d", x[i]);
}

int main()
{
	int la, pn, po;
	printf("Enter the local memory address\n");
	scanf("%d", &la);
	pn = la / 32;
	po = la % 32;
	printf("The page number is %d ", pn);
	dec2bin(pn, 3);
	printf("\nThe page offset is %d ", po);
	dec2bin(po, 5);
}