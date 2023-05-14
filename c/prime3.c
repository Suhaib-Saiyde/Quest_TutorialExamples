#include<stdio.h>
void main()
{
int n,i,j,b=0,c=0;
printf("enter a limit value; \n");
scanf("%d",&n);
for(j=2;b<n;j++)
	{
		for(i=1;i<j;i++)
		{
		 if(j%i==0)
			{
			 c++;
			}
		}
		if(c==1)
		{
		 printf("%d\n",j);
		 b++;
		}
		c=0;
	}

}
