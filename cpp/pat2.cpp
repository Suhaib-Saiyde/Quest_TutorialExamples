#include<iostream>
using namespace std;

int main()
{
int n,i,j,k;
cout<<"Enter the limit"<<endl;
cin>>n;
i=n;
do
{
i--;
	j=0;
	while(j<=n-i-1)
	{
	j++;
	cout<<' ';
	}

	k=0;
	while(k<i)
	{
	k++;
	cout<<'*';
	}
cout<<"\n";
}while(i>=0);
}
