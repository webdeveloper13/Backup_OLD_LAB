#include <stdio.h> 
#include <stdlib.h> 


struct node 
{ 
	int data; 
	struct node* left, *right; 
}; 

//typedef struct node *struct node *;

struct node * createBT(){
	struct node * temp;
	int ele;
	printf("Enter the element to be inserted and -1 to stop\n");
	scanf("%d",&ele);
	if(ele==-1){
		return NULL;
	}

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = ele;

	printf("Enter the left child of %d\n",ele);
	temp->left=createBT();

	printf("Enter the right child of %d\n",ele);
	temp->right=createBT();

	return temp;
}




struct node* newNode(int data); 

int max(int a, int b); 

int height(struct node* node); 

int diameter(struct node * tree) 
{ 

if (tree == NULL) 
	return 0; 

int lheight = height(tree->left); 
int rheight = height(tree->right); 


int ldiameter = diameter(tree->left); 
int rdiameter = diameter(tree->right); 

return max(lheight + rheight + 1, max(ldiameter, rdiameter)); 
} 




int height(struct node* node) 
{ 

if(node == NULL) 
	return 0; 


return 1 + max(height(node->left), height(node->right)); 
} 




int max(int a, int b) 
{ 
return (a >= b)? a: b; 
}	 
int main() 
{ 

	struct node *root;
	root=NULL;
	root=createBT();




printf("Diameter of the given binary tree is %d\n", diameter(root)); 

getchar(); 
return 0; 
} 
