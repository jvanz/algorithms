
#include <iostream>

using std::cout;
using std::endl;

struct Node
{
	int data;
	struct Node *next;
};

Node* Insert(Node *head,int data, int position)
{
	// create the new node
	Node* newNode = new Node();
	newNode->next = nullptr;
	newNode->data = data;

	if (!head || position == 0){
		newNode->next = head;
		return newNode;
	}
	Node* h = head;
	while (--position > 0 && h->next)
		h = h->next;

	newNode->next = h->next;
	h->next = newNode;
	return head;
}

int main(int argc, char** argv)
{
	Node* list = Insert(nullptr, 1, 0);
	Insert(list, 2, 1);
	Insert(list, 3, 2);
	Insert(list, 4, 3);
	Insert(list, 5, 4);
	list = Insert(list, 6, 0);
	while(list){
		cout << list->data << " -> ";
		list = list->next;
	}
	cout << "NULL" << endl;
}
