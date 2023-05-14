#include<stdio.h>
void main()
{
int c[10],*p,n,i,j,k;
printf("Enter a limit\n");
scanf("%d",&n);
p=c;
printf("Enter the elements\n");
for(i=0;i<n;i++)
{
scanf("%d",(p+i));
}
for(j=0;j<n;j++)
{
	for(k=0;k<n-j-1;k++)
	{
		if(c[k]>c[k+1])
		{
		 c[k]=c[k]+c[k+1];
		 c[k+1]=c[k]-c[k+1];
		 c[k]=c[k]-c[k+1];
		 
		}
	}
}
for(i=0;i<n;i++)
{
printf("%d ",*(p+i));	
}
}
