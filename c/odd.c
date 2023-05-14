#include<stdio.h>
void main()
{
int n,i,b=0;
printf("enter a limit\n");
scanf("%d",&n);
for(i=1;b<n;i++)
{
 if(i%2!=0)
 {
  printf("%d\n",i);
  b++;
 }
}

}
