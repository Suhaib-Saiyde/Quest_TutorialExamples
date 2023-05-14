#include<stdio.h>
void main()
{
int n,i,j,c=1;
printf("Enter the limit.\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	for(j=0;j<n-i-1;j++)
	{
	printf(" ");
	}
	for(j=0;j<=i;j++)
	{
		if(j==0||i==0)
		{
		c=1;
		printf("%d ",c);
		}
		else
		{
		c=c*(i-j+1)/j;
		printf("%d ",c);
		}
	}
printf("\n");
}
}
