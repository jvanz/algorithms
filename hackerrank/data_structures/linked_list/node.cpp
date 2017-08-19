#include "node.h"

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

bool CompareLists(Node* headA, Node* headB)
{
	if ((headA && !headB) || (!headA && headB))
		return false;
	return (!headA && !headB) || (headA->data == headB->data && CompareLists(headA->next, headB->next));
}

Node* InsertHead(Node *head,int data)
{
	auto node = new Node();
	node->data = data;
	node->next = head;
	return node;
}
