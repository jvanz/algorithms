#pragma once

struct Node
{
	int data;
	struct Node *next;
};

Node* Insert(Node *head,int data, int position);
Node* Reverse(Node *head);
