#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void val( int var)
{
    var++;
    cout<< var <<endl;
    cout<<"\t\t\tAddress of param = "<<&var<<endl;
}
void ref( int& var)
{
    var++;
    cout<< var <<endl;
    cout<<"\t\t\tAddress of param = "<<&var<<endl;
}
void poi( int* var)
{
    *var = *var +1;
    cout<<*var <<endl;
    cout<<"Address of param = "<<var<<" "<<&var<<endl;
}

int main()
{
    int a = 30;
    int b = 410;
    int c = 5670;
    
    cout<<"before val()   a = "<<a<<endl;
    cout<<"During val()   a = ";
    val(a);
    cout<<"\t\t\tAddress of a =     "<<&a<<endl;
    cout<<"after  val()   a = "<<a<<endl<<endl;
    
    cout<<"before ref()   b = "<<b<<endl;
    cout<<"During ref()   b = ";
    ref(b);
    cout<<"\t\t\tAddress of b =     "<<&b<<endl;
    cout<<"after  ref()   b = "<<b<<endl<<endl;
    
    cout<<"before poi()   c = "<<c<<endl;
    cout<<"During poi()   c = ";
    poi(&c);
    cout<<"\t\t\tAddress of c =     "<<&c<<endl;
    cout<<"after  poi()   c = "<<c<<endl<<endl;
    
    return 0;
}
