#include<stdio.h>
void main()
{
char c[10];
char a[10];
int i,j,l=0;
printf("Enter a string\n");
for(i=0;;i++)
{ 
 scanf(" %c",&c[i]);
 	if(c[i]=='1')
 	{
	 c[i]='\0';
	 break;
 	}
l++;
}
for(j=0;j<l;j++)
{
 a[j]=c[j];
}
a[j]='\0';
for(j=l;j>=0;j--)
{
 printf("%c",a[j]);
}
}
