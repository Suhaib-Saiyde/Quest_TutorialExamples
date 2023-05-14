#include<stdio.h>
void main()
{
char c[10];
char a[10];
int t,i,j,l=0,count=0;
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

for(i=0;i<=l;i++)
{
 printf("%c",c[i]);
}
printf("\n");


for(i=l-1,j=0;j<l;j++,i--)
{
 a[j]=c[i];
}
a[j]='\0';


for(j=0;j<l;j++)
{
 printf("%c",a[j]);
}
printf("\n");


for(i=0;i<l;i++)
{
 	if(c[i]!=a[i])
	{
	 printf("The strings are not palindrome.");
	 break;
	}
	else
	{
	 count++;
	}
}

if(count==l)
{
 printf("The strings are palindrome.");
}
}





