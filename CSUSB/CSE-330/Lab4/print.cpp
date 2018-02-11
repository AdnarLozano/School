#include  <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void Print(Node* head) {
	cout<<"List is:\n";
	while ( head != NULL) {
		cout << head->data << endl;
		head = head->next;
	}
	cout << endl;
}