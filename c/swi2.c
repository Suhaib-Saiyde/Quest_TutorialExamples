#include<stdio.h>
void main()
{
char n;
int a,b,c;
printf("Enter two numbers:\n");
scanf("%d,%d",&a,&b);
printf("Enter K-Add G-sub:\n");
scanf(" %c",&n);
switch(n)
{
	case 'K':
	{
	 c=a+b;
	 printf("%d",c);
	 break;
	}
	case 'G':
	{
	 c=a-b;
 	 printf("%d",c);
 	 break;
	}
	default:
	{
	 printf("Invalid Entry");
	}
}
}
