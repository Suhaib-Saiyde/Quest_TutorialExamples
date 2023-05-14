#include<stdio.h>
void main()
{
char c[10];
int i,j=0;
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
for(i=0;c[i]!='\0';i++)
{
 printf("%c",c[i]);
}
printf("\n");
printf("The length of string is %d\n",j);
}
