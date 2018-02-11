/****************
Adnar Lozano
1/19/17
Lab 1 Exercise 2
****************/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main() {
    fstream file;
    string word, line;
    int i = 0;
/*
    UNCOMMENT THIS IF YOU NEED TO INPUT FILE FROM USER 
    string fileName;
    cout << "File name: ";
    cin>>fileName;
    cout<<endl;
    file.open(fileName);
*/ 
    // NUMBER OF lINES
    file.open("data.txt");
    while (getline(file, line)) i++;
    cout << "Number of lines: " << i << endl;
    file.close();
    
    // NUMBER OF WORDS
    i = 0;
    file.open("data.txt");
    while(!file.eof()) file >> word, i++;
    cout << "Number of words: " << i << endl;
    file.close();
    
    // NUMBER OF CHARACTERS
    i = 0;
    file.open("data.txt");
    // add 1 for carriage return in each line
    while(getline(file, line)) i += line.length(), i++;
    cout << "Number of characters: " << --i << endl;
    file.close();
    return 0;
}