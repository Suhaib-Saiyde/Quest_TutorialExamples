#include<stdio.h>
void main()
{
int n,i,c=1;
printf("enter a number\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
c=c*i;
}
printf("factorial of %d= %d",n,c);
}
