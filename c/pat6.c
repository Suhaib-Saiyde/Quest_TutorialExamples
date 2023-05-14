#include<stdio.h>
void main()
{
int n,i,j,k=65;
printf("enter a number\n");
scanf("%d",&n);
for(i=0;i<=n;i++)
{
	for(j=0;j<=i;j++)
	{
	 printf("%c",k);
	}
 printf("\n");
 k++;
}
}
