#include<stdio.h>
void main()
{
int n,i,b=0;
printf("enter a number: \n");
scanf("%d",&n);
for(i=1;i<n;i++)
{
 if(n%i==0)
  { 
   b++; 
  }
}
if(b==1)
{
 printf("%d is a prime number",n);
}
else
{
 printf("%d is not a prime number",n);
}

}
