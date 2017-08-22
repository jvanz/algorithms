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

Node* InsertTail(Node *head,int data)
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

Node* MergeLists(Node* headA, Node* headB)
{
	if (!headA || !headB)
		return headA ? headA : headB;
	Node* merge;
	if (headA->data < headB->data) {
		merge = headA;
		merge->next = MergeLists(headA->next, headB);
	} else {
		merge = headB;
		merge->next = MergeLists(headA, headB->next);
	}
	return merge;
}

int GetNode(Node* head, int positionFromTail)
{
	auto ptr1 = head;
	auto ptr2 = head;
	auto len = 0;
	while (ptr1){
		ptr1 = ptr1->next;
		if (len > positionFromTail)
			ptr2 = ptr2->next;
		len += 1;
	}
	return ptr2->data;
}

Node* RemoveDuplicates(Node* head)
{
	if (!head || !head->next)
		return head;
	auto ptr1 = RemoveDuplicates(head->next);
	if (head->data == ptr1->data){
		delete head;
		return ptr1;
	} else {
		head->next = ptr1;
	}
	return head;
}
