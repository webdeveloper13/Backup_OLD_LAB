#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 26
#define max 40
int table[26];
int count=0;


void shifttable(char pat[],int m){
	for(int i=0;i<size;i++){
		table[i]=m;
	}
	for(int j=0;j<m-1;j++){
		table[pat[j]-'a']=m-1-j;
	}
}

int horspool(char pat[],char text[]){
	int m=strlen(pat);
	shifttable(pat,m);
	int i=m-1;
	while(i<=strlen(text)-1){
		int k=0;
		while(k<=m-1 && pat[m-1-k]==text[i-k]){
			k=k+1;
			count++;
		}
		count++;
		if(k==m){
			return i-m+1;
		}
		
		else i+=table[text[i]-'a'];
		

	}
	return -1;
}

int main(){
	char text[max],pattern[max];
	printf("Enter text:");
	scanf("%s",text);
	printf("Enter pattern:");
	scanf("%s",pattern);
	int res=horspool(pattern,text);
	if(res==-1){
		printf("No match\n");
	}
	else
		printf("Match at %d\n",res);
	printf("Count:%d",count);
	return 0;
}