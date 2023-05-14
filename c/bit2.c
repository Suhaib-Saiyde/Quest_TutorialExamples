#include<stdio.h>
void main()
{
int n,i,flag=0;
printf("Enter a Number.\n");
scanf("%d",&n);
for(i=7;i>=0;i--)
{
	if(((n&(1<<i))>>i)==1)
	{
	printf("1");
	flag++;
	}
	else
	{
	printf("0");
	}
}
printf("\n");
if(flag%2!=0)
{
printf("%d is odd parity.\n",n);
}
else
{
printf("%d is even parity.\n",n);
}


}
