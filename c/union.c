#include<stdio.h>
union student
{
int roll;
char a;
};

void main()
{
int n;
union student u;
u.roll=50;
u.a='S';
printf(" %c	%d",u.a,u.roll);
}
