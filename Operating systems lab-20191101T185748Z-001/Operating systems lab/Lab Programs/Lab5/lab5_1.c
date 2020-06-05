#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int res[30],upper;


void *fibo(void *param)
{
	int i=0,j=1,k,l=2;
	upper=atoi(param);
	res[0]=i;
	if(upper==0)
		return 0;
	res[1]=j;
	if(upper==1)
		return 0;
	else
	{
		while(l<=upper)
		{
			k=i+j;
			i=j;
			j=k;
			res[l]=k;
			l++;
		}
	}

}

int main (int argc, char *argv[])
{
	pthread_t thread;
	pthread_attr_t attr;
	pthread_attr_init (&attr);
	pthread_create (&thread, &attr, fibo, argv[1]);
	pthread_join (thread, NULL);
	for(int i=0; i<upper; i++)
		printf("%d ",res[i]);
}


