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

}
}
