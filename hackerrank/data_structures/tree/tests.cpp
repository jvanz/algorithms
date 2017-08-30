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


}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
