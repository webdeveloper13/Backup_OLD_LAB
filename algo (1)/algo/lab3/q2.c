#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char text[100],pat[50];
int brute_force(char text[],char pat[],int m,int n);

int main(int argc, char const *argv[])
{
	int t;
	printf("Enter the number of test cases\n");
	scanf("%d",&t);
	for(int i=0;i<t;i++){

    char text[100],pat[50];
	printf("Enter a text string\n");
	scanf("%s",text);
	printf("Enter the pattern you wanna find\n");
	scanf("%s",pat);
	int pos;
	int m=strlen(text);
	int n=strlen(pat);
	pos=brute_force(text,pat,m,n);

	if(pos==-1){
		printf("Matching String not found\n");
	}

	else{
		printf("String present at position %d\n",pos);
	}


}
	
	return 0;
}

int brute_force(char text[],char pat[],int m,int n){

	for(int i=0;i<m;i++){
		int j=0;
		while(j<n && text[i+j]==pat[j]){
			j++;

			if(j==n){
				return i+1;
			}
		}
	}

	return -1;

}

