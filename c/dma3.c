#include<stdio.h>
#include<stdlib.h>
void main()
{
int i,*p;
p=(int*)malloc(5*sizeof(int));
for(i=0;i<5;i++)
{
printf("Enter the elements\n");
scanf("%d",(p+i));
}
p=(int*)realloc(p,10*sizeof(int));
for(i=5;i<15;i++)
{
printf("Enter the elements\n");
scanf("%d",(p+i));
}
for(i=0;i<15;i++)
{
printf("%d ",*(p+i));
}
}
