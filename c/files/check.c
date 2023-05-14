#include<stdio.h>
#include<string.h>
void main()
{
char a[10],b[10],ch;
int l,n,i=0,flag=0,c=0;
FILE *f1;
printf("enter a word\n");
scanf("%s",a);
l=strlen(a);
f1=f1open("text.txt","r");
for(ch=fgetc(f1);ch!=EOF;ch=fgetc(f1))
{
printf("%c%c\n",ch,a[10]);
	if(ch==' ')
	{
	i=0;
	flag=0;
	}
	if(ch==a[0])
	{
	flag=1;
	}
	
	if(flag==1)
	{
	b[i]=ch;
	i++;
	}
printf("\n%d\n\n",i);
	if(i==l)
	{
	b[i]='\0';
		n=strcmp(a,b);
		if(n==0)
		{
		printf("word found\n");
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
