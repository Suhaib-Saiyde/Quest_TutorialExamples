#include<iostream>
using namespace std;

class room
{

public:
	double length;
	double breadth;
	double height;

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

r1.length=42.5;
r1.breadth=30.8;
r1.height=19.2;

cout<<"Area of room="<<r1.calcarea()<<endl;
cout<<"Volume of room="<<r1.calcvolume()<<endl;

return 0;
}
