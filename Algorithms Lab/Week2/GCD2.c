#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int min(int x,int y){
	return x<y?x:y;
}

int *sieve(int c){
	int * result=(int *)malloc(sizeof(int)*(c+1));
	for(int i=0;i<=c;i++){
		result[i]=0;
	}
	for(int i=2;i<=c;i++){
		if(result[i]==0)
			continue;
		int j=i+i;
		while(j<=c){
			result[j]=-1;
			j+=i;
		}

	}
	return result;
}

int *primes(int x){
	int *primes=sieve(x);
	int i=2;
	while(x>1){
	if(primes[i]!=-1 && x%i==0){
		primes[i]++;
		x=x/i;
	}
	else
		i++;
	}
	return primes;
}

int GCD(int x,int y){
	int * primes_x=primes(x);
	int * primes_y=primes(y);
	int gcd=1;
	for(int i=2;i<=min(x,y);i++){
		if(primes_x[i]>0 && primes_y[i]>0)
			gcd=gcd*pow(i,min(primes_x[i],primes_y[i]));
	}
	return gcd;
}

int main(){
	int x,y;
	printf("Enter numbers:\n");
	scanf("%d",&x);
	scanf("%d",&y);
	printf("GCD:%d\n",GCD(x,y));
	int * result=primes(x);
	return 0;

}