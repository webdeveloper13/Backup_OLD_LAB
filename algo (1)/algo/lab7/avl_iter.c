#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node *left;
	int data;
	struct node *right;
}Tree;

int max(int a, int b) { 
	return (a >= b)? a: b; 
}

int Height(struct node *root) { 
	if(root == NULL) 
		return 0; 
	return 1 + max(Height(root -> left), Height(root -> right)); 
}

int BalanceFactor(struct node *root) {
	return Height(root -> left) - Height(root -> right);
}

Tree *rightRotate(Tree *root)
{
	Tree *temp = root->left;
	Tree *temp2 = temp->right;

	temp->right = root;
	root->left = temp2;

	return temp;
}

Tree *leftRotate(Tree *root)
{
	Tree *temp = root->right;
	Tree *temp2 = temp->left;

	temp->left = root;
	root->right = temp2;

	return temp;
} 

Tree *Insert(struct node *root, int element) {
	int top = -1, stackside[20], factor = 0;
	Tree *stack[20];

	Tree *temp, *temp2 = root;
	temp = (Tree *)malloc(sizeof(Tree));
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> data = element;

	
	while(temp2) {
		stack[++top] = temp2;
		if(element < temp2 -> data) {
			stackside[top] = 0;
			if(temp2 -> left)
				temp2 = temp2 -> left;
			else {
				temp2 -> left = temp;
				break;
			}
		}
		else {
			stackside[top] = 1;
			if(temp2 -> right)
				temp2 = temp2 -> right;
			else {
				temp2 -> right = temp;
				break;
			}
		}
	}

	if(root == NULL)
		return temp;

	while(top != -1) {
		temp = stack[top--];
		factor = BalanceFactor(temp);

		if (factor > 1 && element < temp -> left -> data) {
			if(top == -1)
				temp = rightRotate(temp);
			else if(stackside[top] == 0)
				stack[top] -> left = rightRotate(temp);
			else if(stackside[top] == 1)
				stack[top] -> right = rightRotate(temp);
		}
		else if (factor < -1 && element > temp -> right -> data) {
			if(top == -1)
				temp = leftRotate(temp);
			else if(stackside[top] == 0)
				stack[top] -> left = leftRotate(temp);
			else if(stackside[top] == 1)
				stack[top] -> right = leftRotate(temp);
		}
		else if (factor > 1 && element > temp -> left -> data) {
			temp -> left = leftRotate(temp->left);
			if(top == -1)
				temp = rightRotate(temp);
			else if(stackside[top] == 0)
				stack[top] -> left = rightRotate(temp);
			else if(stackside[top] == 1)
				stack[top] -> right = rightRotate(temp);
		}
		else if (factor < -1 && element < temp->right->data) {
			temp -> right = rightRotate(temp->right);
			if(top == -1)
				temp = leftRotate(temp);
			else if(stackside[top] == 0)
				stack[top] -> left = leftRotate(temp);
			else if(stackside[top] == 1)
				stack[top] -> right = leftRotate(temp);
		}
	}

	return temp;
}

void PreDisplay(struct node *root) {
	if(root != NULL) {
		printf("%d ",root -> data);
		PreDisplay(root -> left);
		PreDisplay(root -> right);
	}
}

void main() {
	Tree *root = NULL;
	while(1) {
		int ch,ele;
		printf("\nBINARY SEARCH TREE MENU:\n\t1. Insert\n\t2. PreOrder Traversal\n\t3. Exit\nEnter Choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: printf("\nEnter Element to Insert: ");
					scanf("%d", &ele);
					root = Insert(root,ele);
					break;
			case 2: printf("\nPreOrder Traversal:\n");
					PreDisplay(root);
					break;
			default:exit(0);
		}
	}
}
