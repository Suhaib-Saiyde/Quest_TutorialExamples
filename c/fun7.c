#include<stdio.h>
int prime(int);
void main()
{
int n,a;
printf("enter a number:\n");
scanf("%d",&n);
a=prime(n);
if(a==1)
{
 printf("%d is a prime number",n);
}
else
{
 printf("%d is not a prime number",n);
}
}
int prime(int x)
{
int i,b=0;
for(i=1;i<x;i++)
{
 if(x%i==0)
  { 
   b++; 
  }
}
return b;
}

