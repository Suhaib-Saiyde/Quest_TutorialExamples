#include<stdio.h>
#include"oper1.h"
void main()
{
int x,y,n;
float a,b;
printf("Press 1.add	2.sub	3.mul	4.div\n");
scanf("%d",&n);
switch(n)
{
	case 1:
		{
		printf("Enter the numbers\n");
		scanf("%d%d",&x,&y);
		add(x,y);
		break;
		}
	case 2:
		{
		printf("Enter the numbers\n");
                scanf("%d%d",&x,&y);
		sub(x,y);
		break;
		}
	case 3:
		{
		printf("Enter the numbers\n");
                scanf("%d%d",&x,&y);
		mul(x,y);
		break;
		}
	case 4:
		{
		printf("Enter the numbers\n");
                scanf("%f%f",&a,&b);
		div(a,b);
		break;
		}
	default:
		{
		printf("Invalid Entry\n");
		}
}
}
