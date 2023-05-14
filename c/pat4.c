#include<stdio.h>
void main()
{
int k,n,i,j;
printf("enter a number\n");
scanf("%d",&n);
for(i=n;i>=0;i--)
{
	for(j=0;j<=n-i-1;j++)
	{
 	 printf(" ");
	}
	for(k=0;k<i;k++)
	{
	 printf("*");
	}
	printf("\n");
}

}
