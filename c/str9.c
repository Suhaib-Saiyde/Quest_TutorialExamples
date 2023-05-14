#include<stdio.h>
#include<string.h>
void main()
{
int n;
char a[20],b[20],c[20];
printf("Enter a word\n");
scanf(" %[^\n]s",a);
for(n=0;n<strlen(a);n++)
{
printf("%c",strrev(a));
}
}
