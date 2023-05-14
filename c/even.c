#include<stdio.h>
void main()
{
int n,i=1;
printf("enter a limit\n");
scanf("%d",&n);
do
{
 if(i%2==0)
 {
  printf("%d\n",i);
 }
 i++;
}while(i<=2*n);
}
