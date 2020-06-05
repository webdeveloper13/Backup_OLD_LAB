

#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void swap (int *x, int *y) 
{
	int t = *x;
	*x = *y;
	*y = t;
}

void arrange (int arr[], int end) 
{
	while (end > 1)
	{
		int p = end / 2;
		if (arr[p] < arr[end]) 
		{
			swap (arr + p, arr + end);
			end = p;
		} 
		else 
			return;
		opcount++;
	}
}


void heapify (int arr[], int n) 
{
	int end = 1;
	while (end <= n) 
	{
		arrange (arr, end);
		end += 1;
	}
}

void main ()
{
	int h[100], n;
	printf ("Enter number of elements: ");
	scanf ("%d", &n);

	printf ("\nEnter elements: ");
	for (int i = 1; i <= n; i++)
		scanf ("%d", &h[i]);

	printf ("\nArray: \n");
	for (int i = 1; i <= n; i++)
		printf("%d ", h[i]);

	heapify (h, n);

	printf ("\n\nHeap: \n");
	for (int i = 1; i <= n; i++)
		printf ("%d ", h[i]);

	printf ("\n");
	printf("opcount = %d\n", opcount);
}
