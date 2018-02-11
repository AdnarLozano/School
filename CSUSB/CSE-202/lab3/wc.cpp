#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main() {
    
    fstream file;
    string line, word;
    string fileName;
    cout << "File name: ";
    cin>>fileName;
    cout<<endl;
    file.open(fileName);
    
    // NUMBER OF LINES
    int i = 0;
    while (getline(file, line)) i++;
    cout << "Number of lines: " << i << endl;
    file.clear();
    
    // NUMBER OF WORDS
    i = 0;
    file.seekg(0, ios::beg);
    while(file >> word) i++;
    cout << "Number of words: " << i << endl;
    file.clear();
    
    // NUMBER OF CHARACTERS
    i = 0;
    char c;
    file.seekg(0, ios::beg);
    while (file.get(c)) {
        if (c == ' ' || c == '\n') continue;
        i++;
    }
    cout << "Non-whitespace characters: " << i << endl;
    file.clear();
    file.close();
    return 0;
}