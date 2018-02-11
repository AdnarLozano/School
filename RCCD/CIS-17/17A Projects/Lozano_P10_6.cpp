// Adnar Lozano
// November 20, 2014
// CIS-17A: C++ Programming
// Chapter 10, Programming Challenge 6: Vowels and Consonants

#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

// Constant for array size
const int SIZE = 81;

// Function prototypes
int vowels(char *);
int consonants(char *);

int main()
{
   char choice;			// Menu choice
   char cstring[SIZE];  // To hold a string

   // Get a string.
   cout << "Welcome!!!" << endl;
   cout << "----------" << endl;
   cout << endl;
   cout << "Please enter a string: ";
   cin.getline(cstring, SIZE);
   
   // Display the menu.
   do
   {
      cout << "\tA) Count the vowels in the string\n";
      cout << "\tB) Count the consonants in the string\n";
      cout << "\tC) Count both vowels and consonants\n";
      cout << "\tD) Enter another string\n";
      cout << "\tE) Exit this program\n\n";
      
      // Get the user's choice.
      cout << "\tEnter A, B, C, D, or E.\n";
      cin >> choice;
      
      // Validate the choice.
      while (toupper(choice) < 'A' || toupper(choice) > 'E')
      {
         cout << "\tEnter ONLY A, B, C, D, or E.\n";
         cin >> choice;
      }

      // Process the user's choice.
      switch (toupper(choice))
      {
         // Choice A is to count the vowels.
         case 'A':   cout << "The string has ";
                     cout << vowels(cstring) 
                          << " vowels.\n\n";
                     break;
                     
         // Choice B is to count the consonants.
         case 'B':   cout << "The string has ";
                     cout << consonants(cstring) 
                          << " consonants.\n\n";
                     break;
                     
         // Choice C is to count both vowels and
         // consonants.
         case 'C':   cout << "The string has ";
                     cout << vowels(cstring) 
                          << " vowels and ";
                     cout << consonants(cstring) 
                          << " consonants.\n\n";
                     break;
                     
         // Choice D is to enter another string.
         case 'D':   cin.get();
                     cout << "Enter a string: ";
                     cin.getline(cstring, SIZE);
                     break;
                     
         // Choice E is to exit the program.
         case 'E':   cout << "Thank you for playing... Goodbye!\n";
						system("PAUSE");
                     //exit(EXIT_SUCCESS);
      }
   } while (toupper(choice) != 'E');

   return 0;
}

int vowels(char *str)
{
   char v[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
   int numVowels = 0;

   while (*str != 0)
   {
      for (int count = 0; count < 10; count++)
      {
            if (*str == v[count])
         {
            numVowels++;
            break;
         }
      }
   str++;
   }
   return numVowels;
   
}

int consonants(char *str)
{
   char v[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
   int numCons = 0, foundVowel;

   while (*str != 0)
   {
      foundVowel = 0;
         for (int count = 0; count < 10; count++)
      {
            if (*str == v[count])
         {
            foundVowel = 1;
            break;
         }
      }
      if (!foundVowel)
         numCons++;
      str++;
   }
   return numCons;
}