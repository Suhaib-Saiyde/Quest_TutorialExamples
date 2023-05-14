#include<stdio.h>
struct student
{
char name[20];
int roll;
};
void main()
{
struct student s;
printf("enter a name and roll no ");
scanf("%[^\n]s",s.name);
scanf("%d",&s.roll);
printf("%s",s.name);
printf(" %d",s.roll);
}
