#include<stdio.h>
void main()
{
int n;
printf("Enter a year:\n");
scanf("%d",&n);
if(n%4==0&&n%100!=0||n%400==0)
{
 printf("%d is a leap year.\n",n);
}
else
{
printf("%d is not a leap year.\n",n);
}
}
