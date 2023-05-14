#include<stdio.h>
int fact();
int n;
void main()
{
int a;
a=fact(n);
printf("factorial of %d= %d",n,a);
}
int fact()
{
int i,c=1;
printf("enter a number\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
c=c*i;
}
return c;
}
