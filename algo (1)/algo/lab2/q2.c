#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))



int calculatePrime(int m,int n){

	
	int j=0;
	int pro=1;
	int i=2;
	int min;
	if(m<n)
		min=m;
	else
		min=n;
	while(i<=min)
	{
	   if(m%i==0&&n%i==0)
	   {
	   		m=m/i;
	   		n=n/i;
	   		pro=pro*i;
	   	}
	   	else if(m%i==0)
	   	{
	   		m=m/i;
	   	}
	   	else if(n%i==0)
	   	{
	   		n=n/i;
	   	}
	   	else
	   	{
	   		i++;
	   	}
	}


	return pro;


	

}

int main(int argc, char const *argv[])
{
	clock_t start_time, end_time;
	double total_time;
	int a,b;
	FILE *input;
	input = fopen("inputcoprime.csv", "r");

	FILE *output;
	output = fopen("GCDMiddleSchool.csv", "w+");
	fprintf(output, "max, time\n");

	while (fscanf(input, " %d, %d ", &a, &b) > 1) {
		start_time = clock();
		for (int i = 0; i < 100000; ++i) {
			calculatePrime(a, b);
		}
		end_time = clock();
		total_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;
		fprintf(output, "%d, %lf\n", max(a, b), total_time);
	}

	fclose(input);
	fclose(output);
	
	
	
	return 0;
}