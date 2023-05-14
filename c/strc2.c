#include<stdio.h>
struct student
{
int data;
};
void main()
{
struct student s[10],*p;
int n,i;
p=s;
printf("Enter a limit\n");
scanf("%d",&n);
printf("Enter the value\n");
for(i=0;i<n;i++)
{
scanf("%d",&(p+i)->data);
}
for(i=0;i<n;i++)
{
printf("%d ",(p+i)->data);
}
}
