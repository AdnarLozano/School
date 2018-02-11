#include  <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

int CompareLists(Node *headA, Node* headB) {
	while (headA != NULL && headB != NULL) {
		if (headA->data != headB->data)
			return 0;
		headA = headA->next;
		headB = headB->next;
	}
	if (headA == NULL && headB == NULL)
		return 1;
	else
		return 0;
}