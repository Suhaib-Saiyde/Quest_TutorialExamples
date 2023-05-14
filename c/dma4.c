#include<stdio.h>
#include<stdlib.h>
void main()
{
int i,*p;
p=(int*)malloc(5*sizeof(int));
printf("Enter 5 elements\n");
for(i=0;i<5;i++)
{
scanf("%d",(p+i));
}
p=(int*)malloc(5*sizeof(int));
printf("Enter 5 elements\n");
for(i=0;i<5;i++)
{
scanf("%d",(p+i));
}
for(i=0;i<5;i++)
{
printf("%d",*(p+i));
}
}
