#include<iostream>
using namespace std;
int main()
{
int n,i,j;
cout<<"enter a number"<<endl;
cin>>n;
for(i=0;i<=n;i++)
{
	for(j=0;j<i;j++)
	{
	cout<<'*';
	}
	cout<<"\n";
}
}
