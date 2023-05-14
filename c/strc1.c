#include<stdio.h>
struct student
{
char name[50];
int roll;
float mark1,mark2,mark3,total,avg,perc;
};
void main()
{
int j,k,n,i,c=1;
struct student s[50],temp;
printf("Enter the number of Students\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the roll number\n");
scanf("%d",&s[i].roll);
printf("Enter the name of student\n");
scanf(" %[^\n]s",s[i].name);
printf("Enter the mark for 1st paper\n");
scanf("%f",&s[i].mark1);
printf("Enter the mark for the 2nd paper\n");
scanf("%f",&s[i].mark2);
printf("Enter the mark for 3rd paper\n");
scanf("%f",&s[i].mark3);
s[i].total=s[i].mark1+s[i].mark2+s[i].mark3;
s[i].avg=s[i].total/3;
s[i].perc=(s[i].total/300)*100;
}
for(j=0;j<n;j++)
{
	for(k=0;k<n-j-1;k++)
	{
		if(s[k].total<s[k+1].total)
		{
		 temp=s[k];
		 s[k]=s[k+1];
		 s[k+1]=temp;
		 
		}
	}
}
FILE *fp;
fp=fopen("Class.txt","w");
fprintf(fp,"Sl No.  Roll Number  Name               Mark 1  Mark 2  Mark 3  Total  Average  Percentage");
fprintf(fp,"\n");
for(i=0;i<n;i++)
{
fprintf(fp,"%d.      %d            %s             %.2f   %.2f   %.2f  %.2f  ",c,s[i].roll,s[i].name,s[i].mark1,s[i].mark2,s[i].mark3,s[i].total);
fprintf(fp,"%.2f   %.2f",s[i].avg,s[i].perc);
fprintf(fp,"\n");
c++;
}
fclose(fp);
}
