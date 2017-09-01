#include <gtest/gtest.h>

#include "tree.h"

namespace {

using namespace jvanz::tree;

TEST(Tree, PrintPreOrder)
{
	auto zero = new struct node();
	auto one = new struct node();
	auto two = new struct node();
	auto three = new struct node();
	auto four = new struct node();
	zero->data = 0;
	one->data = 1;
	two->data = 2;
	three->data = 3;
	four->data = 4;
	one->left = zero;
	one->left = two;
	two->left = three;
	two->right = four;
	PrintPreOrder(one);

}

TEST(Tree, PrintPostOrder)
{
	auto one = new struct node();
	auto two = new struct node();
	auto three = new struct node();
	auto four = new struct node();
	auto five = new struct node();
	auto six = new struct node();
	one->data = 1;
	two->data = 2;
	three->data = 3;
	four->data = 4;
	five->data = 5;
	six->data = 6;
	one->right = two;
	two->right = five;
	three->right = four;
	five->left = three;
	five->right = six;
	PrintPostOrder(one);
}

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
