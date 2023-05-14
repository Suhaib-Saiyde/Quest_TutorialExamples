#include<stdio.h>
void main()
{
char a[10];
printf("Enter a word\n");
scanf(" %[^\n]s",a);
printf("%s",a);
}
