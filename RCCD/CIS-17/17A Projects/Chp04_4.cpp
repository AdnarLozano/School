// Adnar Lozano
// CIS-17A: C++ Programming
// September 25, 2014

#include <iostream>
using namespace std;

void main()
{
	double mass;
	double weight;

	cout << "Enter mass (in kilograms): ";
	cin >> mass;

	weight = mass * 9.8;

	cout << "The object weighs: "
		 << weight << " Newtons.\n" << endl; 
	
	if(weight > 1000)
	{
		cout << "Too Heavy!" << endl;
	}
	else if(weight < 10)
	{
		cout << "Too Light!" << endl;	
	}
	system("PAUSE");
}
