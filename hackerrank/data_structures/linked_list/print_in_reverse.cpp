
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

void ReversePrint(Node *head)
{
	if (!head)
		return;
	ReversePrint(head->next);
	cout << head->data << endl;
}

int main(int argc, char** argv)
{
	Node* list = Insert(nullptr, 1, 0);
	for (int i = 2; i < 11; i++)
		list = Insert(list, i, 0);
	ReversePrint(list);
}
