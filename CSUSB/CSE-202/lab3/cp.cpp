#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main() {
    
    fstream fileIn, fileOut;
    string line, fIn, fOut;
    cout << "Copy FROM filename: ";
    cin>>fIn;
    fileIn.open(fIn, fstream::in);
    cout << "Copy TO filename: ";
    cin>>fOut;
    fileOut.open(fOut, fstream::out);
    fileOut << fileIn.rdbuf();
    fileIn.close();
    fileOut.close();
    fileIn.open(fIn);
    cout<<"\nContents of the original file: \""<<fIn<<"\"\n\n";
    while (getline(fileIn, line)) cout<<line<<endl;
    fileIn.close();
    fileIn.open(fOut);
    cout<<"\nContents of the copied file: \""<<fOut<<"\"\n\n";
    while (getline(fileIn, line)) cout<<line<<endl;
    fileIn.close();
    return 0;
}