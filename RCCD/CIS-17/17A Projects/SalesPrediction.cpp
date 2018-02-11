// Adnar Lozano
// September 4, 2014
// CIS-17A: C++ Programming

#include <iostream>
using namespace std;
void main()
{
	double percent = .58;
	double sales = 8600000.00;
	double prediction;

	prediction = percent * sales;

	cout << "Sales prediction: "; cout << prediction << endl;

	system("PAUSE");
}