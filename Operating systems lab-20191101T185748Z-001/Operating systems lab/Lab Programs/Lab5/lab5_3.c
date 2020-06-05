#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr[15],k,s,e;

void *prime (void *param)
{
	int flag,i,start,end;
	start=s;
	end=e;
	k=0;
	for(i=start;i<=end;i++)
	{
		flag=0;
		for(int j=2;j<= sqrt(i) ;j++)
		{
			if((i%j)==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			arr[k++]=i;
	}
}

int main (int argc, char *argv[])
{
	pthread_t thread;
	pthread_attr_t attr;
	pthread_attr_init (&attr);
	s=atoi(argv[1]);
	e=atoi(argv[2]);
	pthread_create (&thread, &attr, prime, argv[1]);
	pthread_join (thread, NULL);
	for(int i=0; i<k; i++)
		printf("%d ",arr[i]);
	printf("\n");

}
