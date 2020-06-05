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
