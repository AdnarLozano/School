#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string line, filename;
    ifstream f;
    
    cout << "filename: "s;
    cin >> filename;
    f.open(filename);
    while (getline(f, line)){
        cout << line <<endl;
    }
}