#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

typedef struct Node * Nodeptr;

int max(int x,int y){
	return x>y?x:y;
}
Nodeptr search(Nodeptr head,int key){
	Nodeptr temp=head;
    while(temp!=NULL){
		if(temp->data==key){
			printf("Key present\n");
			return head;
		}
		
		if(key<temp->data){
			if(temp->left==NULL)
			break;
			temp=temp->left;
			continue;
		}	
 		if(key>temp->data){
 			if(temp->right==NULL)
				break;
			temp=temp->right;
			continue;
		}
						
	}
	
	printf("Inserting\n");
	Nodeptr newnode=(Nodeptr)malloc(sizeof(struct Node));
	newnode->data=key;
	newnode->left=newnode->right=NULL;
	if(temp==NULL)
		return newnode;
	if(key<temp->data)
		temp->left=newnode;
	else
		temp->right=newnode;
	return head;

}

int height(Nodeptr root){
	if(root==NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;
} 

int diameter(Nodeptr tree){
	if (tree==NULL)
		return 0;
	int lheight=height(tree->left);
  	int rheight=height(tree->right);

  	int ldiameter = diameter(tree->left);
  	int rdiameter = diameter(tree->right);
  	return max(lheight+rheight+1,max(ldiameter,rdiameter));
} 
 


void inorder(Nodeptr head){
	if(head==NULL)
		return;
	inorder(head->left);
	printf("%d\t",head->data);
	inorder(head->right);
}

int main(){
	Nodeptr header=NULL;
	int ch=0;
	while(ch!=3){
		printf("\n1:Search\n2:Display\n3:Exit\nEnter choice:");
		scanf("%d",&ch);
		if(ch==1){
			int key;
			printf("\nEnter key:");
			scanf("%d",&key);
			header=search(header,key);
		}
		if(ch==2){
			//printf("\nInorder:");
			//inorder(header);
			printf("\nDiamter:%d",diameter(header));
			

		}

	}

	return 0;
}

