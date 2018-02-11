// Adnar Lozano
// October 7, 2014
// CIS-17A: C++ Programming
// Chapter 5, Programming Challenge 17: Sales Bar Chart

#include <iostream>
#include <iomanip>

using namespace std;

void getEven(int, int);
void getOdd(int, int);
void getPrime(int, int);
void special(int, int);

void main()
{
	int begin, end, selection;
	char chr;

	do
	{
		cout << "M A I N  M E N U"	<< endl;
		cout << "1. Even"			<< endl;
		cout << "2. Odd "			<< endl;
		cout << "3. Prime"			<< endl;
		cout << "4. Special"		<< endl;
		cin  >> selection;

		switch(selection)
		{
		case 1:
			cout << "Begin: ";
			cin  >> begin;
			cout << "End: " ;
			cin	 >> end;
			getEven(begin, end);
			break;
		case 2:
			cout << "Begin: ";
			cin  >> begin;
			cout << "End: " ;
			cin	 >> end;
			getOdd(begin, end);
			break;
		case 3:
			cout << "Begin: ";
			cin  >> begin;
			cout << "End: ";
			cin	 >> end;
			getPrime(begin, end);
			break;
		}

		cout << "Continue (y/n)? ";
		cin >> chr;
	}while(chr == 'y');
	system("PAUSE");
}

void getEven(int b, int e)
{
	for(int i = b; i<=e; i++)
	{
		if(i % 2 == 0)
		cout << i << "  " << endl;
	}
}
void getOdd(int b, int e)
{
	for(int i = b; i<=e; i++)
	{
		if(i % 2 != 0)
		cout << i << "  " << endl;
	}
}
void getPrime(int b, int e)
{
	bool test = false;
	
	for(int i = b; i <= e; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if(i % j != 0)
			{
				test = true;
			}
		}
		if (test)
		{
			cout << i << "  ";
			//test = false;
		}
	}
}