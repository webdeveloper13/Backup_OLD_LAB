# include <stdio.h>
# include <stdlib.h>
# include <string.h>
struct node
{
    int info;
    struct node * llink;
    struct node * rlink;
};
typedef struct node * nodeptr;
nodeptr insert(int data,nodeptr root)
{
    char direction[10];
    int i;
    nodeptr temp,cur,prev;
    temp=(nodeptr)malloc(sizeof(struct node));
    temp->info=data;
    temp->llink=temp->rlink=NULL;
    if(root==NULL)
    {
        return temp;
    }
    scanf("%s",direction);
    prev=NULL;
    cur=root;
    for(i=0;i<strlen(direction) && cur!=NULL;i++)
    {
        prev = cur;
        if(direction[i]=='L')
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    if(cur!=NULL || i!=strlen(direction))
    {
        printf("insertion not possible\n");
        free(temp);
        return root;
    }
    if(direction[i-1]=='L')
    {
        prev->llink=temp;
    }
    else
        prev->rlink=temp;
    return root;
}
void preorder(nodeptr root,int * count)
{
    if(root!=NULL)
    {
        printf("%d\n",root->info);
		(*count)++;
        preorder(root->llink,count);
        preorder(root->rlink,count);
    }
}

int main()
{
    struct node * root = NULL;
    int data,count;
    printf("make a tree\n");
    do
    {
    	printf("enter data :");
        scanf("%d",&data);
	if(data!=-1)
        root=insert(data,root);
    }while(data!=-1);
    preorder(root,&count);
    printf("the number of nodes are : %d",count);
}

/*
make a tree
enter data :1
enter data :2
L
enter data :1
R
enter data :4
LL
enter data :5
RL
enter data :-1
1
2
4
1
5
the number of nodes are : 5
*/
