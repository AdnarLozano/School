// Adnar Lozano
// CSE 330 Data Structures
// Lab 6
// 5/10/17

#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
};
Node* Insert(Node* head, int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(head != NULL) temp->next = head;
	head = temp;
	return head;
}
void Print(Node* head) {
    while ( head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
void ReversePrint(Node *head) {
    if(head == NULL) return;
    ReversePrint(head->next);
    cout << head->data << " -> ";
}
Node* MergeLists(Node* headA, Node* headB) {
	if (headA == NULL || headB == NULL) 
		return (headA == NULL) ? headB : headA;
	if (headA->data < headB->data) {
		headA->next = MergeLists(headA->next, headB);
		return headA;
	}
	headB->next = MergeLists(headB->next, headA);		
	return headB;
}
int GetNode(Node *head,int positionFromTail) {
	Node* temp = head;
	int index = 0;
	while(head->next) {
		head = head->next;
		if(++index>positionFromTail)
			temp = temp->next;
	}
	return temp->data;
}
bool has_cycle(Node* head) {
	if (head == NULL) return false;
	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next) {
		if (fast->next->next == slow)
			return true;
		fast = fast->next->next;
		slow = slow->next;
	}
	return false;
}
int main() {
	Node* headA = NULL;
	Node* headB = NULL;
	
	headA = Insert(headA, 7);
	headA = Insert(headA, 5);
	headA = Insert(headA, 3);
	headA = Insert(headA, 1);

	headB = Insert(headB, 8);
	headB = Insert(headB, 6);
	headB = Insert(headB, 4);
	headB = Insert(headB, 2);

    cout << "Print List A:\n";
	Print(headA);
    cout << "Reversed Print List A:\n";
	ReversePrint(headA);
	cout << "NULL\n\n";
    cout << "Print List B:\n";
	Print(headB);
    cout << "Reversed Print List:\n";
	ReversePrint(headB);
	cout << "NULL\n\n";
    cout << "Print Merged List:\n";
	MergeLists(headA,headB);
	Print(headA);
	cout << endl;
	cout << "PositionFromTail at (2):\n" << GetNode(headA, 2) << "\n\n";
	cout << "Check if List has a cycle:\n";
	if (has_cycle(headA) == 1) cout << "List has a cycle\n";
	else cout<< "List does NOT have a cycle\n\n";
}