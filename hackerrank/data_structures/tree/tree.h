#pragma once

namespace jvanz {
namespace tree {

struct node
{
	struct node* left;
	struct node* right;
	int data;
};

void PrintPreOrder(struct node* root);
void PrintPostOrder(struct node* root);
void PrintInOrder(struct node* root);
int GetHeight(struct node* root);

/**
 * Insert new node in the binary tree
 * @node pointer to the tree root
 * @value value to be added in the tree
 */
struct node* Insert(struct node*, int value);

}
}
