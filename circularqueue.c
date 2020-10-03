#include<stdio.h>
#include<stdlib.h>
#define MAX 5
//simple que function


int insert(int [],int *, int *,int );
void display(int [],int *,int *);
int remve(int [],int *,int *);
//remove is a reserved key word and hence cannot be used


void main(){
    int choice;
    int q[MAX];
    int front=-1;int rear=-1;
    int x; 
    while(1){
        printf("\nEnter \n1 for Insert\n2 for Delete\n3 for DISPLAY\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            {
                printf("Enter the element to be inseted into the queue:");
                scanf("%d",&x);
                int k;
				k=insert(q,&front,&rear,x);
				if(k>0){
					printf("\nSuccessful Insertion\n");
				}
				else{
					printf("\nUnsuccessful insertion\n");
				}
            }break;
            case 2:{
				if(front==-1 && rear==-1){
					printf("Empty queue");
				}
				else{
					int y;
					y=remve(q,&front,&rear);
					printf("\nThe deleted element was: %d",y);
				}
                
            }break;
            case 3:
            {
                printf("The elements in the stack are:");
                display(q,&front,&rear);
            }break;
            default:{
                exit(0);
            }
        }
    }
}




int insert(int que[],int *f, int *r,int x)
{
    if(*r==(MAX-1)){
		printf("\nQueue Full");
		return -1;
	}
	else{
		if(*f==-1 && *r==-1){
			++(*f);
		}
		++(*r);
		que[*r]=x;	
	}
	return 1;
}



void display(int que[],int *f,int *r){
	int i;
	if(*f==-1 && *r==1)
	{
		printf("\nEmpty queue\n");
	}
	else{
		for(i=*f;i<=*r;i++){
			printf("\t%d",que[i]);
		}
	}
}

int remve(int que[],int *f,int *r){
	int x;
	if(*f==*r){
		x=que[*f];
		*f=-1;
		*r=-1;
	}
	else{
		x=que[*f];
		(*f)++;
	}
	
	return x;
}




