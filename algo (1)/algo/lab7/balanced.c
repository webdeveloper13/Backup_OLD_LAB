#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h> 

typedef struct node {
	int data;
	struct node *left, *right;
}NODE;

int max(int a, int b) 
{ 
    return (a >= b) ? a : b; 
} 

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

int BalFac(NODE* root) 
{ 
    int lh, rh; 
  
    if (root == NULL) 
        return 1; 
  
    lh = height(root->left); 
    rh = height(root->right); 
    
    printf("\n\nBalnce factor of %d is %d\n\n", root->data, (lh - rh));
    return 0;
} 

int height(NODE* node) 
{ 
    if (node == NULL) return 0; 
    return 1 + max(height(node->left), height(node->right)); 
}

void PrintBAlFac(NODE* root) {

	if(root!=NULL)
		{
			PrintBAlFac(root->left);
			BalFac(root);
			PrintBAlFac(root->right);
		}

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
		printf("1.Insert\n2.All Traversals\n3.Balance factor\n4.Exit\n");
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
			case 3: PrintBAlFac(root);
			case 4: exit(0);
			default: printf("please enter the correct option\n");
		}
	}
}


