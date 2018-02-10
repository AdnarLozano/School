#include <iostream>
using namespace std;
int main(){
    for (int i = 1; i < 100; ++i)
      for (int j = i; j < 100; ++j)
        for (int k = j; k < 100; ++k)
            for(int m = k; m < 100; ++m)
                if ( i != j && j != k && k != m)
                    if(i+j+k+m ==100)
                        cout << i <<" + "<< j <<" + "<< k <<" + "<< m<< " = 100"<<endl;
    return 0;
}



