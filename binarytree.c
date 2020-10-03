#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int info;
	struct node *left, *right;
}TREE;

TREE* lexins(TREE *,int);
void preorder(TREE*);
void inorder(TREE*);
void postorder(TREE*);
int maxval(TREE*);
int minval(TREE*);
void noofnodes(TREE*);
void noofleafnodes(TREE*);
TREE* delete_node(TREE*,int );
int count=0;
int leafcount=0;

void main(){
	TREE *root;
	int choice,x;
	root=NULL;
	while(1){
		printf("\n1->Insert\n2->Preorder Traversal\n3->Inorder Traversal\n4->Postorder Traversal\n5->Minimum value in the tree\n6->Maximum value in the tree\n7->Number of nodes in the tree\n8->Number of Leaf Nodes in the tree\n9->Delete Node\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				printf("Enter the value to be inserted:");
				scanf("%d",&x);
				root=lexins(root,x);
			}break;
			case 2:{
				preorder(root);
			}break;
			case 3:{
				inorder(root);
			}break;
			case 4:{
				postorder(root);
			}break;
			case 5:{
				printf("\n Min value is : %d\n",minval(root));
			}break;
			case 6:{
				printf("\n Max value is : %d\n",maxval(root));
			}break;
			case 7:{
				noofnodes(root);
				printf("The number of nodes in the tree : %d",count);
			}break;
			case 8:{
				noofleafnodes(root);
				printf("The number of leaf nodes in the tree : %d",leafcount);
			}break;
			case 9:{
				printf("Enter the info of the node to be deleted : ");
				scanf("%d",&x);
				root=delete_node(root,x);
			}break;
			default:{
				exit(0);
			}
		}
	}
}

TREE* lexins(TREE *root,int x){
	TREE *newnode,*temp;
	int flag=1;
	newnode=(TREE *)(malloc(sizeof(TREE)));
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->info=x;
	
	if(root==NULL){
		root=newnode;
	}
	else{
		temp=root;
		while(flag)
		{
			if(x<temp->info)
			{
				if(temp->left==NULL)
				{
					temp->left=newnode;
					flag=0;
				}
				else
				{
					temp=temp->left;
				}
			}
			else{ 
				if(temp->right==NULL){
					temp->right=newnode;
					flag=0;
				}
				else{
					temp=temp->right;
				}
			}
		}
	}
	return root;
}
void preorder(TREE *root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->info);
		preorder(root->left);
		preorder(root->right);
	}
	
}
void inorder(TREE *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->info);
		inorder(root->right);
	}
}

void postorder(TREE *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->info);
	}
}

int minval(TREE *root){
	TREE *temp;
	temp=root;
	while(temp->left!=NULL){
		temp=temp->left;
	}return(temp->info);
}

int maxval(TREE *root){
	TREE *temp;
	temp=root;
	while(temp->right!=NULL){
		temp=temp->right;
	}return(temp->info);
}
void noofnodes(TREE *root){
	if(root!=NULL){
		noofnodes(root->left);
		noofnodes(root->right);
		count++;
	}
}
void noofleafnodes(TREE *root){
	if(root!=NULL){
		noofleafnodes(root->left);
		noofleafnodes(root->right);
		if(root->left==NULL && root->right==NULL){
			leafcount++;
		}
	}
}


TREE* delete_node(TREE *root,int x){
	TREE *temp,*q,*parent,*insucc;
	temp=root;q=NULL;parent=NULL;
	while(temp!=NULL && temp->info!=x){
		parent=temp;
		if((temp->info)>x){
			temp=temp->left;
		}
		else{
			temp=temp->right;
		}
	}
	if(temp==NULL){
		printf("\nThis is an Unsuccessful search...Key not found\n");
	}
	else if(temp->left==NULL){
		q=temp->right;
	}
	else if(temp->right==NULL){
		q=temp->left;
	}
	else {//two child nodes
	//find the inorder successor of the temo node
		insucc=temp->right;
		while(insucc->left!=NULL){
			insucc=insucc->left;
		}
		insucc->left=temp->left;
		q=temp->right;
	}
	if(parent==NULL){//delete the root node
			root=q;
	}
	else if(temp==parent->left){
		parent->left=q;
	}
	else if(temp==parent->right){
		parent->right=q;
	}
	free(temp);
	count--;
	return root;
}




