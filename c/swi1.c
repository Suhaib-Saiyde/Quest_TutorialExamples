#include<stdio.h>
void main()
{
int n,a,b,c;
printf("Enter two numbers;\n");
scanf("%d,%d",&a,&b);
printf("Enter 1-add 2-sub\n");
scanf("%d",&n);
switch(n)
{
	case 1:
	{
	 c=a+b;
	 printf("%d",c);
	 break;
	}
	case 2:
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
