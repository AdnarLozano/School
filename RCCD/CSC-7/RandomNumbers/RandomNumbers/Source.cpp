#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void rsort(vector<int> &nums)
{

	

}

void print(vector<int> &nums)
{
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << endl;
}


int main()
{
	vector<int> nums;
	string filename;
	ifstream in;
	int num;

	cout << "Filename: ";
	cin >> filename;

	in.open(filename);
	if (in.fail())
	{
		cout << "ERROR: File not found!" << endl;
		exit(404);
	}

	while (in >> num)
	{
		nums.push_back(num);
	}

	in.close();

	//unsorted
	//print(nums);

	sort(nums);

	//sorted
	print(nums);


	return 0;
}