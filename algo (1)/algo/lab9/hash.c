#include<stdio.h>
#include<stdlib.h>

typedef struct node *nodeptr;

typedef struct  node
{
	int data;
	nodeptr next;
}node;

nodeptr createnode(int ele)
{
	nodeptr temp=(nodeptr)malloc(sizeof(node));
	temp->data=ele;
	temp->next=NULL;
	return temp;
}

nodeptr add(nodeptr head,int ele)
{
	if(head==NULL)
		return createnode(ele);

	nodeptr temp=head;
	nodeptr new=createnode(ele);
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new;
	return head;
}

nodeptr *createTable(int n)
{
	nodeptr *list=(nodeptr*)calloc(n,sizeof(nodeptr));int ele;
	printf("Enter indices of table\n");
	for(int i=0;i<n;i++)
	{
		//printf("Enter index:");scanf("%d",&ele);
		list[i]=createnode(i);
	}
	return list;
}

void print_hash(nodeptr *l,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Index:%d\n",l[i]->data);
		nodeptr temp=l[i]->next;;
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("\n\n");
	}
}

int main()
{
	printf("Enter number of elements to be hashed:");
	int m,n;scanf("%d",&m);
	int *arr=(int *)malloc(sizeof(int)*m);
	printf("Enter array elements\n");
	for(int i=0;i<m;i++)
		scanf("%d",&arr[i]);
	printf("Enter size of hash table:");scanf("%d",&n);
	nodeptr *list=createTable(n);
	for(int i=0;i<m;i++)
	{
		int ele=arr[i]%n;
		list[ele]=add(list[ele],arr[i]);
	}
	printf("Hash table\n");
	print_hash(list,n);

}