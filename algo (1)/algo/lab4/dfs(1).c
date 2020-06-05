#include<stdio.h>
#include<stdlib.h>
int top=-1;
int stack[10];
struct node
{
	int data;
	struct node* next;
};
void push(int k)
{
	stack[++top]=k;
}
int check()
{
	return stack[top];
}
int pop()
{
	int temp=check();
	top-=1;
	return temp;
}

int stackEmpty()
{
	if(top==-1)
		return 0;
	return 1;
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
void dfs(struct node** arr,int n)
{
	push(0);
	printf("%d ",0 );
	int i=0,cnt=0,zz[n],k=0,z;
	while(cnt<n-1)
	{
		struct node* root= *(arr+i);
		// printf("11111111111111\n");
		// printf("%d \n",top );
		root=root->next;
		if(root!=NULL)
		{
			while(root->data==-1)
				root=root->next;
			if(root!=NULL)
			{
				for(int j=0;j<k;j++)
				{
					if(zz[j]==root->data)
						root=root->next;
				}
				push(root->data);
				printf("%d ",root->data );
				zz[k++]=root->data;
				cnt++;
				// printf("%drwegergergg%d\n",cnt,n );
				i=root->data;
				root->data=-1;
			}
			else
			{
				// if(top==-1)
				// 	break;
				i=pop();
				// printf("22222222222222222\n");
			}
		}
		else
		{
			// if(top==-1)
			// 	break;
			i=pop();
			// printf("2222222222222222222222222\n");
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
	printf("the dfs traversal is : \n");
	dfs(arr,v);
}