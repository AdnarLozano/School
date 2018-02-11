#include  <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

Node* Insert_Tail (Node* head, int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) head = temp;
	else {
		Node* temp1 = new Node();
		temp1 = head;
		while ( temp1->next != NULL) temp1 = temp1->next;
		temp1->next = temp;
	}
	return head;
}