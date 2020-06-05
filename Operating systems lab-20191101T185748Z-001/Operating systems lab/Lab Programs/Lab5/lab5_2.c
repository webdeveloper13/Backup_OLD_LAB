#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int sum;

void *summer (void * param)
{
	int upper=atoi(param);
	int i;
	sum=0;
	for(i=1;i<=upper;i++)
	{
		sum+=i;
		printf("\nSum after %d iteration: %d",i,sum);
	}
	pthread_exit(0);
}

int main (int argc, char *argv[])
{
	pthread_t thread;
	int n;
	//pthread_attr_t attr;
	//pthread_attr_init (&attr);
	printf("Enter the number\n");
	scanf("%d",&n);
	pthread_create (&thread,0,&summer,argv[1]);
	pthread_join (thread, NULL);
	printf("\n Final Sum is: %d \n",sum);
	return 0;
}