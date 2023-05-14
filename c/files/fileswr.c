#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
void main()
{
FILE *fp;
char a[10];
printf("enter string ");
scanf("%[^\n]s",a);
fp=fopen("test.txt","w");
fprintf(fp,"%s",a);
fclose(fp);

fp=fopen("test.txt","r");
fscanf(fp,"%[^EOF]s",a);
fclose(fp);
printf("%s",a);

}
