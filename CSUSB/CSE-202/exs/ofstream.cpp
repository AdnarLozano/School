#include <iostream>
#include <fstream>
using namespace std;

int main() {
    
    ofstream f("data2.txt"s);
    f << "Hello"s << endl;
}