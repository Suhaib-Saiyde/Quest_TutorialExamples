#include<stdio.h>
int fact(int);
void main()
{
int n,x;
printf("Enter a number:\n");
scanf("%d",&n);
x=fact(n);
printf("Factorial of %d is %d",n,x);
}

int fact(int a)
{
int f;
	if(a==0)
	{
	return 1;
	}
	else
	{
	f=a*fact(a-1);
	return f;
	}
}
