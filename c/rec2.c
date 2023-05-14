#include<stdio.h>
int prime(int);
void main()
{
int a,c;
printf("enter a number: \n");
scanf("%d",&a);
c=prime(a);
if(c==1)
{
 printf("%d is a prime number",a);
}
else
{
 printf("%d is not a prime number",a);
}
}

int prime(int n)
{
int i,b=0;
for(i=1;i<n;i++)
{
 if(n%i==0)
  { 
   b++; 
  }
}

return b;
}
