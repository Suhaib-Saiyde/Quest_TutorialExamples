#include<stdio.h>
struct employee
{
char name[20];
int ID;
};
void print(struct employee a)
{
printf("ID:- %d		Name:-%s",a.ID,a.name);
}
void main()
{
struct employee e;
printf("Enter the Employee Id\n");
scanf("%d",&e.ID);
printf("Enter the Name of Employee\n");
scanf(" %[^\n]s",e.name);
print(e);
}
