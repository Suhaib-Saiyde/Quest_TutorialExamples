#include<stdio.h>
void main()
{
int n,i,j,c=0;
printf("enter a limit value: \n");
scanf("%d",&n);

for(j=2;j<n;j++)
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
printf("%d ",j);
}
c=0;
}

}
