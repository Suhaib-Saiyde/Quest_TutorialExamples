#include<iostream>
using namespace std;

class room
{

private:
	double length;
	double breadth;
	double height;
public:
	void getdata(double len,double brth,double hght)
	{
	length=len;
	breadth=brth;
	height=hght;
	}
	double calcarea()
	{		
	return length*breadth;	
	}

	double calcvolume()
	{
	return length*breadth*height;
	}

};

int main()
{
room r1;

r1.getdata(42.5,30.8,19.2);

cout<<"Area of room="<<r1.calcarea()<<endl;
cout<<"Volume of room="<<r1.calcvolume()<<endl;

return 0;
}
