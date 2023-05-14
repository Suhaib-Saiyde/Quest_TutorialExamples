#include<stdio.h>
void prime(int);
void main()
{
int n;
printf("enter a number:\n");
scanf("%d",&n);
prime(n);
}
void prime(int x)
{
int i,b=0;
for(i=1;i<x;i++)
{
 if(x%i==0)
  { 
   b++; 
  }
}
if(b==1)
{
 printf("%d is a prime number",x);
}
else
{
 printf("%d is not a prime number",x);
}
}

