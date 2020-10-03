#include<stdio.h>
#include<stdlib.h>
void push(char, char*, int*);
char pop(char*, int*);
char peek(char*, int*);
void convert_postfix(char*, char*);
int stack_prec(char );
int input_prec(char );
void reverse(char *, int *, char *);

void main()
{
    char prefix[10];
    char infix[10];
    char s1[20];
    int top1=-1;
    printf("Enter a valid INFIX expression: ");
    scanf("%s",infix);
    //reverse the string
    reverse(s1,&top1,infix);

    convert_postfix(infix, prefix);
    //reverse the string
    reverse(s1,&top1,prefix);

    printf("The postfix expression is:%s",infix);
}

void convert_postfix(char *infix, char *postfix){
    char stk[10];
    char sym;
    int top=-1;
    push('#',stk,&top);
    int i=0;int j=0;
    while(infix[i!='\0'])
    {
        sym=infix[i];
        while(stack_prec(peek(stk,&top))>input_prec(sym)){
            postfix[j++]=pop(stk,&top);
        }
        if(stack_prec(peek(stk,&top))!=input_prec(sym))
            push(sym,stk,&top);
        else pop(stk,&top);
        i++;
    }
    while(peek(stk,&top)!='#')
    {
        postfix[j++]=pop(stk,&top);
    }
    postfix[j]='\0';
}

int input_prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 3;
        case '^':return 6;
        case '(':return 9;
        case ')':return 0;
        default:return 7;
    }
}

int stack_prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 4;
        case '^':return 5;
        case '(':return 0;
        case '#':return -1;
        default:return 8;
    }
}

void push(char ch,char *s, int *t){
    (*t)++;
    s[*t]=ch;
}

char pop(char *s,int *t){
    char x;
    x=s[*t];
    (*t)--;
    return x;
}

char peek(char *s,int *t){
    char x;
    x=s[*t];
    return x;
}

void reverse(char *s,int *t,char *infix){
    char x;int i=0;
    for(i=0;i<infix)
    for(i=0;infix[i]!='\0';i++){
        x=infix[i];
        push(x,s,t);
    }
    for(i=0;infix[i]!='\0';i--){
        x=pop(s,t);
        infix[i]=x;
    }
}


