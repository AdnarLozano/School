// Adnar Lozano
// CIS-17A: C++ Programming
// September 25, 2014

#include <iostream>
using namespace std;

void main()
{
	int age, gender, price = 20;

	cout << "Select one..." << endl;
	cout << "1. Adult" << endl;
	cout << "2. Child" << endl;
	cin >> age;

	cout << "Select one..." << endl;
	cout << "1. Male" << endl;
	cout << "2. Female" << endl;
	cin >> gender;

	if(age == 1)
		if(gender == 1)
			price = price;
		else
			price = price - 2;
	else
		if(gender == 1)
			price = price / 2;
		else
			price = (price - 2) / 2;
	
	cout << "Cost of ticket: " << price << endl;

	system("PAUSE");
}
