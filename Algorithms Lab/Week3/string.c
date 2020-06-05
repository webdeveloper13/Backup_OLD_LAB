#include<stdio.h>
#define max 40

int match(char * text,int m,char * pat,int n){
	int i,j,opcount=0;
	for(i=0;i<=m-n;i++){

		for(j=0;j<n && text[i+j]==pat[j];j++);
		if(j==n){
			
			return i;	
		}	
	}
	
	return -1;
}

int length(char *str){
	int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}

int main(){
	char text[max],pattern[max];
	printf("Enter text:");
	scanf("%s",text);
	printf("Enter pattern:");
	scanf("%s",pattern);
	int index=match(text,length(text),pattern,length(pattern));
	if(index==-1)
		printf("\nNo match\n");
	else
		printf("\nMatch at %d\n",index+1);
	return 0;
}