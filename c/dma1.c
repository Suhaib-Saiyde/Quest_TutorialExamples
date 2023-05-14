#include<stdio.h>
#include<stdlib.h>
void main()
{
int i,*p;
p=(int*)malloc(10*sizeof(int));
printf("Enter 10 elements\n");
for(i=0;i<10;i++)
{
scanf("%d",(p+i));
}
for(i=0;i<10;i++)
{
printf("%d",*(p+i));
}
}
