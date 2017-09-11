#include <iostream>

#include "tree.h"

namespace jvanz {
namespace tree {

using std::cout;

void PrintPreOrder(struct node* root)
{
	cout << root->data;
	if (root->left)
		PrintPreOrder(root->left);
	if (root->right)
		PrintPreOrder(root->right);

}

void PrintPostOrder(struct node* root)
{
	if (root->left)
		PrintPostOrder(root->left);
	if (root->right)
		PrintPostOrder(root->right);
	cout << root->data;
}

void PrintInOrder(struct node* root)
{
	if (root->left)
		PrintInOrder(root->left);
	cout << root->data;
	if (root->right)
		PrintInOrder(root->right);
}

int GetHeight(struct node* root)
{
	if (!root)
		return -1;
	auto lheight = GetHeight(root->left);
	auto rheight = GetHeight(root->right);
	if (lheight > rheight)
		return lheight + 1;
	else
		return  rheight + 1;
}

}
}
