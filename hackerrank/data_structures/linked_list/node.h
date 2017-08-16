#pragma once

struct Node
{
	int data;
	struct Node *next;
};

Node* Insert(Node *head,int data, int position);
Node* Reverse(Node *head);
bool CompareLists(Node* headA, Node* headB);