#include<stdio.h>
#include<stdlib.h>

int queue[10];
int rear=-1,front=-1;
struct node
{
	int data;
	struct node* next;
};
void pushQueue(int n)
{
	if(-1==front)
		front=0;
	rear++;
	queue[rear]=n;
}
int popQueue()
{
	int temp=queue[front];
	front++;
	return temp;
}

void insert(struct node* root,int dst)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=dst;
	temp->next=NULL;
	while(root->next!=NULL)
		root=root->next;
	root->next=temp;
}

void bfs(struct node** arr,int n)
{
	pushQueue(0);
	printf("%d ",0 );
	int i=0,zz[n],k=0,z;
	struct node* root= *(arr+i);
	while(front<=rear)
	{
		// printf("111111111111111111\n");
		int temp=popQueue();
		// printf("%d ",temp );
		root=*(arr+temp);
		while(root->next!=NULL)
		{
			z=0;
			// printf("222222222222222\n");
			root=root->next;
			// printf("333333333333\n");
			for(int j=0;j<k;j++)
			{
				if(root->data==zz[j])
					z=1;
			}
			if(z==1)
				continue;
			pushQueue(root->data);
			printf("%d ",root->data );
			zz[k]=root->data;
			k++;
		}
	}
}

void main()
{
	int v,temp,i;
	printf("enter number of vertex\n");
	scanf("%d",&v);
	struct node* arr[v];
	i=0;
	while(i!=v)
	{
		arr[i]=(struct node*)malloc(sizeof(struct node));
		arr[i]->data=i;
		arr[i]->next=NULL;
		i++;
	}
	for(i=0;i<v;i++)
	{
		int ch=1;
		while(1)
		{
			printf("Exit with 0 for %d vertex\n",i);
			scanf("%d",&ch);
			if(ch==0)
				break;
			printf("enter the edges of %d vertex\n",i);
			scanf("%d",&temp);
			insert(arr[i],temp);
		}
	}
	printf("the bfs traversal is : \n");
	bfs(arr,v);
}