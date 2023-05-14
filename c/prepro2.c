#include<stdio.h>
#define cube(x) (x*x*x)
void main()
{
int b,n;
printf("Enter a number\n");
scanf("%d",&b);
n=cube(b++);
printf("%d %d",n,b);
}
