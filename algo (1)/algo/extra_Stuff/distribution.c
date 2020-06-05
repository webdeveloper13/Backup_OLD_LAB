	  
#include<stdio.h>
#include<conio.h>

int i,j,n,m,a[20],s[20],count[20];
void dist(int a[],int n);

void main()
{
clrscr();
printf("Enter the number of elements:\n");
scanf("%d",&n);
printf("Enter the elements in an array:\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Unsorted array is:\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
dist(a,n);
getch();
}

void dist(int a[],int n)
{
m=n;

for(j=0;j<=m-1;j++)
count[j]=0;

for(i=1;i<=n;i++)
count[a[i]]= count[a[i]] + 1;

for(j=1;j<=m-1;j++)
count[j]= count[j-1] + count[j];

for(i=n;i>=0;i--)
{
s[count[a[i]]-1]= a[i];
count[a[i]]= count[a[i]] - 1;
}

printf("\nSorted array is:\n");
for(i=0;i<n;i++)
printf("%d\t",s[i]);
}