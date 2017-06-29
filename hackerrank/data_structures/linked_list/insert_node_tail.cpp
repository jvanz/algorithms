
#include <iostream>

using std::cout;
using std::endl;

struct Node
{
	int data;
	struct Node *next;
};

Node* Insert(Node *head,int data)
{
	// create the new node
	Node* newNode = new Node();
	newNode->next = nullptr;
	newNode->data = data;

	if (!head){
		// first node, return the head
		return newNode;
	}
	// find the last node
	Node* h = head;
	while (h->next)
		h = h->next;
	h->next = newNode;
	return head;
}

int main(int argc, char** argv)
{
	Node* list = Insert(nullptr, 1);
	Insert(list, 4);
	Insert(list, 2);
	Insert(list, 3);
	while(list){
		cout << list->data << " -> ";
		list = list->next;
	}
	cout << "NULL" << endl;
}
