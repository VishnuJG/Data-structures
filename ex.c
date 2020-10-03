#include<stdio.h>
void f1(int a[]);
void f2(int *a);
int fact(int n);
void main()
{
    
    int z[]={1,2,3,4};
    f1(z);
    printf("\n%d %d %d %d",z[0],z[1],z[2],z[3]);
    f2(z);
    printf("\n%d %d %d %d",z[0],z[1],z[2],z[3]);
    printf("\n%d",fact(5));
}
void f1(int a[]) //only the base address in received i.e., the address of the 1st element is received
{
    a++;//here the reference is updated to the next element of the array
    *a=50;
}
void f2(int *a)
{
    a++;
    *a=65;
}

int fact(int n)
{
    
    return n==0? 1: n*fact(n-1);
}