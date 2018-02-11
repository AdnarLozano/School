/*
 *  futuramaCipherbyAdnar.cpp
 *  Created by Adnar Lozano on 4/18/15.
 *	CIS-7: Discrete Structures
 *  Copyright 2015. All rights reserved.
 */
#include <iostream>
#include <string>
using namespace std;

string encrypt(string msg)
{
	string cyp;
	int length, before = 0;
	length = (int)msg.length();
	for (int element = 0; element < length; element++)
	{
		if(isalpha(msg[element]))	
		{
			msg[element] = toupper(msg[element]);
			char c = (char)(((((int)msg[element] - 65 + before) +26) % 26) + 65);
			cyp += c;
        before = (int)c - 65;
		}
		else
			cyp += " ";		
    }
	return cyp;
}

string decrypt(string msg)
{
	string dcyp;
	int length, before = 0;
	length = (int)msg.length();
	for (int element = 0; element < length; element++)
	{
		if(isalpha(msg[element]))
		{
			msg[element] = toupper(msg[element]);
			dcyp += (char)(((((int)msg[element] - 65 - before) + 26) % 26) + 65);
        before = (int)msg[element] - 65;
		}
		else
			dcyp += " ";
    }
	return dcyp;
}

int main()
{
    string msg;
	string cyp, dcyp;
	char choice;
	
	cout <<"Welcome to the Futurama Cipher\n";
	cout <<"------------------------------\n";
	cout << endl;
	cout << "Enter your Message: ";
	getline(cin, msg);	
	
	cout << "\nDo you want to encrypt or decrypt (e/d): ";
	cin >> choice;		
	choice = tolower(choice);

		if ( choice == 'e')
		{
			cyp = encrypt(msg);
			cout << "\nYour encrypted message is: " << cyp << endl << endl;
		}
		else if ( choice == 'd')
		{
			dcyp = decrypt(msg);
			cout << "\nYour decrypted message is: " << dcyp << endl << endl;
		}
		else
			cout << "Please enter 'e' or 'd' and try again " << endl;

	cout << "Thank you for playing...\n" << endl;		
	return 0;
}
