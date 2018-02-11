// Adnar Lozano
// November 20, 2014
// CIS-17A: C++ Programming
// Chapter 10, Programming Challenge 5: Sentence Capitalizer

#include <iostream>
#include <cctype>
using namespace std;

// Function prototype
void capital(char*);

int main()
{
	const int SIZE = 1024;
   
	char cstring[SIZE];

	cout << "Welcome!!!" << endl;

	cout << "Enter at least two sentences, but "
		 << "do not use capital letters.\n";
	cin.getline(cstring, SIZE);

	capital(cstring);

	cout << "\nHere are your sentences with "
		 << "beginning words capitalized:\n";
	cout << cstring << endl << endl;
   
	system("PAUSE");
}

void capital(char *str)
{

	bool period = true;

	while (*str != '\0')
	{
		while (*str != 0 && isspace(*str))
			str++;
		if (period && *str != '\0')
		{
			*str = toupper(*str);
         
			period = false;
		}

		while (*str != 0 && *str != '.' )
		{

			str++;
		}

		if (*str == '.')
		{
			period = true;
			str++;
		}
      
	} 
}