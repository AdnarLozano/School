/****************
Adnar Lozano
1/19/17
Lab 1 Exercise 1
****************/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main() {
    fstream file;
    string line;
/*
    UNCOMMENT THIS IF YOU NEED TO INPUT FILE FROM USER 
    string fileName;
    cout << "File name: ";
    cin>>fileName;
    cout<<endl;
    file.open(fileName);
*/  
    int i = 1;
    file.open("data.txt");
    while (!file.eof()){
        getline(file, line);
        cout<<"\t"<<i<<" "<<line<<endl;
        i++;
    }
    file.close();
    return 0;
}