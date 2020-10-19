  #include<stdio.h>
  #include<stdlib.h>
  
  // function prototypes
   void display(int *,int);
   void heapify(int *, int);
   int maxremove(int*, int*);
   void adjust(int *,int);
    
 void main()
 {
  int count,num,i;
  int h[20];

  printf("Enter the no of elements");
  scanf("%d", &count);

  printf("Enter the elements..");
  for(i=0;i<count;i++)
    scanf("%d", &h[i]);
  
  printf("\n\tBefore heap is created.....");
  display(h,count);
  
  heapify(h,count);
  
  printf("\n\tAfter heap is created.....");
  display(h,count);
  
  num=maxremove(h,&count);
  printf("The maximum element removed..%d\n",num);
  
  printf("New Heap after removal of the max element is");
  display(h,count);
  
 }

 void heapify(int *h, int count)
 {
	int i,j,k,key;
    // every element in the tree	
	for(k=1;k<count;k++)
	{ i=k;
	  key=h[i];
	  j=(i-1)/2;
	  
	  while((i>0)&&(h[j]<key))
	  {
		h[i]=h[j];
		i=j;
		j=(i-1)/2;
	  }
	  h[i]=key;
	}
 }

void display(int *h,int count)
{
  int i;
  for (i=0;i<count;i++)
   printf("\t%d",h[i]);	  
}

int maxremove(int *h, int *count)
{
	// fill the code
}

void adjust(int *h,int count)
{
	
	// fill the code
	
}