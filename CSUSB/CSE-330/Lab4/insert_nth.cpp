#include  <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

Node* Insert_Nth(Node* head, int data, int position) {
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if (position == 1) {
        temp1->next = head;
        head = temp1;
        return head;
    }
    Node* temp2 = head;
    for (int i = 0; i < position-2; i++) 
        temp2 = temp2->next;
    temp1->next = temp2->next;  
    temp2->next = temp1;
    return head;
}