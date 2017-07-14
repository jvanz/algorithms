#include <iostream>

using std::cout;
using std::endl;

struct Node {
	int data;
	struct Node *next;
};

Node* Insert(Node *head,int data)
{
	auto node = new Node();
	node->data = data;
	node->next = head;
	return node;
}

int main(int argc, char** argv)
{
	Node* head = nullptr;
	head = Insert(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 3);
	while (head){
		cout << head->data << " --> ";
		Node* prev = head;
		head = head->next;
		delete prev;
	}
	cout << "NULL"<< endl;
}

