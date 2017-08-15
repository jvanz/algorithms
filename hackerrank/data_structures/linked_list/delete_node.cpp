
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

Node* Delete(Node *head, int position)
{
	Node* current = head;
	Node* previous = nullptr;
	while (position-- > 0 && current){
		previous = current;
		current = current->next;
	}
	if (previous == nullptr)
		head = current->next;
	else if (current)
		previous->next = current->next;
	if (current)
		delete current;
	return head;
}

int main(int argc, char** argv)
{
	Node* list = Insert(nullptr, 1, 0);
	Insert(list, 2, 1);
	Node* bck = list;
	while(list){
		cout << list->data << " -> ";
		list = list->next;
	}
	cout << "NULL" << endl;
	list = Delete(bck, 1);
	while(list){
		cout << list->data << " -> ";
		list = list->next;
	}
	cout << "NULL" << endl;
}
