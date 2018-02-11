#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    
    fstream file;
    string line;
    string fileName;
    cout << "File name: ";
    cin>>fileName;
    cout<<endl;
    file.open(fileName);
    
    // Unsorted
    cout << "\nOriginal file:\n";
    cout << "--------------\n";
    int i = 0;
    while (getline(file, line))  cout<<line<<endl, i++; 
    int const size = i;
    file.clear();
    cout<<"\n\n";

    vector<string> str(size);
    // Sorted
    cout << "Sorted file:\n";
    cout << "------------\n";
    file.seekg(0, ios::beg);
    i = 0;
    while (getline(file, line)) {
        str[i] = line;
        i++;
        // str.push_back(line);
    }
    sort ( str.begin(), str.end() );
    for (int i = 0; i < str.size(); i++) cout <<str[i] << endl;
    cout<<endl;
    file.clear();
    file.close();
    return 0;
}