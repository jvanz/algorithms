#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

void Print(Node *head)
{
	while (head){
		cout << head->data << endl;
		head = head->next;
	}

}

int main(int argc, char** argv){
	auto node = new Node();
	auto node2 = new Node();
	auto node3 = new Node();
	node->data = 1;
	node2->data = 2;
	node3->data = 3;
	node->next = node2;
	node2->next = node3;
	Print(node);
	Print(NULL);

}
