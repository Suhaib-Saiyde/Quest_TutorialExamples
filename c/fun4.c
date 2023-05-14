#include<stdio.h>
int sum()
{
int a,b,c;
printf("Enter two numbers:\n");
scanf("%d%d",&a,&b);
c=a+b;
return c;
}
void main()
{
int n;
n=sum();
printf("The sum=%d",n);
}
