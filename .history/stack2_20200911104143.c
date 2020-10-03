#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;//this is a self referential structure    
}NODE;
NODE *list,*new;


void frontins(int );
void display();
int frontdel();
void create(int);

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
                display();
                
            }break;
            case 2:{
                printf("The term %d was deleted\n",frontdel());
               
            } break;
            
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

