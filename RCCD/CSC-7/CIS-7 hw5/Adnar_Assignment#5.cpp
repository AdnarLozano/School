//  CIS-7: Assignment #5 by Adnar Lozano
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;
static int value = 1;
int n_mat;
int n;
int array[7] = {0,1,2,3,4,5,6};
int** first;
int** second;
int** firstAferS;
bool test = false;
int factorial(int n)
{
    
    if (n<=0)
        return 1;
    else
        value = n * factorial(n-1);
    return value;
}
int numOfPernutations(int n, int k)
{
    if (k>n)
        return 0;
    else if (n<=0)
        return 1;
    else
        value = factorial(n) / factorial(n-k);
    return value;
}
int numOfCombinations(int n, int k)
{
    int value;
    if (k > n || k<=0 )
        return 0;
    if (n==k)
        return 1;
    else
        value = factorial(n) / (factorial(k)*factorial(n-k));
    return value;
}

void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permutes(char *arr, int i, int n)
{
    int count = 0;
    int j;
    if (i == n)
    {
        cout<<arr<<endl;
        count++;
    }
    
    else
    {
        for (j = i; j <= n; j++)
        {
            swap((arr + i), (arr + j));
            permutes(arr, i + 1, n);
            swap((arr + i), (arr + j));
        }
    }
}
void swap(int x, int y){
    int temp = array[x];
    array[x]=array[y];
    array[y]=temp;
    return;
}
int** mSWAP(int pass1,int pass2)
{
            for(int i = 0; i<n; i++)
            {
                int temp1=first[i][pass1];
                first[i][pass1]=first[i][pass2];
                first[i][pass2]=temp1;
            }
            for (int j = 0; j<n; j++)
            {
                int temp2=first[pass1][j];
                first[pass1][j]=first[pass2][j];
                first[pass2][j]=temp2;
            }
    return first;
}
void printArray(int size){
    int i;
    test = true;
    for (i=0;i<size;i++)
        {
            firstAferS = mSWAP(i,array[i]);
        }

    for ( int i = 0; i < n && test== true; i++ )
   {
      for ( int j = 0; j < n&& test== true; j++ )
      {
         if ((firstAferS[i][j])!= (second[i][j]))
         {
             test=false;
         }
      }
   }
   if(test==true)
    {
    cout<<"Given these two matrices, they are isomorphic based on ";
    for (i=0;i<size;i++)
        {
            cout << i<<"->"<<array[i] << ", ";
        }
    cout << " rotation."<<endl;
    exit;
   }

    return;
}
void permute(int k,int size){
    int i;
    if (k==0&& test==false)
        printArray(size);
    else{
        for (i=k-1;i>=0;i--){
            swap(i,k-1);
            permute(k-1,size);
            swap(i,k-1);
        }

    }

    return;
}
int** LoadMatrix(string filename)
{
   ifstream in;
   in.open (filename.c_str());

   if ( !in )
   {
        cout<<"File not found!";
        exit( 1 );
   }
   in >> n;
   int **a = new int *[n];

   for ( int i = 0; i < n; i++ )
   {
      a[i] = new int[n];
   }

   for ( int i = 0; i < n; i++ )
   {
      for ( int j = 0; j < n; j++ )
      {
         in >> a[i][j];
      }
   }
   return a;
}
int* PrintMatrix(int** adj)
{
    int c_edge [7]= {};
    int edge = 0;
    for ( int i = 0; i < n; i++ )
   {
      for ( int j = 0; j < n; j++ )
      {
         cout <<  adj[i][j]<<" ";
         if(adj[i][j])
         {
             edge++;
             c_edge[i]++;
         }

      }cout<<"  # of edges in "<<i<<" is "<<c_edge[i]<<endl;
   }

   cout<<"\nTotal # of edges is: "<<edge<<endl<<endl;
   return c_edge;
}
void Part1()
{
    int k, n;
    cout << "Part 1\n";
    cout << "------\n";
    cout << "Develop an algorithm that outputs all permutations\n";
    cout << "from the set S = { 1, 2, 3, 4, 5, 6, 7 } with no repeats.\n\n";
    cout << "Enter n and k (0 ≤ k ≤ n): ";
    cout << endl;
    cin  >> n >> k;
    cout << "n = " << n << "  |  k = " << k << "  |  ";
    cout << n << "! = " << factorial(n) << "  |  P(n,k) = ";
    cout << numOfPernutations(n,k) <<  "  |  C(n,k) = " << numOfCombinations(n,k) << endl;
    cout << endl;
    cout << "Display of permutations\n";
    cout << "-----------------------\n";
    char arr[] = "1234567";
    permutes(arr, 0, sizeof(arr)-2);
    cout << endl;
}
int main()
{
	int* firstE;
	int* secondE;
	string filename;

    cout << "Permutations, Combinations & Graphs\n";
    cout << "-----------------------------------\n\n";
    Part1();
    cout << "Part 2\n";
    cout << "------\n";
    cout << "a) Given several adjacency matrices, determine which graphs are isomorphic to one another.\n";
    cout << "b) Assuming you find two isomorphic graphs (G1 and G2)\n";
    cout << "   indicate the correspondence between vertices in G1 to vertices in G2.\n";    
    cout << endl;

    cout << "Enter first file name: ";
    cin >> filename;
    first= LoadMatrix(filename);
    cout << "Enter second file name: ";
    cin >> filename;
    second= LoadMatrix(filename);
    firstE=PrintMatrix(first);
    secondE=PrintMatrix(second);
    permute(7,7);
    if (test==false)
            cout<<"Given these two matrices, they are NOT isomorphic."<<endl;
	return 0;
}
