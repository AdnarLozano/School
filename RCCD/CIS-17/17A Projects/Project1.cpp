// Adnar Lozano
// September 4, 2014
// CIS-17A: C++ Programming
// Project 1

#include <iostream>
#include <math.h>
using namespace std;
void main()
{
	const double pi = 3.1415926535897;
	double r;
	double a;
	double c;

	cout <<"Lets find the area & circumference of a circle\n"; 
	cout <<"----------------------------------------------\n\n";

	cout <<"Please enter the radius: ";
	cin >> r;
	cout << "\n";

	a = pi * pow(r, 2); 
	cout << "The area of ur circle is: " << a << endl;
	cout << "\n";

	c = 2 * pi * r;
	cout << "The circumference of ur circle is: " << c << endl;
	cout << "\n";

	system("PAUSE");
}