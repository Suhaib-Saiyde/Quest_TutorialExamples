#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
void main()
{
FILE *fp;
char a[10];
fp=fopen("test.txt","r");
fscanf(fp,"%[^EOF]s",a);
fclose(fp);
printf("%s",a);
}
