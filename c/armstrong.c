#include<stdio.h>
void main()
{
int e,n,r,p,k,u,v,c,s=0;
printf("enter a three digit number\n");
scanf("%d",&e);
n=e;
r=n%10;
c=r*r*r;
n=n/10;
p=n%10;
k=p*p*p;
n=n/10;
u=n%10;
v=u*u*u;
s=c+k+v;
if(e==s)
 {
  printf("The number is an Armstrong number\n");
 }
else
 {
  printf("The number is not an Armstrong number\n");
 }
}
