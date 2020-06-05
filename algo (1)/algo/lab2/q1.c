#include <stdio.h>
#include<stdlib.h>

int calculateGcd(int m,int n){
	int t;
  
	if(m>n){
		t=n;
	}

	else{
		t=m;
	}

	while(t>0){
		if(m%t==0&&n%t==0){
			return t;
			break;
		}

		t-=1;
	}
}

int main(int argc, char const *argv[])
{
	int a,b;
	printf("Enter two numbers whose gcd should be calculated\n");
	scanf("%d",&a);
	scanf("%d",&b);

	printf("Gcd of these two numbers is %d\n",calculateGcd(a,b));

	return 0;
}