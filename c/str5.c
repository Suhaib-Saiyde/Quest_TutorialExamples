#include<stdio.h>
void main()
{
char c[10];
char a[10];
int t,i,j=0,k=0,count=0;
printf("Enter a string\n");
for(i=0;;i++)
{ 
 scanf(" %c",&c[i]);
 	
	if(c[i]=='1')
 	{
	 c[i]='\0';
	 break;
 	}
 j++;
}
printf("Enter a string\n");
for(t=0;;t++)
{ 
 scanf(" %c",&a[t]);
 	
	if(a[t]=='1')
 	{
	 a[t]='\0';
	 break;
 	}
 k++;
}	
if(j==k)
{
	for(i=0;i<j;i++)
	{
		if(a[i]!=c[i])
		{
		 printf("The string are not same\n");
		 break;
		}
		else
		{
		count++;
		}
	}
	if(count==j)
	{
	printf("The strings are Same.\n");
	}

}
else
{
 printf("The strings are not same\n");
}
}
