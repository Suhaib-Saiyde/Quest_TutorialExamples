#include<stdio.h>
struct student
{
int data;
char a[10];
};
void main()
{
struct student s,*p;
p=&s;
printf("Enter the value\n");
scanf("%d",&p->data);
printf("Enter a Name\n");
scanf(" %[^\n]s",p->a);
printf("%d	%s",p->data,p->a);

}
