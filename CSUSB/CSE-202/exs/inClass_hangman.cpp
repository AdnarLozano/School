#include <iostream>
#include <string>
#include <vector> ;
using namespace std;

int main() {
    int lives = 6;
    bool found;
    char letter;
    //string secret = "photography"s;
    vector<char> letter
    
    string guess(secret.size(), '_');
    while (true) {
        cout << "You have "s << lives << " lives left"s << endl;
        for ( char c : guess) cout << c << ' ';
        cout << endl;
        if (guess == secret) {
                cout <<"You won!"s << endl;
                break;
        }
        cin >> letter;
        found = false;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == letter) {
                found = true;
                guess[i] = letter;
            }            
        }
        if ( not found) {
            --lives;
            if (lives==0){
                cout << "You lose!"s <<endl;
                break;
            }
        } 
    }
    return 0;
}