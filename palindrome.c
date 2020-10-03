#include<stdio.h>
#include<stdlib.h>
typedef struct dnode
{
    char info;
    struct dnode *left,*right;//this is a self referential structure    
}DNODE;

DNODE* endins(DNODE*,char );
void validate(DNODE*);

void main(){
    DNODE *dlist;
    dlist=NULL;
    int x;
   while(1){
        printf("\nEnter a number:");
        scanf("%d",&x);
        switch(x)
        {
            case 1:{
                char y;
                printf("\nEnter the value required for end insertion:");
                scanf("%d",&x);
                scanf("%c",&y);
                dlist=endins(dlist,y);
                
            }break;
            case 2:{
                validate(dlist);                
            }break;
            
            default  :{
                exit(0);
            }
        }
    }
}

DNODE* endins(DNODE *dll,char x){
    DNODE *new;
    new=(DNODE *)(malloc(sizeof(DNODE)));
    new->info=x;
    new->left=NULL;
    new->right=NULL;
    if(dll==NULL){
        dll=new;
    }
    else{
        new->right=dll;
        dll->left=new;
        dll=new;
    }
    return dll;
}

void validate(DNODE* dll){
    DNODE *initial,*final;
    initial=dll;
    int flag=0;
    if(initial==NULL){
        printf("Empty List");
    }
    else if(initial->right==NULL){
        printf("Only one element is present ...Invalid entry, try adding more nodes");
    }
    else
    {
        final=dll;
        while(final->right!=NULL)
        {
            final=final->right;
        }
        while(initial!=NULL){
            if(initial->info==final->info)
            {
                initial=initial->right;
                final=final->left;
                if(initial->left==final || final->right==initial || final==initial){
                    flag=1;
                    break;
                }
            }
            else{
                break;
            }
        }
        if(flag==1){
        printf("\nIT IS A PALINDROME");
        }
        else{
            printf("\nIT IS NOT A PALINDROME");
        }
    }
    
}