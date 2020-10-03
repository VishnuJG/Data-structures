#include<stdio.h>
#include<stdlib.h>
#define MAX 5


void push(int [],int,int *);
void pop(int [],int *);
void display(int [],int *);
int peek(int [],int);



void main(){
    int choice;
    int s[MAX];
    int top=-1;
    int x; 
    while(1){
        printf("\nEnter \n1 for PUSH\n2 for POP\n3 for DISPLAY\n4 to see what is at the top of the stack\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            {
                printf("Enter the element to be pushed:");
                scanf("%d",&x);
                push(s,x,&top);
            }break;
            case 2:{
                pop(s,&top);
                
            }break;
            case 3:
            {
                printf("The elements in the stack are:");
                display(s,&top);
            }break;
            case 4:
            {
                if(top==-1){
                    printf("Stack is empty");
                }
                else{
                    printf("The element on the top of the stack is:%d",peek(s,top));
                }
            }break;
            default:{
                exit(0);
            }
        }
    }
}


void push(int s1[MAX],int x,int *t1){
    if(*t1==(MAX-1)){
        printf("Stack overflow");
    }
    else{
        t1++;
        s1[*t1]=x;
    }
}

void pop(int s1[MAX],int *t1){
    if(*t1==-1){
        printf("Empty Stack");
        return -1;
    }
    else{
        int x=0;
        x=s1[*t1];
        *t1--;
        printf("The element popped was:%d",x);
    }
}

void display(int s1[MAX],int *t1){
    if(*t1==-1){
        printf("Stack is empty");
    }
    else{
        for(int i=*t1;i>=0;i--){
            printf("%d ",s1[i]);
        }
    }
}

int peek(int s1[MAX],int t1){
    if(t1==-1){
        return -1;
    }
    else{
        return s1[t1];
    }
}