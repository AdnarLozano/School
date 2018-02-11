#include  <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

Node* Delete(Node* head, int position) { 
	Node* temp1 = head; 
	if (position == 1) { 
		head = temp1->next; 
		delete temp1; 
		return temp1; 
	} 
	for(int i = 0; i < position-2; i++)
		temp1 = temp1->next;
	Node *temp2 = temp1->next; 
	temp1->next = temp2->next; 
	delete temp2; 
	return temp1; 
}