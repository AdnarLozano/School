// Adnar Lozano
// November 20, 2014
// CIS-17A: C++ Programming

#include <iostream>
#include <cctype>
using namespace std;

int isvowel(char);

void main()
{
	char chr;

	cout << "Enter a character: ";
	cin.get(chr);

	cout << endl << endl;

	if(isalpha(chr))
		cout << "Alphabetic Character" << endl;
	if(isdigit(chr))
		cout << "Digit" << endl;
	if(islower(chr))
		cout << "Lower Case" << endl;
	if(isupper(chr))
		cout << "Upper Case" << endl;
	if(isspace(chr))
		cout << "Space" << endl;
	if(isalnum(chr))
		cout << "Alpha Numeric" << endl;
	if(iscntrl(chr))
		cout << "Control Character" << endl;
	if(isgraph(chr))
		cout << "Graphic Symbol" << endl;
	if(isprint(chr))
		cout << "Print Character" << endl;
	if(ispunct(chr))
		cout << "Punctuation Character" << endl;
	if(isxdigit(chr))
		cout << "Hexadecimal Character" << endl;
	if(isvowel(chr))
		cout << "Vowel" << endl;


	system("PAUSE");
}

int isvowel(char chr)
{
	char c = toupper(chr);
	if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
	{
		return 1;
	}

	return 0;
}