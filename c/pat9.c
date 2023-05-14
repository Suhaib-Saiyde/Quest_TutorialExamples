#include<stdio.h>
void main()
{
int n,i,j,k;
printf("enter a number\n");
scanf("%d",&n);
for(i=0;i<=n;i++)
{
	for(j=2*(n-i);j>0;j--)
	{
	 printf(" ");
	}
	for(k=0;k<=2*i;k++)
	{
	 printf("* ");
	}
 printf("\n");
}
}
