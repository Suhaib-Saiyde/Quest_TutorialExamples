#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
void main()
{
FILE *fp;
char a[10];
printf("enter string ");
scanf("%s",a);
fp=fopen("test.txt","a");
fprintf(fp," %s",a);
fclose(fp);
}
