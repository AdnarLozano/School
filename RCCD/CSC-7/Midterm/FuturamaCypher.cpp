/*
 *  FuturamaCypher.cpp
 *  FuturamaCypher
 *
 *  Created by Adnar Lozano on 4/18/15.
 *
 */

#include <iostream>
#include <string>

using namespace std;

string en(string msg)
{
	string input;
	int count = 0, length;
	length = (int)input.length();

	for (count = 0; count < length; count++)
	{
		if(isalpha(input[count]))
		{

			input[count] = toupper(input[count]);
			int l = (input.length() - 'A');
			l = 0;
			for(int i = 0; i < 13; i++)
			{
				if (input[count] == 'Z')
					input[count] = 'A';
				else
					input[count]++;
			}
		}
	}


	return input;
}


string de(string msg)
{
	string input;
    int count = 0, length;
	length = (int)input.length();

	for (count = 0; count < length; count++)
	{
		if(isalpha(input[count]))
		{

			input[count] = toupper(input[count]);
			int l = (input.length() - 'A');
			l = 0;
			for(int i = 0; i < 13; i++)
			{
				if (input[count] == 'A')
					input[count] = 'Z';
				else
					input[count]--;
			}
		}
	}

	return input;
}



int main()
{
	string msg;
	int length;
	string cyp, dcyp;

	cout << "Enter your phrase: \n";
	getline(cin, msg);
    length = (int)msg.length();

	cyp = en(msg);

	cout << "Cypher: " << endl;
	for (int i = 0; i < length; i++)
		cout << cyp[i] << " ";

	dcyp = de(cyp);
	cout << "\nDecypher: " << endl;
	for (int i = 0; i < length; i++)
		cout << dcyp[i] << " ";
	cout << endl;



	//cout << "Results: \n" << input << endl;

}
