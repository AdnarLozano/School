#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

int main() {
    
    /*
    
    fstream f("phonebook.txt"s);
    stringstream entry;
    string line;
    
    string name;
    int number;
    
    while (getline(f, line)) {
        entry = stringstream(line);
        entry >> name >> number;
        cout << name << ' ' << number + 1 << endl;
    }
    
    */
    
    fstream f("prices.txt", );
    map<string, double> prices;
    string item;
    double price;
    
    while (f >> item >> price) {
        prices[item] = price;
    }
    
    f.clear();
    f.seekp(0);
    
    //cout << f.tellg() << ' ' << f.tellp();
    /*
    f.close();
    f.open("prices.txt"s, fstream::out);
    for (auto &p : prices) {
       f << p.first << ' ' << p.second * 2.0 << endl;
    }
    */
}