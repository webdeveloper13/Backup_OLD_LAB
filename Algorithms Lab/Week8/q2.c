#include <stdio.h>
#define max 300
int count=0;

void heapify(int h[],int n){
	int i,k,v,heapify,j;
	
	for(i=(n/2);i>=1;i--){
				k=i;
		v=h[k];
		heapify=0;
		while(heapify==0 && 2*k<=n){
			
			count++;
			j=2*k;
			if(j<n)
				if(h[j]<h[j+1])
					j=j+1;
			if(v>=h[j])
				heapify=1;
			else{
				
				h[k]=h[j];
				k=j;
			}
		}
		h[k]=v;
	}
	return;

}

void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void sort(int h[],int n){
	int arr[max],i=0;
	heapify(h,n);
	while(n>0){
		arr[i++]=h[1];
		swap(&h[1],&h[n]);
		n--;
		
		heapify(h,n);
	}	
	printf("\nSorted:\n");
	while(i>0){
		printf("%d\t",arr[--i]);
	}
}

int main(){
	int h[max],i,n;
	printf("Number of elemets:");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	sort(h,n);
	//printf("Heap:\n");
	//for(int i=1;i<=n;i++){
	//	printf("%d\t",h[i]);
	//}
	printf("Opcount:%d",count);
	return 0;

}
