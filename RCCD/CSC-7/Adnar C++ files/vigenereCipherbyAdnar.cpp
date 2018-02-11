/*
 *  vigenereCipherbyAdnar.cpp
 *  Created by Adnar Lozano on 4/18/15.
 *  CIS-7: Discrete Structures
 *  Copyright 2015. All rights reserved.
 */
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

string Convert(string& str)
{
  string converted;

  for(short i = 0; i < str.size(); ++i)
    converted += toupper(str[i]);
  
  return converted;
}

class Vigenere
{
public:
  string key;
 
  Vigenere(string key)
  {
    for(int i = 0; i < key.size(); ++i)
    {
      if(key[i] >= 'A' && key[i] <= 'Z')
        this->key += key[i];
      else if(key[i] >= 'a' && key[i] <= 'z')
        this->key += key[i] + 'A' - 'a';
    }
  }
 
  string encrypt(string text)
  {
    string out;
 
    for(int i = 0, j = 0; i < text.length(); ++i)
    {
      char c = text[i];
 
      if(c >= 'a' && c <= 'z')
        c += 'A' - 'a';
      else if(c < 'A' || c > 'Z')
        continue;
 
      out += (c + key[j] - 2*'A') % 26 + 'A'; 
      j = (j + 1) % key.length();
    }
 
    return out;
  }
 
  string decrypt(string text)
  {
    string out;
 
    for(int i = 0, j = 0; i < text.length(); ++i)
    {
      char c = text[i];
 
      if(c >= 'a' && c <= 'z')
        c += 'A' - 'a';
      else if(c < 'A' || c > 'Z')
        continue;
 
      out += (c - key[j] + 26) % 26 + 'A'; 
      j = (j + 1) % key.length();
    }
 
    return out;
  }
};
 
int main()
{
  string key, original;
  string cyp, dcyp;
  char choice;

  cout <<"\nWelcome to the Vigenere Cipher";
  cout <<"\n------------------------------";
  cout << endl;

  cout << "\nEnter your key in letters only: ";
  getline(cin, key);

  Convert(key); 
  Vigenere cipher(key);

  cout << "\nEnter your message in letters only: ";
  getline(cin, original);

  cout << "\nDo you want to encrypt or decrypt (e/d): ";
  cin >> choice;    
  choice = tolower(choice);

    if ( choice == 'e')
    {
      cyp = cipher.encrypt(original);
      cout << "\nYour encrypted message is: " << cyp << endl << endl;
    }
    else if ( choice == 'd')
    {
      dcyp = cipher.decrypt(original);
      cout << "\nYour decrypted message is: " << dcyp << endl << endl;
    }
    else
      cout << "\nPlease enter 'e' or 'd' and try again...\n " << endl;

  cout << "Thank you for playing...\n" << endl;   
  return 0;
  
}
