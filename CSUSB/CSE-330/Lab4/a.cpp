3// Adnar Lozano
// CSE 330 Data Structures
// Lab 4 (Linked List 2)
// 4/26/17
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
Node* Insert_Head (Node* head, int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(head != NULL) temp->next = head;
	head = temp;
	return head;
}
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
void Print(Node* head) {
	cout<<"List is:\n";
	while ( head != NULL) {
		cout << head->data << endl;
		head = head->next;
	}
	cout << endl;
}
void ReversePrint(Node *head) {
	if(head == NULL) return;
	ReversePrint(head->next);
	cout << head->data << endl;
}
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
int main() {
	Node* headA = NULL;
	Node* headB = NULL;
	int n,x;
	cout << "Getting values for List A using Insert_Head:\n";
	cout << "how many numbers? \n";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout<<"enter the number: \n";
		cin>>x;
		headA = Insert_Head(headA, x);
		Print(headA);
	}
	
	cout << "Getting values for List B using Insert_Tail:\n";
	cout << "how many numbers? \n";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout<<"enter the number: \n";
		cin>>x;
		headB = Insert_Tail(headB, x);
		Print(headB);
	}
	cout << "Printing List A:\n";
	Print(headA);
	cout << "Printing List B:\n";
	Print(headB);
	cout<<"Inserting 0 at position 4 of List A :\n";
	headA = Insert_Nth(headA, 0, 4);
	Print(headA);
	cout<<"Inserting 0 at position 4 of List B :\n";
	headB = Insert_Nth(headB, 0, 4);
	Print(headB);
	cout<<"Deleting position 3 of List A :\n";
	Delete(headA, 3);
	Print(headA);
	cout<<"Deleting position 3 of List B :\n";
	Delete(headB, 3);
	Print(headB);
	cout<<"Reverse List A is:\n";
	ReversePrint(headA);
	cout << endl;
	cout<<"Reverse List B is:\n";
	ReversePrint(headB);
	cout << endl;
	cout << "Comparing List A and List B\n";
	int r = CompareLists(headA, headB);
	if (r == 0) cout << "result = " << r << "\nTherefore the lists are not the same\n";
	else cout << "result = " << r << "\nTherefore the lists are the same\n";
	return 0;
}