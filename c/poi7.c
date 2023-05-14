#include<stdio.h>
void sort(int *);
int n;
void main()
{
int c[10],*p,i;
printf("Enter a limit\n");
scanf("%d",&n);
p=c;
printf("Enter the elements\n");
for(i=0;i<n;i++)
{
scanf("%d",(p+i));
}
sort(p);
}
void sort(int *q)
{
int i,j,k;
for(j=0;j<n;j++)
{
	for(k=0;k<n-j-1;k++)
	{
		if(q[k]>q[k+1])
		{
		 q[k]=q[k]+q[k+1];
		 q[k+1]=q[k]-q[k+1];
		 q[k]=q[k]-q[k+1];
		 
		}
	}
}
for(i=0;i<n;i++)
{
printf("%d ",q[i]);	
}
}
