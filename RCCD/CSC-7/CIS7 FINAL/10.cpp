#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
float temp[5];
void CalcP(float p[], float p_m, int size)
{
    
    for (int i = 0; i < size; i++)
    {
        // at loc i and didnt move or at loc i-1 and moved
        if (i > 0)
            temp[i] = p[i] * (1 - p_m) + p[i - 1] * p_m;
        else
            temp[i] = p[i] * (1 - p_m);
    }
    memcpy(p, temp, sizeof(float)*size);
}
int main()
{
    float p[5] = { 1, 0 };
    float p_m = .6f;
    for (int t = -1; t < 6; t++)
    {
        cout << "t = " << t << endl;
        
        for (int i = 0; i < 5; i++)
        {
            cout << p[i] << "\t | ";
        }
        CalcP(p, p_m, 5);
        system("pause");
    }
    cout << endl;
    return 0;
}