#include<stdio.h>
void main()
{
int n;
printf("enter a number:\n");
scanf("%d",&n);
if(n%5==0)
{
 if(n%2==0)
  {
   printf("The number is divisible by 2 and 5\n");
  }
 else
  {
   printf("The number is divisible only by 5\n");
  }
}
else 
{
 if(n%2==0)
  {
   printf("The number is divisible only by 2\n");
  }
 else
  {
   printf("The number is not divisible by 2 and 5\n");
  }
}
}
