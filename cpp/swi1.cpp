#include<iostream>
using namespace std;
int main()
{
int n,a,b,c;
cout<<"Enter two numbers"<<endl;
cin>>a>>b;
cout<<"Enter 1-add 2-sub"<<endl;
cin>>n;
switch(n)
{
	case 1:
	{
	c=a+b;
	cout<<"The sum is"<<c<<endl;
	break;
	}

	case 2:
	{
	c=a-b;
	cout<<"The difference is"<<c<<endl;
	break;
	}

	default:
	{
	cout<<"Invalid entry"<<endl;
	break;
	}
}
}
