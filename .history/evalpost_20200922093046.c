#include <stdio.h>
#include <stdlib.h>

void push(int,int*,int*);
char pop(int*,int*);
int pevaluate(char *);
int isoper(char);

void main()
{
	char postfix[20];
	int ch,r;
	
	printf("Enter a valid postfix expression");
	scanf("%s",postfix);
	r=pevaluate(postfix);
	printf("The value of the expression is %d\t",r);
}
	
void push(int ch,int *s,int *t)
    {    
	 (*t)++;
	 s[*t]=ch; 
	 }

char pop(int *s,int *t)
{   char x;
      x= s[*t];
	  (*t)--;
	return x;
}

int pevaluate(char *postfix)
{
	 int i,top,r,s[20];
	 top=-1;
	 i=0;
	 
	 while(postfix[i]!='\0')
	 {
		char ch=postfix[i];
		if (isoper(ch))
		{
			int op1=pop(s,&top);
			int op2=pop(s,&top);
			
			switch(ch)
			{
				case '+': r = op1+op2;
				          break;
				case '-': r = op2-op1;
				          break;
				case '*': r = op1*op2;
				          break;
				case '/': r = op2/op1;
				          break;
			}
			push(r,s,&top);
		}
		else push(ch-'0',s,&top);
	    i++;
		}
		return (pop(s,&top));
}

int isoper(char ch)
{
	if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/'))
		return 1;
	else 
		return 0;
}

