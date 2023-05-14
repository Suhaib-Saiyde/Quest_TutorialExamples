#include<stdio.h>
void main()
{
int n,q,r=0,c=0;
printf("enter a number\n");
scanf("%d",&n);
q=n;
while(q!=0)
{
 c=c*10;
 r=q%10;
 c=c+r;
 q=q/10;
}
if(n==c)
{
 printf("%d is a palindrome",n);
}
else
{
 printf("%d is not a palindrome",n);
}
}
