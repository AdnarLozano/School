#include <iostream>
#include <random>
#include <unistd.h>
using namespace std;
int main() {
    int a, b, c, x;
    int coins = 100;
    default_random_engine prng(random_device{}());
    uniform_int_distribution<int> dist(0,9);
    cout<<"\nWelcome to the slot machine game!";
    cout<<"\n---------------------------------\n\n";
    do {
        cout<<"Pay with $1, $2, or $3 coins (4 to quit)\n";
        cout<<"Insert coin = \t$";
        cin>>x;
        if (x<=0 || x>3 || isdigit(x)) break;
        coins-=x;
        a=dist(prng), b=dist(prng), c=dist(prng);
        cout<<"----------------------------------------------\n";
        cout<<"Spining..."<<"\t*|*|*\tPaid: $"<<x<<endl;
        for (int i=0; i<2; i++) {
        	usleep(90000);
        	cout<<"\t\t*|*|*\n";
    	}
        cout<<"Spin: \t\t"<<a<<"|"<<b<<"|"<<c;
        if (a == b && b == c) {
            cout<<"\n**********************************\n";
            cout<<"Congrats, you hit all three reels! \n";
            cout<<"**********************************\n";
            coins+=300*x;
            cout<<"++++++++ Bonus "<<300*x<<" coins ++++++++\n";
        }
        cout<<"\tYou have "<<coins<<" coins left\n";
        cout<<"----------------------------------------------\n\n";
    }while(coins>0);
    cout<<"\nThank you for playing\n";
    return 0;
}
