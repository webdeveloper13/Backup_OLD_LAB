#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *left, *right;
}NODE;

NODE* insertion(NODE*bnode, int item)
{
	if(bnode==NULL)
	{
		bnode = (NODE*)malloc(sizeof(NODE));
		bnode->data=item;
		bnode->left=bnode->right=NULL;
	}
	else if(bnode->data < item)
		bnode->right=insertion(bnode->right,item);
	else if(bnode->data > item)
		bnode->left=insertion(bnode->left,item);

	else{
		printf("Duplicate Nodes\n");
		exit(0);
	}

	return(bnode);
}        

void inorder(NODE* root)
{
		if(root!=NULL)
		{
			inorder(root->left);
			printf("%d ->",root->data);
			inorder(root->right);
		}
}
void preorder(NODE* root)
{
		if(root!=NULL)
		{
			printf("%d -> ",root->data);
			preorder(root->left);
			preorder(root->right);
		}
}
void postorder(NODE* root)
{
		if(root!=NULL)
		{
			postorder(root->left);
			postorder(root->right);
			printf("%d -> ",root->data);
		}
}

void main()
{
	int n, x, ch, i;
	NODE* root;
	root =  NULL;

	while(1) {
		printf("\n\n*****MENU******\n\n");
		printf("1.Insert\n2.All Traversals\n3.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("enter the node to be inserted\n");
					scanf("%d",&x);
					root = insertion(root,x);
					break;
			case 2: printf("inorder traversal : ");
					inorder(root);
					printf("\npreorder traversal : ");
					preorder(root);
					printf("\npostorder traversal : ");
					postorder(root);
					break;
			case 3: exit(0);
			default: printf("please enter the correct option\n");
		}

	}
}


