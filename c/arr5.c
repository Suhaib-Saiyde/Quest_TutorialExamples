#include<stdio.h>
void main()
{ int a[5][5],b[5][5],d[5][5]={0},i,j,k,r,c,p,q;
printf("Enter the number of rows for 1st\n");
scanf("%d",&r);
printf("Enter the number of coloumns for 1st\n");
scanf("%d",&c);
printf("Enter the elements\n");
for(i=0;i<r;i++)
{
	for(j=0;j<c;j++)
	{
	scanf("%d",&a[i][j]);
	}
}
printf("Enter the number of rows for 2nd\n");
scanf("%d",&p);
printf("Enter the number of coloumns for 2nd\n");
scanf("%d",&q);
printf("Enter the elements\n");
for(i=0;i<p;i++)
{
	for(j=0;j<q;j++)
	{
	scanf("%d",&b[i][j]);
	}
}
if(c==p)
{
for(i=0;i<r;i++)
{
	for(j=0;j<q;j++)
	{
		for(k=0;k<c;k++)
		{
		d[i][j]=d[i][j]+a[i][k]*b[k][j];	
		}
	}
}
for(i=0;i<r;i++)
{
	for(j=0;j<q;j++)
	{
	printf("%d ",d[i][j]);
	}
	printf("\n");
}
}
else
{
printf("ERROR\n");
}
}
