#include<stdio.h>
void sum(int,int);
void main()
{
int a,b,*p,*q;
p=&a;
q=&b;
printf("Enter two numbers;\n");
scanf("%d%d",p,q);
sum(*p,*q);
}
void sum(int x,int y)
{
 int c;
c=x+y;
printf("The Sum=%d",c);
}
