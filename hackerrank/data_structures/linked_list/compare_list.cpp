
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

bool CompareLists(Node* headA, Node* headB)
{
	if ((headA && !headB) || (!headA && headB))
		return false;
	return (!headA && !headB) || (headA->data == headB->data && CompareLists(headA->next, headB->next));
}

int main(int argc, char** argv)
{
	Node* list = Insert(nullptr, 1, 0);
	Node* list2 = Insert(nullptr, 1, 0);
	for (int i = 1; i < 11; i++)
		list = Insert(list, i+1, i);
	for (int i = 1; i < 11; i++)
		list2 = Insert(list2, i+1, i);
	cout << "The lists are " << (CompareLists(list, list2) ? "equal" : "different") << endl;
}
