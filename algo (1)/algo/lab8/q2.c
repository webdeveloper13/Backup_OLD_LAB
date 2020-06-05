

#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void swap (int *x, int *y) 
{
    int t = *x;
    *x = *y;
    *y = t;
}


void heapify (int h[], int n)
{
    int i, k, v, heapify, j;
    for (i = (n / 2); i >= 1; i--)
    {
        k = i;
        v = h[k];
        heapify = 0;

        while (heapify == 0 && 2 * k <= n)
        {
            j = 2 * k;
            if (j < n)
            {
                if (h[j] < h[j + 1])
                    j = j + 1;
            }
            if (v >= h[j])
                heapify = 1;
            else
            {
                h[k] = h[j];
                k = j;
            }
            opcount++;
        }
        h[k] = v;
    }
    return;
}

void heapSort (int arr[], int n) 
{
    heapify (arr, n);
    int end = n;

    while (end > 1)
    {
        swap (arr + end, arr + 1);
        end -= 1;
        heapify (arr, end);
    }
}

void main ()
{
    int h[100], n;
    printf ("Enter number of elements: \n");
    scanf ("%d", &n);

    printf ("Enter elements: \n");
    for (int i = 1; i <= n; i++)
        scanf ("%d", &h[i]);

    printf ("\nArray: \n");
    for (int i = 1; i <= n; i++)              
        printf("%d ", h[i]);

    heapSort (h, n);

    printf ("\n\nSorted: \n");
    for (int i = 1; i <= n; i++)
        printf ("%d ", h[i]);

    printf ("\n");
    printf("opcount = %d\n", opcount);
}
