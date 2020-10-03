#include<stdio.h>
#include<stdlib.h>

void BSTinsert(int);
void preorder(int);
void inorder(int);
void postorder(int);

int t[50];

void main(){
	int choice,i,x;
	i=0;
	for(i=0;i<50;i++){
		t[i]=0;
	}
	while(1){
		printf("\nEnter \n1->BTS Insertion\n2->Preorder\n3->Inorder\n4->Postorder\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				printf("\nEnter the value to be added : ");
				scanf("%d",&x);
				BSTinsert(x);
			}break;
			case 2:{
				preorder(i);
			}break;
			case 3:{
				inorder(i);
			}
			case 4:{
				postorder(i);
			}break;
			default:{
				exit(0);
			}
		}
	}
}

void BSTinsert(int x){
	int i=0;
	if(t[i]==0)//empty tree
	{
		t[i]=x;
	}
	else{
		while(t[i]!=0){
			if(x<t[i])
			{
				i=2*i+1;
			}
			else{
				i=2*i+2;
			}
		}
		t[i]=x;
	}
}
void preorder(int i){
	if(t[i]!=0){
		printf("\t%d",t[i]);
		preorder(2*i+1);
		preorder(2*i+2);
	}
}
void inorder(int i){
	if(t[i]!=0){
		inorder(2*i+1);
		printf("\t%d",t[i]);
		inorder(2*i+2);
	}
}

void postorder(int i){
	if(t[i]!=0){
		postorder(2*i+1);
		postorder(2*i+2);
		printf("\t%d",t[i]);
	}
}











