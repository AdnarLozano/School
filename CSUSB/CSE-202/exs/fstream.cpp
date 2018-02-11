#include <iostream>
#include <fstream>
using namespace std;

int main() {
    
    fstream f;
    f.open("data.txt"s, fstream::in | fstream::out | fstream::ate);
    f << "Hello"s << endl;
}