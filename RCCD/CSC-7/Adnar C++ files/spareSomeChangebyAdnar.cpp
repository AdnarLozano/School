/*
 *  spareSomeChangebyAdnar.cpp
 *  Created by Adnar Lozano on 4/18/15.
 *	CIS-7: Discrete Structures
 *  Copyright 2015. All rights reserved.
 */
#include <iostream>
#include <string>
using namespace std;

void change(int n, int &quarter, int &dime, int &nickle, int &penny)
{
	quarter = n/25;
	dime = n % 25/10;
	nickle = n % 25 % 10/5;
	penny = n % 25 % 10 % 5;

	cout << "\nYour change should be:" << endl;
	cout << "\t\t\t" << quarter	<< " quarter(s), " << endl;
	cout << "\t\t\t" << dime		<< " dime(s), " << endl;
	cout << "\t\t\t" << nickle	<< " nickle(s), and " << endl;
	cout << "\t\t\t" << penny		<< " penny(s)." << endl << endl;
}

int main()
{
	int input, q=25, d=10, n=5, p=1;

	cout <<"\nWelcome to the Spare Some Change Program\n";
	cout <<"------------------------------------------\n";
	cout << endl;

    cout << "Enter the amount of money you want change for: ";
	cin >> input;

	change(input, q, d, n, p);

	return 0;
}

