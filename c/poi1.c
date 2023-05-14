#include<stdio.h>
void main()
{
char *p,a;
p=&a;
printf("Enter a number\n");
scanf("%c",p);
printf("%c",*p);
}
