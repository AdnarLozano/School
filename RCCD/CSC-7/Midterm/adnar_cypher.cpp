/*
 *  adnar_cypher.cpp
 *
 *  Created by Adnar Lozano on 4/18/15.
 *
 */


#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	int count = 0, length;

	cout << "Enter your phrase (spaces are ok): \n";
	getline(cin, input);

	length = (int)input.length();

	//  TO ENCRYPT IT

	for (count = 0; count < length; count++)
	{
		if(isalpha(input[count]))	// This is see nmake sure is a letter and not a space or symbol
		{
			input[count] = tolower(input[count]);
			for(int i = 0; i < 13; i++) 	// moving the character 13 times instead of 26
			{
				if (input[count] == 'z')
					input[count] = 'a';
				else
					input[count]++;
			}
		}
	}

	cout << "Encrypted Code: \n" << input << endl;


	//  TO DENCRYPT IT

	for (count = 0; count < length; count++)
	{
		if(isalpha(input[count]))	// This is see nmake sure is a letter and not a space or symbol
		{
			input[count] = tolower(input[count]);
			for(int i = 0; i < 13; i++) 	// moving the character 13 times instead of 26
			{
				if (input[count] == 'A')
					input[count] = 'Z';
				else
					input[count]--;
			}
		}
	}

	cout << "Decrypted Code: \n" << input << endl;

}
