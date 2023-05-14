#include<stdio.h>
void main()
{
int c[10];
int i,j,n,k;
printf("Enter a limit value\n");
scanf("%d",&n);
printf("Enter the numbers\n");
for(i=0;i<n;i++)
{
 scanf("%d",&c[i]);
}
printf("[");
for(j=0;j<n;j++)
{
	for(k=0;k<n-j-1;k++)
	{
		if(c[k]<c[k+1])
		{
		 c[k]=c[k]+c[k+1];
		 c[k+1]=c[k]-c[k+1];
		 c[k]=c[k]-c[k+1];
		 
		}
	}
printf("%d ",c[k]);	
}
printf("]");
}
