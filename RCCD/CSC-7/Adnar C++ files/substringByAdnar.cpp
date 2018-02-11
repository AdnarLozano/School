/*
 *  substringByAdnar.cpp
 *  Created by Adnar Lozano on 4/18/15.
 *	CIS-7: Discrete Structures
 *  Copyright 2015. All rights reserved.
 */
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int i = 0, j = 0;
	int count = 0;
	string str1, str2, str3;

	cout <<"\nWelcome!";
	cout <<"\n-------!\n";
	cout << endl;

	cout << "This program checks to see if your first word\n";
	cout << "is a substring of your second word.\n" << endl;

	cout << "Enter first word: ";
	getline (cin,str1);
	cout << endl;

	cout << "Enter second word: ";
	getline (cin,str2);
	cout << endl;

		if (str2.size() > str1.length()) 
		{
			str3 = str2;
			str2 = str1;
			str1 = str3;
		}
	for (i=0 ; i < str1.length() ; i++)
	{
		if (str1[i]==str2[j] && count < str2.length())
		{
			count ++;
			if (count == str2.length())
			{
				cout << "BRAVO, your word '" + str2 +
						"' was found in '" + str1 +"'." << endl << endl;
				break;
			}
			j++;
		} else if(count > 0)
			{
				i = i-count+1;
				j = 0;
				count =0;
			}
	}
		if(count <str2.length())
		{
			cout << "SORRY, your word '" + str3 +
					"' was NOT found in '" + str1 +"'." << endl << endl;
		}
	return 0;
}