#include<stdio.h>
void main()
{
int a[10],*p,n,i;
p=a;
printf("Enter a number\n");
scanf("%d",&n);
printf("Enter the numbers\n");
for(i=0;i<n;i++)
{
 scanf("%d",(p+i));
}
for(i=0;i<n;i++)
{
 printf("%d ",*(p+i));
}
}
