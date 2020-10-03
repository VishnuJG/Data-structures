#include<stdio.h>
#include<stdlib.h>
void endins(int );
void frontins(int );
void display();
int frontdel();
void posins(int,int);
int enddel();
int posdel(int);
typedef struct node
{
    int info;
    struct node *next;//this is a self referential structure    
}NODE;
NODE *list,*new;


void main()
{
    list=NULL;
    int x;
    while(1){
        printf("\nEnter a number:");
        scanf("%d",&x);
        switch(x)
        {
            case 1:{
                int y;
                printf("\nEnter the value required");
                scanf("%d",&y);
                frontins(y);
                
            }break;
            case 2:{
                int y;
                printf("\nEnter the value required");
                scanf("%d",&y);
                endins(y);
                
            }break;
            case 3:{
                display();
                
            }break;
            case 4:{
                printf("The term %d was deleted\n",frontdel());
               
            } break;
            case 5:{
                printf("The term %d was deleted\n",enddel());
                
            }break;
            case 6:{
                printf("Enter the position:");
                int pos;
                scanf("%d",&pos);
                printf("\nEnter the value to be inserted:");
                int val;
                scanf("%d",&val);
                posins(pos,val);
            }break;
            case 7:{
                printf("\nEnter the position to be deleted:");
                int pos;
                scanf("%d",&pos);
                printf("\n%d has been deleted",posdel(pos));
            }break;
            default  :{
                exit(0);
            }
        }
    }
}


void create(int x){
    new=(NODE *)malloc(sizeof(NODE));//NODE * is required as the malloc has to know as to what type of data it should have so basically type casting
    new->info=x;
    new->next=NULL;
}
void frontins(int x){
    create(x);
    if(list==NULL)
    {
        list=new;
    }
    else
    {
        new->next=list;
        list=new;
    }
}
void display()
{
    NODE *temp;
    if(list==NULL){
        printf("List is empty");
    }
    else
    {
        temp=list;
        while(temp!=NULL)
        {
            printf("%d \n",temp->info);
            temp=temp->next;
        }
    }
}


void endins(int x){
    create(x);
    NODE *temp;
    if(list==NULL){
        list=new;
    }
    else{
        temp=list;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
    }
}

int frontdel(){
    NODE *temp;int x;
    if(list==NULL)printf("Empty list");
    else{
        temp=list;
        list=list->next;
        x=temp->info;
        free(temp);
        return x;
    }
}
int enddel(){
    NODE *temp,*prev;int x;
    if(list==NULL)printf("Empty list");
    else if(list->next==NULL){
        temp=list;
        x=temp->info;
        list=NULL;//we can also do temp->NULL
        return x;
    }
    else{
        temp=list;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }x=temp->info;
        prev->next=NULL;//temp->next can also be replaced by temp->next as it is NULL
        free(temp);
        return x;
    }

}

void posins(int pos,int x){
    NODE *temp;
    create(x);
    if(list==NULL){
        list=new;
    }
    else if (pos==1){
        new->next=list;
        list=new;
    }
    else{
        int i=1;
        NODE *temp,*prev;temp=list;
        while(temp->next!=NULL && i<pos){
            prev=temp;
            temp=temp->next;
            i++;
        }
        if(i==pos){
        new->next=prev->next;
        prev->next=new;
        }
        else if(++i==pos){
            temp->next=new; 
        }
        else{printf("Invalid is position");}
    }
}
int posdel(int pos){
    NODE *temp,*prev;
    int i=1;int x;
    if(list==NULL){
        printf("List is empty");
    }
    else{
        NODE *temp,*prev;temp=list;
        if(pos==1){
            list=list->next;
            x=temp->info;
            free(temp);
        }
        while(temp->next!=NULL && i<pos){
            prev=temp;
            temp=temp->next;
            i++;
        }
        if(i==pos){
        prev->next=temp->next;
        x=temp->info;
        free(temp);
        }
        else{printf("Invalid is position");}
    }
    return x;
}