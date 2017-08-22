#pragma once

struct Node
{
	int data;
	struct Node *next;
};

Node* Insert(Node *head,int data, int position);
Node* Reverse(Node *head);
bool CompareLists(Node* headA, Node* headB);
Node* InsertHead(Node *head,int data);
Node* InsertTail(Node *head,int data);
Node* Delete(Node *head, int position);
Node* MergeLists(Node* headA, Node* headB);
int GetNode(Node* head, int postionFromTail);

/**
 * Remove duplicates values from a sorted linked list
 */
Node* RemoveDuplicates(Node* head);
