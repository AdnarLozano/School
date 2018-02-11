#include <iostream>
#include <string>
using namespace std;
const int MAX_TRIES = 6;
int letterFill (char, string, string&);
int main () {
	string name, word = "hello";
	char letter;
	int wrongGuess = 0;
	string guess(word.length(),'_');
	cout << "\nGuess the word game\n";
	cout << "-------------------\n";
	cout << "You have " << MAX_TRIES << " tries to guess the word\n";
	while (wrongGuess < MAX_TRIES) {
		cout << "This is the word to guess: \"" << guess <<"\"\n\nGuess a letter: ";
		cin >> letter;
		if (letterFill(letter, word, guess) == 0) {
			cout << "\nSorry, that letter is incorrect\n";
			wrongGuess++;
		}
		else if (guess == word) {
		    cout << "\nYou found the word!\n" << "The word was: \"" << word << "\"\nYou win!\n"; 
		    break;
	    }
		else cout << endl << "You found a letter" << endl;
		cout << "You have " << MAX_TRIES - wrongGuess << " guesses left\n";
	}
	if(wrongGuess == MAX_TRIES) cout << "and run out of tries.\nThe word was: \"" << word << "\"\nYou lose!\n";
	cin.ignore();
	return 0;
}
int letterFill (char letter, string word, string &guess) {
	int i;
	int rightLetter = 0;
	for (i = 0; i< word.length(); i++) {
		if (letter == guess[i]) return 0;
		if (letter == word[i]) guess[i] = letter, rightLetter++;
	}
	return rightLetter;
}