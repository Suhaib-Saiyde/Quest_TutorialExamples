#include<stdio.h>
struct student
{
char name[20];
int roll;
float maths,phy,che,total,avg,percentage;
};
void main()
{
int n,i,j;
struct student s[2],temp;
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
printf("roll no  maths  phy   che   total   avg   percentage");
printf("  name\n");
for(i=0;i<n;i++)
{
	for(j=0;j<n-i-1;j++)
	{
		if(s[j].total<s[j+1].total)
		{
		temp=s[j];
		s[j]=s[j+1];
		s[j+1]=temp;
		}
	}
printf("%d",s[i].roll);
printf("        %.1f",s[i].maths);
printf("   %.1f",s[i].phy);
printf("  %.1f",s[i].che);
printf("  %.1f",s[i].total);
printf("   %.1f",s[i].avg);
printf("  %.1f",s[i].percentage);
printf("        %s\n",s[i].name);
}
}
