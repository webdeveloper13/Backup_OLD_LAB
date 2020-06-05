#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct stack
{
	struct node* t;
	struct stack* next; 	
};
void push(struct stack** top_ref, struct node* t)
{
	struct stack* new_node = (struct stack*)malloc(sizeof(struct stack));
	if(new_node==NULL)
	{
		printf("stack overflow\n");
		getchar();
		exit(0);
	}
	new_node->t=t;
	new_node->next = *top_ref;
	*top_ref=new_node;
}
bool isEmpty(struct stack *top) 
{ 
   return (top == NULL)? 1 : 0; 
}    
struct node *pop(struct stack** top_ref) 
{ 
  struct node *res; 
  struct stack *top; 
  
  /*If sNode is empty then error */
  if(isEmpty(*top_ref)) 
  { 
     printf("Stack Underflow \n"); 
     getchar(); 
     exit(0); 
  } 
  else
  { 
     top = *top_ref; 
     res = top->t; 
     *top_ref = top->next; 
     free(top); 
     return res; 
  } 
} 
void inorder_itr(struct node* root)
{
	if(root==NULL)
		return;
	
}
void insertion(struct node** root, int item)
{
	if(*root==NULL)
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data=item;
		temp->left=temp->right=NULL;
		*root= temp;
		return;
	}
	else if((*root)->data < item)
		insertion(&((*root)->right),item);
	else
		insertion(&((*root)->left),item);
}
int search_key(struct node* root , int key)
{
	if(root==NULL)
		return -1;
	if(root->data == key)
		return 1;
	else if(root->data<key)
		search_key(root->right,key);
	else if(root->data>key)
		search_key(root->left,key);
}
void inorder(struct node* root)
{
		if(root!=NULL)
		{
			inorder(root->left);
			printf("%d ->",root->data);
			inorder(root->right);
		}
}
void preorder(struct node* root)
{
		if(root!=NULL)
		{
			printf("%d -> ",root->data);
			preorder(root->left);
			preorder(root->right);
		}
}
void postorder(struct node* root)
{
		if(root!=NULL)
		{
			postorder(root->left);
			postorder(root->right);
			printf("%d -> ",root->data);
		}
}
int main()
{
	int a = 1;
	struct node* root = NULL;
	int arr[20],n;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(int i=0;i<n;i++)
		insertion(&root,arr[i]);
	int opt;
	printf("1. search \n" );
	printf("2. display \n" );
	scanf("%d",&opt);
	do
	{
	switch(opt)
	{
		case 1: printf("enter the key to be searched for\n");
				int key;
				scanf("%d",&key);
				int b = search_key(root,key);
				if(b==1)
					printf("key found\n");
				else
					{
						insertion(&root,key);
						printf("key not found! inserted in the tree\n");
					}
				break;
		case 2: printf(" inorder traversal : ");
				inorder(root);
				printf("\n preorder traversal : ");
				preorder(root);
				printf("\n postorder traversal : ");
				postorder(root);
				break;
		default: printf("please enter the correct option\n");
	}
printf("\n Wanna go again (yes(1) | no(0))? ");
scanf("%d",&a);

if(a==1)
{	
	printf("enter option : \n");
	scanf("%d",&opt);
}
else
	break;
}
while(a==1);
	return 0;
}