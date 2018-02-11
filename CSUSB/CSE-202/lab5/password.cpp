#include <iostream>
#include <random>
using namespace std;

int main(int  argc, char* argv[]) {
    default_random_engine prng(random_device{}());
    uniform_int_distribution<char> dist('a','z');
    string password;
    string guess;
    int count=0;
    for (int i = 0; i < 3; ++i) password += dist(prng);
    cout<<password<<endl;
    while (true) {
        cout << "Guess 3-letter password: ";
        cin >> guess;
        count++;
        cout << "You guessed: " << guess << endl;
        if (guess == password) {
            cout <<count<<". "<< "Access granted." << endl;
            break;
        } else {
            cout <<count<<". "<< "Access denied." << endl;
        }
    }
    return 0;
}
