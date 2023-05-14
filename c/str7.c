#include<stdio.h>
#include<string.h>
void main()
{
char s[20];
char a[20];
int i,j,l=0,k;
printf("Enter a string\n");
scanf(" %[^\n]s",s);
for(i=0;;i++)
{
	if(s[i]==' ')
	{
		for(j=i-1,k=l;j>=l;j--,k++)
		{
		a[k]=s[j];
		}
		a[k]=' ';
		l=k+1;
	}
	if(s[i]=='\0')
	{
		for(j=i-1,k=l;j>=l;j--,k++)
		{
		a[k]=s[j];
		}
		a[k]='\0';
		break;
	}
}
printf("%s",a);
}
