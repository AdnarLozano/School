// Adnar Lozano
// CIS-17A: C++ Programming
// September 25, 2014

#include <iostream>
using namespace std;

void main()
{
	int length1, width1, area1;
	int length2, width2, area2;

	cout << "Length Rec1: ";
	cin >> length1;

	cout << "Width1: ";
	cin >> width1;

	area1 = length1 * width1;

	cout << "Length Rec2: ";
	cin >> length2;

	cout << "Width2: ";
	cin >> width2;

	area2 = length2 * width2;

	if (area1 > area2)
	{
		cout << "Rectangle 1 is larger." << endl;
	}
	else if (area1 < area2)
	{
		cout << "Rectangle 2 is larger." << endl;
	}
	else
	{
		cout << "Rectangle 1 has the same area as Rectangle 2" << endl;
	}

	system("PAUSE");
}