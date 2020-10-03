#include<stdio.h>

typedef struct node
{
    int info;
    struct node *next;//this is a self referential structure    
}NODE;
NODE *list,*new;
{
    /* data */
};

void main()
{
    list=NULL;
    if(list==NULL)
    {
        printf("List is empty");
    }
    else
    {
        new=(NODE *)malloc(sizeof(NODE));//NODE * is required as the malloc has to know as to what t
        new->info=10;
        new->next=NULL;
    }
    

}