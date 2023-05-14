#include<stdio.h>
int main()
{
	int i,j,k,r,c1=0,c2=0;
	printf("enter the rows\n");
	scanf("%d",&r);
	for(i=0;i<=r;i++)
	{
		for(j=1;j<=r-i;j++)
		{
		printf(" ");
		c1++;
		}
		for(k=0;k<2*i-1;k++)
		{
			if(c1<=r-1)
			{
				printf("%d",i+k);
				c1++;
			}
			else
			{	
				c2++;
				printf("%d",(i+k-2*c2));
			}
		}
		c1=c2=k=0;
		printf("\n");
	}
}
		
