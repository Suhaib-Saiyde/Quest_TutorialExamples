#include<stdio.h>
int prime();
int n;
void main()
{
int a;
a=prime();
if(a==1)
{
 printf("%d is a prime number",n);
}
else
{
 printf("%d is not a prime number",n);
}
}
int prime()
{
int i,b=0;
printf("enter a number: \n");
scanf("%d",&n);
for(i=1;i<n;i++)
{
 if(n%i==0)
  { 
   b++; 
  }
}
return b;

}
