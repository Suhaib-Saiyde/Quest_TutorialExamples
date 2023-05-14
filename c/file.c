#include<stdio.h>
#include<string.h>
void main()
{
char a[20],b[20],ch;
int l,n,i=0,flag=0,c=0;


printf("Enter a string.\n");
scanf(" %[^\n]s",a);
l=strlen(a);

FILE *f;
f=fopen("test.txt","r");
for(ch=fgetc(f);ch!=EOF;ch=fgetc(f))
{
	if(ch==' ')
	{i=0;
	flag=0;}
	if(ch==a[0])
	{
	flag=1;
	}
	
	if(flag==1)
	{
	b[i]=ch;
	i++;
	}

	if(i==l)
	{
	b[i]='\0';
		n=strcmp(a,b);
		if(n==0)
		{
		printf("word is present\n");
		flag=0;
		i=0;
		c=1;
		break;
		}
		else
		{
		flag=0;
		i=0;
		}
	}
}

if(c==0)
{
printf("word not found\n");
}

}
