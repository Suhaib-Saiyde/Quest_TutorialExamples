#include<stdio.h>
#include<stdlib.h>
struct student
{
char name[20];
int roll;
float maths,phy,che,total,avg,percentage;
};
void main()
{
FILE *fp;
int n,i,j;
struct student s[2];
printf("enter total no of students ");
scanf("%d",&n);
printf("enter student roll no,marks of maths,phy,che and name ");
for(i=0;i<n;i++)
{
scanf("%d",&s[i].roll);
scanf("%f",&s[i].maths);
scanf("%f",&s[i].phy);
scanf("%f",&s[i].che);
s[i].total=s[i].maths+s[i].phy+s[i].che;
s[i].avg=(s[i].maths+s[i].phy+s[i].che)/3;
s[i].percentage=((s[i].maths+s[i].phy+s[i].che)/300)*100;
scanf("%s",s[i].name);
}
fp=fopen("list.txt","w");
fprintf(fp,"roll no  maths  phy   che   total   avg   percentage");
fprintf(fp,"  name\n");
for(i=0;i<n;i++)
{
fprintf(fp,"%d",s[i].roll);
fprintf(fp,"        %.1f",s[i].maths);
fprintf(fp,"   %.1f",s[i].phy);
fprintf(fp,"  %.1f",s[i].che);
fprintf(fp,"  %.1f",s[i].total);
fprintf(fp,"   %.1f",s[i].avg);
fprintf(fp,"  %.1f",s[i].percentage);
fprintf(fp,"        %s\n",s[i].name);
}
fclose(fp);
}
