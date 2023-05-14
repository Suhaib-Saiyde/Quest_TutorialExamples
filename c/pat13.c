#include<stdio.h>
void main()
{
int n,i,j,k,a=65;
printf("Enter a number:\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	for(j=n-i;j>0;j--)
	{
	printf(" ");
	}
printf("%c",a);
	for(k=2;k<2*i-1;k++)
	{
 	printf(" ");
	}
if(i!=1)
{
printf("%c",a);
}
a++;
printf("\n");
}
}
