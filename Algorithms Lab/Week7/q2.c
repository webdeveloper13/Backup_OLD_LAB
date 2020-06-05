#include<stdio.h> 
#include<stdlib.h> 
  
struct Node { 
	int key; 
	struct Node *left; 
	struct Node *right; 
	int height; 
}; 
  
int max(int a, int b){
	return(a>b)?a:b; 
}  
  
int height(struct Node *N){
	if (N == NULL) 
		return 0;
	return N->height; 
} 
  
struct Node* newNode(int key){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
    node->key   = key; 
    node->left   = NULL; 
    node->right  = NULL; 
    node->height = 1; 
    return node; 
} 
  

struct Node *rightRotate(struct Node *y){ 
    struct Node *x = y->left; 
    struct Node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
     
    y->height = max(height(y->left),height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    // Return new root 
    return x; 
} 
  
// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
struct Node *leftRotate(struct Node *x) 
{ 
    struct Node *y = x->right; 
    struct Node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Return new root 
    return y; 
} 
  
// Get Balance factor of node N 
int getBalance(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 
  
// Recursive function to insert a key in the subtree rooted 
// with node and returns the new root of the subtree. 
struct Node* insert(struct Node* node, int key) 
{ 
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return(newNode(key)); 
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    else // Equal keys are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
// A utility function to print preorder traversal 
// of the tree. 
// The function also prints height of every node 
void preOrder(struct Node *root) 
{ 
    if(root != NULL) 
    { 
        printf("%d ", root->key); 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int info;
	struct node *left,*right;
}NODE;

NODE* create(NODE *bnode,int x){
	NODE *getnode;
	if(bnode==NULL){
		bnode=(NODE*)malloc(sizeof(NODE));
		bnode->info=x;
		bnode->left=bnode->right=NULL;
	}
	else if(x>bnode->info)
		bnode->right=create(bnode->right,x);
	else if(x<bnode->info)
		bnode->left=create(bnode->left,x);
	else{
		printf("Duplicate node\n");
		exit(0);
	}
	return bnode;
}

int count(NODE * root){
	if(root==NULL)
		return 0;
	int left=count(root->left);
	int right=count(root->right);
	return left>right?left+1:right+1;
}

void inorder(NODE *ptr){
	if(ptr!=NULL){
		inorder(ptr->left);
		if( (count(ptr->left)-count(ptr>right)) >=2 )


		printf("%5d(%d)",ptr->info,count(ptr->left)-count(ptr->right));
		inorder(ptr->right);
	}
}



int main(){
	int n,x,ch,i;
	NODE *root;
	root=NULL;
	while(1){
		printf("\n1:Insert\t2:Disp\t3:Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter:");
				scanf("%d",&x);
				root=create(root,x);
			break;
			case 2: printf("\nTree:\n");
					inorder(root);
					
					break;
			case 3: exit(0);		
		}
	}
}
