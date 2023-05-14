#include<stdio.h>
void main()
{
int a,b,c,n,i,j,k;
printf("enter a number\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	for(j=0;j<=n-i-1;j++)
	{
	 printf(" ");
	}
	for(k=0;k<=2*i;k++)
	{
	 printf("*");
	}
 printf("\n");
}
for(a=n;a>=0;a--)
{
	for(b=0;b<=n-a-1;b++)
	{
	 printf(" ");
	}
	for(c=0;c<=2*a;c++)
	{
	 printf("*");
	}
 printf("\n");
}
}
