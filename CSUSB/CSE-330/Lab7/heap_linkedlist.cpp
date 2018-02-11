// Adnar Lozano
// CSE 330 Data Structures
// Lab 7
// 5/20/17

#include <iostream>
#include <vector>
using namespace std;

void rebuild(vector<int> &heap, int& cur_size);

void addItem(vector<int> &heap, int item, int& cur_size) {
	if (cur_size > 0) {
		cur_size++;
		heap.push_back(item);
		int index = cur_size - 1;
		while ((index-1)/2 >= 0) {
			int parent = (index - 1) / 2;
			if (heap.at(index) < heap.at(parent)) {
				int tmp = heap.at(parent);
				heap.at(parent) = heap.at(index);
				heap.at(index) = tmp;
				index = parent;
			}
			else
				return;
		}
	}
	else if (cur_size == 0) {
		cur_size++;
		heap.push_back(item);
	}
	else
		return;
}

void deleteItem(vector<int> &heap, int item, int& cur_size) { 
	int index = 0;
	while (heap.at(index) != item)
		index++;
	heap.at(index) = heap.back();
	heap.resize(--cur_size);
	while (index > 0) {
		if (2 * index + 1 < cur_size) {
			int left = 2 * index + 1;
			int right = left + 1;
			int swap;
			if (right < cur_size) {
				if (heap.at(left) < heap.at(right))
					swap = left;
				else if (heap.at(left) > heap.at(right))
					swap = right;
				else
					swap = left;
			}
			else
				swap = left;

			if (heap.at(index) > heap.at(swap)) {
				int tmp = heap.at(index);
				heap.at(index) = heap.at(swap);
				heap.at(swap) = tmp;
			}
		}

		index = (index - 1) / 2;
	}
	rebuild(heap, cur_size);
}

void rebuild(vector<int> &heap, int &cur_size) {
	int index = 0;
	while (2 * index + 1 < cur_size) {
		int left = 2 * index + 1;
		int right = left + 1;
		int swap;
		if (right < cur_size) {
			if (heap.at(left) < heap.at(right))
				swap = left;
			else if (heap.at(left) > heap.at(right))
				swap = right;
			else
				swap = left;
		}
		else
			swap = left;
		if (heap.at(index) > heap.at(swap)) {
			int tmp = heap.at(index);
			heap.at(index) = heap.at(swap);
			heap.at(swap) = tmp;
		}
		index = swap;
	}
}

int main() {
	int opCount;
	int cur_size = 0;
	vector<int> heap;
	cin >> opCount;
	while (opCount>0) {
		int opID;
		cin >> opID;
		if (opID == 1) {
			int item;
			cin >> item;
			addItem(heap, item, cur_size);
		}
		else if (opID == 2) {
			int item;
			cin >> item;
			deleteItem(heap, item, cur_size);
		}
		else if (opID == 3)
			cout << heap.at(0) << endl;
		else
			break;
		opCount--;
	}
	return 0;
}