#include<stdio.h>

int GCD(int x,int y){
	int count=0;
	int i;
	int gcd=x>y?y:x;
	for(i=gcd;i>1;i--){
		if(x%i==0 && y%i==0)
			break;
		else
			count++;
	}

	printf("Count:%d\n",count+1);
	return i;
}

int main(){
	int a,b;
	printf("Enter numbers:\n");
	scanf("%d%d",&a,&b);
	printf("GCD:%d\n",GCD(a,b));
	return 0;
}