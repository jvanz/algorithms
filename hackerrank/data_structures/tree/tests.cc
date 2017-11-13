#include <gtest/gtest.h>

#include "tree.hh"

namespace {

using namespace jvanz::tree;

TEST(Tree, PreOrderIterator)
{
	auto zero = new TreeNode(0);
	auto one = new TreeNode(1);
	auto two = new TreeNode(2);
	auto three = new TreeNode(3);
	auto four = new TreeNode(4);
	auto five = new TreeNode(5);
	auto six = new TreeNode(6);
	auto seven = new TreeNode(7);
	auto eight = new TreeNode(8);
	zero->left = one;
	one->left = two;
	one->right = three;
	zero->right = four;
	four->left = five;
	four->right = six;
	six->left = seven;
	six->right = eight;
	unsigned int x = 0;
	for (auto n : (*zero)){
		ASSERT_EQ(x, n.data);
		x++;
	}
	ASSERT_EQ(9, x);
}

//TEST(Tree, PrintPreOrder)
//{
	//auto zero = new struct node();
	//auto one = new struct node();
	//auto two = new struct node();
	//auto three = new struct node();
	//auto four = new struct node();
	//zero->data = 0;
	//one->data = 1;
	//two->data = 2;
	//three->data = 3;
	//four->data = 4;
	//one->left = zero;
	//one->left = two;
	//two->left = three;
	//two->right = four;
	//PrintPreOrder(one);

//}

//TEST(Tree, PrintPostOrder)
//{
	//auto one = new struct node();
	//auto two = new struct node();
	//auto three = new struct node();
	//auto four = new struct node();
	//auto five = new struct node();
	//auto six = new struct node();
	//one->data = 1;
	//two->data = 2;
	//three->data = 3;
	//four->data = 4;
	//five->data = 5;
	//six->data = 6;
	//one->right = two;
	//two->right = five;
	//three->right = four;
	//five->left = three;
	//five->right = six;
	//PrintPostOrder(one);
//}

//TEST(Tree, PrintInOrder)
//{
	//auto one = new struct node();
	//auto two = new struct node();
	//auto three = new struct node();
	//auto four = new struct node();
	//auto five = new struct node();
	//auto six = new struct node();
	//one->data = 1;
	//two->data = 2;
	//three->data = 3;
	//four->data = 4;
	//five->data = 5;
	//six->data = 6;
	//one->right = two;
	//two->right = five;
	//five->left = three;
	//five->right = six;
	//three->right = four;
	//PrintInOrder(one);
//}

//TEST(Tree, GetHeight)
//{
	//auto one = new struct node();
	//auto two = new struct node();
	//auto three = new struct node();
	//auto four = new struct node();
	//auto five = new struct node();
	//auto six = new struct node();
	//auto seven = new struct node();
	//one->data = 1;
	//two->data = 2;
	//three->data = 3;
	//four->data = 4;
	//five->data = 5;
	//six->data = 6;
	//seven->data = 7;
	//two->left = one;
	//three->left = two;
	//three->right = five;
	//five->left = four;
	//five->right = six;
	//six->right = seven;
	//auto height = GetHeight(three);
	//ASSERT_EQ(3, height);
//}

//TEST(Tree, Insert)
//{
	//using std::cout;
	//using std::endl;
	//auto root = Insert(nullptr, 4);
	//root = Insert(root, 2);
	//root = Insert(root, 3);
	//root = Insert(root, 1);
	//root = Insert(root, 6);
	//root = Insert(root, 5);
	//root = Insert(root, 7);
	//// validate tree structure
	//ASSERT_NE(nullptr, root);
	//ASSERT_NE(nullptr, root->left);
	//ASSERT_NE(nullptr, root->left->left);
	//ASSERT_NE(nullptr, root->left->right);
	//ASSERT_EQ(nullptr, root->left->left->left);
	//ASSERT_EQ(nullptr, root->left->left->right);
	//ASSERT_EQ(nullptr, root->left->right->left);
	//ASSERT_EQ(nullptr, root->left->right->right);
	//ASSERT_NE(nullptr, root->right);
	//ASSERT_NE(nullptr, root->right->left);
	//ASSERT_NE(nullptr, root->right->right);
	//ASSERT_EQ(nullptr, root->right->left->left);
	//ASSERT_EQ(nullptr, root->right->left->right);
	//ASSERT_EQ(nullptr, root->right->right->left);
	//ASSERT_EQ(nullptr, root->right->right->right);
	//// validate node data
	//ASSERT_EQ(4, root->data);
	//ASSERT_EQ(2, root->left->data);
	//ASSERT_EQ(1, root->left->left->data);
	//ASSERT_EQ(3, root->left->right->data);
	//ASSERT_EQ(6, root->right->data);
	//ASSERT_EQ(5, root->right->left->data);
	//ASSERT_EQ(7, root->right->right->data);
//}

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
