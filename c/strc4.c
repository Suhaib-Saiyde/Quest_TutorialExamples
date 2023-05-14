#include<stdio.h>
struct student
{
int data[10],*p;
};
void main()
{
struct student s;
s.p=s.data;
int n,i;
printf("Enter a number\n");
scanf("%d",&n);
printf("Enter the numbers\n");
for(i=0;i<n;i++)
{
scanf("%d",(s.p+i));
}
for(i=0;i<n;i++)
{
printf("%d",*(s.p+i));
}
}
