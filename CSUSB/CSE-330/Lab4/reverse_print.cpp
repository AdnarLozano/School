#include  <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void ReversePrint(Node *head) {
	if(head == NULL) return;
	ReversePrint(head->next);
	cout << head->data << endl;
}