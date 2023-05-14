#include<iostream>
using namespace std;

int main()
{
int j,n,c=0,r=0,mul=1,cnt,rem,q,i;
cout<<"enter a limit"<<endl;
cin>>n;
for(i=1;i<=n;i++)
{
q=i;
	while(q!=0)
	{
	q=q/10;
	c++;
	}
cnt=c;
q=i;
	while(q!=0)
	{
	rem=q%10;
		for(j=0;j<cnt;j++)
		{	
		mul=mul*rem;
		}
	r=r+mul;
	q=q/10;
	mul=1;
	}

if(r==i)
{
cout<<r<<endl;
c=r=cnt=0;
mul=1;
}
else
{
c=r=cnt=0;
mul=1;
}
}
}
