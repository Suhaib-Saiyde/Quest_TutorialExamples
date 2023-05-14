#include<stdio.h>
void fact(int);
void main()
{
int n;
printf("enter a number\n");
scanf("%d",&n);
fact(n);
}
void fact(int x)
{
int i,c=1;

for(i=1;i<=x;i++)
{
c=c*i;
}
printf("factorial of %d= %d",x,c);
}

