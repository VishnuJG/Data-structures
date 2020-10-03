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
int search_del(DNODE *,int);
DNODE* order_ins(DNODE*,int);

void main()
{
    DNODE *dlist,*new;
    dlist=NULL;
    int x;
    while(1){
        printf("\nEnter a number:");
        scanf("%d",&x);
        switch(x)
        {
            case 1:{
                int y;
                printf("\nEnter the value required for front insertion:");
                scanf("%d",&y);
                dlist=frontins(dlist,y);
                
            }break;
            case 2:{
                int y;
                printf("\nEnter the value required for end insertion:");
                scanf("%d",&y);
                dlist=endins(dlist,y);
                
            }break;
            case 3:{
                display(dlist);
                
            }break;
            case 4:{
                dlist=frontdel(dlist);
               
            } break;
            case 5:{
                dlist=enddel(dlist);
                
            }break;
            case 6:{
                printf("Enter the successor node info:");
                int suc;
                scanf("%d",&suc);
                int val;
                printf("Enter the value of the node:");
                scanf("%d",&val);
                dlist=succ_node_info(dlist,suc,val);
            }break;
            case 7:{
                printf("\nEnter the value to be deleted:");
                int pos;
                scanf("%d",&pos);
                int flag;
                flag=search_del(dlist,pos);
            }break;
            case 8:{
                int y;
                printf("\nEnter the value required for ordered insertion:");
                scanf("%d",&y);
                dlist=order_ins(dlist,y);
            }break;

            default  :{
                exit(0);
            }
        }
    }
}

DNODE* frontins(DNODE *dl1, int x){
    DNODE *new;
    new=(DNODE *)(malloc(sizeof(DNODE)));
    new->info=x;
    new->left=NULL;
    new->right=NULL;
    if(dl1==NULL){
        dl1=new;
    }
    else{
        new->right=dl1;
        dl1->left=new;
        dl1=new;
    }
    return dl1;
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

DNODE * frontdel(DNODE* dl1){
    DNODE* temp;
    if(dl1==NULL)printf("Empty list");
    else{
        temp=dl1;
        dl1=dl1->right;
        if(dl1!=NULL){
            dl1->left=NULL;
        }
        printf("\nThe element that was deleted was:%d",temp->info);
        free(temp);
        return dl1;
    }
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

DNODE* succ_node_info(DNODE* dl1,int suc,int x){
    DNODE *temp;
    DNODE *new;
    new=(DNODE *)(malloc(sizeof(DNODE)));
    new->info=x;
    new->left=NULL;
    new->right=NULL;
    if(dl1==NULL){
        dl1=new;
    }
    else if (suc==dl1->info){
        new->right=dl1;
        dl1->left=new;
        dl1=new;
    }
    else{
        temp=dl1;
        while (temp->right!=NULL && temp->info!=suc)
        {
            temp=temp->right;
        }
        if(temp->info==suc){
        new->right=temp;
        new->left=temp->left;
        temp->left=new;
        (new->left)->right=new;
        }
        else{printf("Invalid in position");}
    }
    return dl1;
}

int search_del(DNODE *dl1,int x){
    DNODE* temp;
    if(dl1==NULL){
        printf("List is empty and hence cannot delete from this list");return 0;
    }
    else{
        temp=dl1;
        if(temp->info==x){
            dl1=dl1->right;
            dl1->left=NULL;
            printf("the element %d was deleted",temp->info);
            free(temp);return 1;
        }
        else
        {
            while(temp->right!=NULL && temp->info==x){
            temp=temp->right;
            }
            if(temp->info==x){
                if(temp->right==NULL)
                {(temp->left)->right=temp->right;
                (temp->right)->left=temp->left;
                free(temp);return 1;
                }
                else if(temp->right==NULL)
                {
                    (temp->left)->right=temp->right;
                    free(temp);
                    return 1;
                }
                else{
                    printf("Invalid data");return 0;
                }
        }}}
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