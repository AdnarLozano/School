/*input
7
1 3 9 8 2 7 5
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &v, int lo, int hi) {
    int pivot = v[hi];
    int i = lo - 1;
    for (int j = lo; j <= hi - 1;j++) {
        if (v[j] < pivot) {
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1], v[hi]);
    return i + 1;
}
void quickSort(vector <int> &v, int lo, int hi) {
    if (lo < hi) {
        int p = partition(v, lo, hi);
        for (int i = 0; i < v.size(); i++) 
        	cout << v[i] << " ";
    	cout << endl;
        quickSort(v, lo, p-1);
        quickSort(v, p+1, hi);
    }
}
int main(void) {
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    printf("Quick In-place:\n");
    printf("Sample Input:\n");
    printf("7\n");
    printf("1 3 9 8 2 7 5\n");
    printf("Output:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    quickSort(v,0,v.size()-1);
    return 0;
}