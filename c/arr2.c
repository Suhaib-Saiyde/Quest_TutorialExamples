#include<stdio.h>
void main()
{
int i,n;
char c[10];
printf("Enter a limit\n");
scanf("%d",&n);
printf("Enter the entries:\n");
for(i=0;i<n;i++)
{ 
 scanf("%d",&c[i]);
 
}
printf("[");
for(i=0;i<n;i++)
{
if(i==n-1)
{
 printf("%d",c[i]); 
}
else
{
printf("%d,",c[i]);
}
}
printf("]");
}
