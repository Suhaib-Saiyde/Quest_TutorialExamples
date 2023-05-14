#include<stdio.h>
void main()
{
 int n,i,j,k,c=0,r=0;
printf("enter a value: \n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	for(j=1;j<=n-i;j++)
	{
 	printf("  ");
	c++;
	}
	for(k=0;k<2*i-1;k++)
	{
	 	if(c<=n-1 )
		{
		printf("%d ",i+k);
		c++;
		}
		else
		{
		r++;
		printf("%d ",(i+k-2*r));
		}
	}
r=c=k=0;
printf("\n");
}
}
