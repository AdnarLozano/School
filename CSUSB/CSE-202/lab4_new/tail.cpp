#include<iostream>
#include<fstream>
using namespace std;
int main(){
    int n=10;
    int line_count = 1;
    fstream fs("data.txt");
    char c;
    while ( fs.get(c) ) if (c == '\n') line_count++; 
    fs.clear();
    fs.seekg(0, ios::beg);
    int lines_over = line_count - n;
    line_count=1;
    while ( fs.get(c) ) {
        if (c == '\n') line_count++;
        if (line_count > lines_over) cout<<c;
    }
    return 0;
}