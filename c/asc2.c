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
	for(k=j+1;k<=n;k++)
	{
		if(c[j]>c[k])
		{
		 c[j]=c[j]+c[k];
		 c[k]=c[j]-c[k];
		 c[j]=c[j]-c[k];
		 
		}
	}
printf("%d ",c[j]);	
}
printf("]");
}
