#include<stdio.h>
#include<stdlib.h>
void main()
{
FILE *fp;
char ch;
fp=fopen("pgm.c","r");
for(ch=fgetc(fp);ch!=EOF;ch=fgetc(fp))
{
printf("%c",ch);
}
fclose(fp);
}
