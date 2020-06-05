#include<stdio.h>
#include<stdlib.h>

void sort(int a[20], int m, int x)
{
	for(int i=0; i<m; i++)
		for(int j=i+1; j<m; j++)
			if((a[i]>a[j] && x==0)||(a[i]<a[j] && x==1))
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}

void firstFit(int par[20], int m, int pro[20], int n, int x)
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			if(pro[i]<par[j])
			{
				printf("Process %d(%d) placed in partion of size %d.\n", i+1, pro[i], par[j]);
				par[j] = par[j]-pro[i];
				if(x==1)
					sort(par, m, 0);
				else if(x==2)
					sort(par, m, 1);
				break;
			}
		}
		if(j==m)
			printf("No partion found for process %d(%d).\n", i+1, pro[i]);
	}
}

void bestFit(int par[20], int m, int pro[20], int n)
{
	sort(par, m, 0);
	firstFit(par, m, pro, n, 1);
}

void worstFit(int par[20], int m, int pro[20], int n)
{
	sort(par, m, 1);
	firstFit(par, m, pro, n, 2);
}

int main()
{
	int par1[20], par2[20], par3[20], m = 0, pro[20], n = 0;
	printf("Enter the partions in order(-1 to exit):\n");
	while(1)
	{
		scanf("%d", &par1[m]);
		if(par1[m]==-1)
			break;
		par3[m] = par2[m] = par1[m];
		m++;
	}
	printf("Enter the processes in order(-1 to exit):\n");
	while(1)
	{
		scanf("%d", &pro[n]);
		if(pro[n]==-1)
			break;
		n++;
	}
	printf("First fit:\n");
	firstFit(par1, m, pro, n, 0);
	printf("\nBest fit:\n");
	bestFit(par2, m, pro, n);
	printf("\nWorst fit:\n");
	worstFit(par3, m, pro, n);
}