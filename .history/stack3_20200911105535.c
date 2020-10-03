#include<stdio.h>
#include<stdlib.h>
typedef struct dnode
{
    int info;
    struct dnode *left,*right;//this is a self referential structure    
}DNODE;
void display();
DNODE* endins(DNODE*,int);

DNODE* enddel(DNODE*);



void main()
{
    DNODE *dlist,*new;
    dlist=NULL;
    int x;
    while(1){
        printf("\nEnter a number:\n1 for PUSH\n2 for display\n3 for enddel:\n");
        scanf("%d",&x);
        switch(x)
        {
            
            case 1:{
                int y;
                printf("\nEnter the value required for end insertion:");
                scanf("%d",&y);
                dlist=endins(dlist,y);
                
            }break;
            case 2:{
                display(dlist);
                
            }break;
            case 3:{
                dlist=enddel(dlist);
                
            }break; 
            
            default  :{
                exit(0);
            }
        }
    }
}


void display(DNODE *dl1)
{
    DNODE *temp;
    if(dl1==NULL){
        printf("list is empty");
    }
    else{
        temp=dl1;
        while(temp!=NULL)
        {
            printf("\t%d",temp->info);
            temp=temp->right;
            //temp=temp->right->right;//this will print alternate elements
        }
    }
}

DNODE* endins(DNODE* dl1,int x){
    DNODE *new;
    new=(DNODE *)(malloc(sizeof(DNODE)));
    new->info=x;
    new->left=NULL;
    new->right=NULL;
    DNODE *temp;
    if(dl1==NULL){
        dl1=new;
    }
    else{
        temp=dl1;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        temp->right=new;
        new->left=temp;
    }
    return dl1;
}


DNODE* enddel(DNODE* dl1){
    DNODE *temp;
    if(dl1==NULL)printf("Empty list");
    else if(dl1->right==NULL){
        temp=dl1;
        dl1=NULL;
        free(temp);
        return dl1;
    }
    else{
        temp=dl1;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        temp->left->right=NULL;//temp->next can also be replaced by temp->next as it is NULL
        free(temp);
        //printf("\nThe element that was deleted was:%d",x);
        return dl1;
    }

}


DNODE* order_ins(DNODE* dll,int x){
    DNODE *temp,*new;
    new=(DNODE *)(malloc(sizeof(DNODE)));
    new->info=x;
    new->right=NULL;
    new->left=NULL;
    if(dll==NULL){
        dll=new;
    }
    else{
        if(x<(dll->info))
        {
            new->right=dll;
            dll->left=new;
            dll=new;
        }
        else{
            temp=dll;
            while((temp->info)<x && temp->right!=NULL){
                temp=temp->right;
            }
            if(x<(temp->info)){
                new->right=temp;
                new->left=temp->left;
                temp->left=new;
                (new->left)->right=new;
            }
            else{
                temp->right=new;
                new->left=temp;
            }
        }
    }
    return dll;
}