// Adnar Lozano
// CIS-17A: C++ Programming
// October 2, 2014

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const int CODES = 127;
	const int CHARS = 16;
	char character;

	cout << "ASCII Codes for characters" << endl;

	for (int code = 0; code <= CODES; code++)
	{
		character = code;

		(code % CHARS == 0) ? 
		(cout << " " << character << "=" << code << endl):
		(cout << character << "=" << code << endl);
	}

	for(int i = 0; i < 10; i++)
	{
		character = 7;
		cout << character;
	}
	
	cout << endl << endl;

	system("PAUSE");
	return 0;
}

