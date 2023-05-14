#include<stdio.h>
void main()
{
int n,i,j,k=65;
printf("enter a number\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	for(j=0;j<i;j++)
	{
	 printf("%c",k);
	 k++;
	}
 printf("\n");
}
}
