
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

Node* Reverse(Node *head)
{
	if (!head || !head->next)
		return head;
	auto reverse = Reverse(head->next);
	head->next->next = head;
	head->next = nullptr;
	return reverse;
}

int main(int argc, char** argv)
{
	Node* list = Insert(nullptr, 1, 0);
	for (int i = 1; i < 11; i++)
		list = Insert(list, i+1, i);
	auto bck = list;
	while (bck){
		cout << bck->data << " --> ";
		bck = bck->next;
	}
	cout << "NULL" <<endl;
	list = Reverse(list);
	while (list){
		cout << list->data << " --> ";
		list = list->next;
	}
	cout << "NULL" <<endl;
}
