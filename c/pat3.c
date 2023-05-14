#include<stdio.h>
void main()
{
int n,i,j;
printf("enter a number");
scanf("%d",&n);
for(i=n;i>=0;i--)
{
	for(j=0;j<i;j++)
	{
	printf("*");
	}
	printf("\n");
}
}
