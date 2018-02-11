#include  <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

Node* Insert_Head (Node* head, int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if (head != NULL) temp->next = head;
	head = temp;
	return head;
}