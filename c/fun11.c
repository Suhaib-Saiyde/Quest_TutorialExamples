#include<stdio.h>
int fact(int);
void main()
{
int n,a;
printf("enter a number\n");
scanf("%d",&n);
a=fact(n);
printf("factorial of %d= %d",n,a);
}
int fact(int x)
{
int i,c=1;

for(i=1;i<=x;i++)
{
c=c*i;
}
return c;
}

