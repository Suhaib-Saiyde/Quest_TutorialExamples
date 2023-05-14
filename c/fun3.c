#include<stdio.h>
int sum(int,int);
void main()
{
int a,b,n;
printf("Enter two numbers:\n");
scanf("%d%d",&a,&b);
n=sum(a,b);
printf("The Sum=%d",n);
}
int sum(int x,int y)
{
int c;
c=x+y;
return c;
}
