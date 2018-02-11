// Adnar Lozano
// October 7, 2014
// CIS-17A: C++ Programming
// Chapter 5, Programming Challenge 17: Sales Bar Chart

#include <iostream>
#include <iomanip>

using namespace std;

int getArea(int);
int getArea(int, int);
int getPerimeter(int);
int getPerimeter(int, int);

void main()
{
	int side, length, width, selection;
	char chr;

	do
	{
		cout << "M A I N  M E N U" << endl;
		cout << "1. Square" << endl;
		cout << "2. Rectangle" << endl;
		cin >> selection;

		switch(selection)
		{
		case 1:
			cout << "Enter side: ";
			cin  >> side;
			cout << "Area: " 
				 << getArea(side) << endl;
			cout << "Perimeter: "
				 << getPerimeter(side) << endl;
			break;
		case 2:
			cout << "Enter length: ";
			cin  >> length;
			cout << "Enter width: ";
			cin  >> width;
			cout << "Area: " 
				 << getArea(length, width) << endl;
			cout << "Perimeter: "
				 << getPerimeter(length, width) << endl;
			break;
		}

		cout << "Continue (y/n)? ";
		cin >> chr;
	}while(chr == 'y');
	system("PAUSE");
}

int getArea(int s)
{
	return s * s;
}

int getArea(int l, int w)
{
	return l * w;
}

int getPerimeter(int s)
{
	return 4 * s;
}

int getPerimeter(int l, int w)
{
	return 2 * (l + w);
}