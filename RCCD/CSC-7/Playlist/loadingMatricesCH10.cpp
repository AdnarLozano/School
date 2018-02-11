#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int* LoadMatrix(string filename)
{
	ifstream in;
	in.open(filename);

	int n;
	int temp;
	int* adj;	//dynamic array
	int* result;

	in >> n;
	
	int size = n*n / 32;
	if (n*n % 32 > 0)
		size++;


	 
	result = new int[size + 1];
	adj = result + 1;
	
	memset(adj, 0, size*sizeof(int));

	int shift = 0;
	int offset = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			in >> temp;

			adj[offset] |= (temp << shift);
			
			shift++;

			if (shift >= 32)
			{
				shift = 0;
				offset++;
			}
		}
	}

	result[0] = n;	//number of nodes
	return result;
}

bool Connected(int src, int dest, int* matrix)
{
	int size = matrix[0];
	int* adj = matrix + 1;

	int index  = src * size + dest;
	int shift  = index % 32;
	int offset = index / 32;

	return (adj[offset] & (1 << shift));

}

int main()
{
	int* adj;
	int size;
	string filename;

	cout << "Enter filename: ";
	cin >> filename;

	adj = LoadMatrix(filename);

	int src, dest;

	cout << "Enter src and dest node: ";
	while (cin >> src >> dest)
	{
		if (Connected(src, dest, adj))
			cout << "Connected!" << endl;
		else
			cout << "Not connected!" << endl;
	}

	return 0;
}
