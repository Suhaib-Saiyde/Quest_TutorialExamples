#include<stdio.h>
int sum(int *,int *);
void main()
{
int a,b,n,*p,*q;
p=&a;
q=&b;
printf("Enter two numbers:\n");
scanf("%d%d",p,q);
n=sum(p,q);
printf("The Sum=%d",n);
}
int sum(int *x,int *y)
{
int c,*r;
r=&c;
*r=*x+*y;
return *r;
}
