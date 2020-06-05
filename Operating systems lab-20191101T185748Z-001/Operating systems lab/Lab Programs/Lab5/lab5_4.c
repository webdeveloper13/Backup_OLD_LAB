#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int l,arr[20],esum=0,osum=0;

void *calcsum (void *param)
{
	int lim;
	lim=l;
	printf("Input an array: \n");
	for(int i=0;i<lim;i++)
		scanf("%d",&arr[i]);

	for(int i=0;i<l;i++)
	{
		if(arr[i]%2==0)
			esum+=arr[i];
		else
			osum+=arr[i];

	}

	


}

int main (int argc, char *argv[])
{
	pthread_t thread;
	pthread_attr_t attr;
	pthread_attr_init (&attr);
	l=atoi(argv[1]);
	pthread_create (&thread, &attr, calcsum, argv[1]);
	pthread_join (thread, NULL);
	printf("Even Sum: %d ",esum);
	printf("Odd Sum: %d ",osum);
	printf("\n");
	

}
