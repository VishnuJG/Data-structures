#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct stack{
    int s[MAX];
    int top;
}STACK;


void push(STACK*,int );
int pop(STACK*);
void display(STACK*);
int peek(STACK*);



void main(){
    int choice;
    STACK stk;
    int x; 
    stk.top=-1;
    while(1){
        printf("\nEnter \n1 for PUSH\n2 for POP\n3 for DISPLAY\n4 to see what is at the top of the stack\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            {
                printf("Enter the element to be pushed:");
                scanf("%d",&x);
                push(&stk,x);
            }break;
            case 2:{
                printf("The element popped was:%d",pop(&stk));
                
            }break;
            case 3:
            {
                printf("The elements in the stack are:");
                display(&stk);
            }break;
            case 4:
            {
                printf("The element on the top of the stack is:%d",peek(&stk));                
            }break;
            default:{
                exit(0);
            }
        }
    }
}


void push(STACK *s1,int x){
    if((s1->top)==(MAX-1)){
        printf("Stack overflow");
        
    }
    else{
        (s1->top)++;
        s1->s[s1->top]=x;
        
    }
}

int pop(STACK *s1){
    int x;
    if((s1->top)==-1){
        return -1;
    }
    x=s1->s[s1->top];
    (s1->top)--;
    return x;

}

void display(STACK *s1){
    if((s1->top)==-1){
        printf("Stack is empty");
    }
    else{
        for(int i=(s1->top);i>=0;i--){
            printf("%d ",s1->s[i]);
        }
    }
}

int peek(STACK *s1){
    if((s1->top)==-1){
        return -1;
    }
    else{
        return s1->s[s1->top];
    }
}


