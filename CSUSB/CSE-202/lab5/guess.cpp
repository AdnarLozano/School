#include <iostream>
#include <random>
using namespace std;
int main() {
    for (char first = 'a'; first<='z'; first++)
        for (char second = 'a'; second<='z'; second++)
            for (char third = 'a'; third<='z'; third++)
                cout<<first<<second<<third<<endl;
    return 0;
}
