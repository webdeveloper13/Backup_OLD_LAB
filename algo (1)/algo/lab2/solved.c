#include <stdio.h>
#include <stdlib.h>

int gcd_euclid(unsigned int m, unsigned int n) {
	int opcount=0;
	unsigned int r;
	while(n!=0){
		opcount++;
		r=m%n;
		m=n;
		n=r;
	}

	printf("Operation Count is %d\n",opcount);
	return m;
}

int main(int argc, const char * argv []) {

	unsigned int m,n;
	printf("Enter two numbers whose gcd you want to calculate\n");
	scanf("%d",&m);
	scanf("%d",&n);
	printf("GCD IS %d\n",gcd_euclid(m,n));
	//gcd_euclid(m,n);
	return 0;
}