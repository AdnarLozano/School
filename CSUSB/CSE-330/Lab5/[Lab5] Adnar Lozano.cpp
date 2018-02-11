/*input
15
*/
// Adnar Lozano
// CSE 330 Data Structures
// Lab 5 (Trees)
// 5/4/17

#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
	int data;
	Node* left;
	Node* right;
};
Node* GetNewNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = GetNewNode(data);
	}
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else root->right = Insert(root->right, data);
	return root; 
}
bool Search(Node* root, int data) {
	if(root == NULL)
		return false;
	else if (root->data == data)
		return true;
	else if (data <= root->data)
		return Search(root->left, data);
	else return Search(root->right, data);
}
// Recursive Function
int FindMin(Node* root) {
	if (root == NULL) {
		cout << "Error: Tree is empty\n";
		return -1;
	}
	while (root->left == NULL)
		return root ->data;
	return FindMin(root->left);
}
// Iterative function
int FindMax(Node* root) {
	if (root == NULL) {
		cout << "Error: Tree is empty\n";
		return -1;
	}
	while (root->right != NULL)
		root = root->right;
	return root->data;
}
int FindHeight(Node* root) {
	if (root == NULL) return -1;
	return max(FindHeight(root->left), FindHeight(root->right))+1;
}
void LevelOrder(Node* root) {
	if(root == NULL) return;
	queue<Node*> Q;
	Q.push(root);
 	while(!Q.empty()) {
		Node* root = Q.front();
		cout << root->data << " ";
		if(root->left != NULL) Q.push(root->left);
		if(root->right != NULL) Q.push(root->right);
		Q.pop();
	}
}
void PreOrder(Node* root) {
	if(root == NULL) return;
	cout << root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}
void InOrder(Node* root) {
	if(root == NULL) return;
	InOrder(root->left);
	cout << root->data << " ";
	InOrder(root->right);
}
void PostOrder(Node* root) {
	if(root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << " ";
}
bool IsBST(Node* root) {
	if(root == NULL) return true;
	if(root->data > INT_MIN && root->data < INT_MAX
		&& IsBST(root->left)
		&& IsBST(root->right))
		return true;
	else return false;
}
void remove(const int x, Node* & t) {
	if ( t == nullptr) return;
	if ( x < t->data) remove(x, t->left);
	else if (t->data < x) remove(x, t->right);
	else if (t->left != NULL && t->right != NULL) {
		t->data = FindMin(t->right);
		remove(t->data, t->right);
	}
	else {
		Node* oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}
}
int main() {
	Node* root = NULL;
	root = Insert(root,3);
	Insert(root,1);
	Insert(root,4);
	Insert(root,6);
	Insert(root,9);
	Insert(root,2);
	Insert(root,5);
	Insert(root,7);

	// int number;
	// cout << "Enter number to search: ";
	// cin >> number;
	// cout << number << endl;
	// if (Search(root,number) == true) cout << "Number was Found\n";
	// else cout << "Number was Not found\n";
	cout << "Root: " << root->data << endl;
	cout << "Min value is: " << FindMin(root) << endl;
	cout << "Max value is: " << FindMax(root) << endl;
	cout << "Height is: " << FindHeight(root) << endl;
	cout << "\nLevelOrder: ";
	LevelOrder(root);
	cout << "\nPreOrder: ";
	PreOrder(root);
	cout << "\nInOrder: ";
	InOrder(root);
	cout << "\nPostOrder: ";
	PostOrder(root);
	if (IsBST(root) == true) cout << "\n\nIt's a Binary Tree\n\n";
	else cout << "Not a Binary Tree\n\n";
	cout << "Removing the root Node\n";
	remove(root->data, root);
	cout << "PreOrder: ";
	PreOrder(root);
	cout << "\nRoot: " << root->data << endl;

	return 0;
}