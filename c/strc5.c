#include<stdio.h>
struct address
{
int house_no;
};
struct employee
{
char name[20];
int id;
struct address a;
};
void main()
{
struct employee e;
printf("Enter the Name of Employee\n");
scanf(" %[^\n]s",e.name);
printf("Enter the Employee ID\n");
scanf("%d",&e.id);
printf("Enter the House Number\n");
scanf("%d",&e.a.house_no);
printf("ID:-%d		Name:-%s	House Number:-%d",e.id,e.name,e.a.house_no);
}
