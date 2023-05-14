#include<stdio.h>
#include<stdlib.h>
void main()
{
char a[100],ch;
FILE *fp,*f1,*f2,*f3;
printf("enter string ");
scanf("%[^\n]s",a);
fp=fopen("sort.txt","w");
fprintf(fp,"%s",a);
fclose(fp);
fp=fopen("sort.txt","r");
f1=fopen("char.txt","w");
f2=fopen("num.txt","w");
f3=fopen("spl.txt","w");
for(ch=fgetc(fp);ch!=EOF;ch=fgetc(fp))
{
	if(ch>64 && ch<91)
	{
	fprintf(f1,"%c",ch);
	}
	else if(ch>96 && ch<123)
	{
	fprintf(f1,"%c",ch);
	}
	else if(ch>44 && ch<58)
	{
	fprintf(f2,"%c",ch);
	}
	else
	{
	fprintf(f3,"%c",ch);
	}
}
fclose(f3);
fclose(f2);
fclose(f1);
fclose(fp);
}
