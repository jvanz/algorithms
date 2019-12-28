#include <gtest/gtest.h>

#include "tree.hh"

using namespace jvanz::tree;

TEST(Tree, pre_order_iterator)
{
	auto zero = new TreeNode<int>(0);
	auto one = new TreeNode<int>(1);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	auto five = new TreeNode<int>(5);
	auto six = new TreeNode<int>(6);
	auto seven = new TreeNode<int>(7);
	auto eight = new TreeNode<int>(8);
	zero->left = one;
	one->left = two;
	one->right = three;
	zero->right = four;
	four->left = five;
	four->right = six;
	six->left = seven;
	six->right = eight;
	unsigned int x = 0;
	pre_order_iterator<int>(zero,
		[&x] (int data) {
			ASSERT_EQ(x, data);
			x++;
		}
	);
	ASSERT_EQ(9, x);
	delete zero;
}

TEST(Tree, post_order_iterator)
{
	auto zero = new TreeNode<int>(0);
	auto one = new TreeNode<int>(1);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	auto five = new TreeNode<int>(5);
	auto six = new TreeNode<int>(6);
	auto seven = new TreeNode<int>(7);
	auto eight = new TreeNode<int>(8);
	zero->left = one;
	one->left = two;
	one->right = three;
	zero->right = four;
	four->left = five;
	four->right = six;
	six->left = seven;
	six->right = eight;
	unsigned int order[9] = {2, 3, 1, 5, 7, 8, 6, 4, 0};
	auto x = 0;
	post_order_iterator<int>(zero,
		[&x, &order] (int data) {
			ASSERT_EQ(order[x], data);
			x++;
		}
	);
	ASSERT_EQ(9, x);
	delete zero;
}

TEST(Tree, in_order_iterator)
{
	auto zero = new TreeNode<int>(0);
	auto one = new TreeNode<int>(1);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	auto five = new TreeNode<int>(5);
	auto six = new TreeNode<int>(6);
	auto seven = new TreeNode<int>(7);
	auto eight = new TreeNode<int>(8);
	zero->left = one;
	one->left = two;
	one->right = three;
	zero->right = four;
	four->left = five;
	four->right = six;
	six->left = seven;
	six->right = eight;
	unsigned int order[9] = {2, 1, 3, 0, 5, 4, 7, 6, 8};
	auto x = 0;
	in_order_iterator<int>(zero,
		[&x, &order] (int data) {
			ASSERT_EQ(order[x], data);
			x++;
		}
	);
	ASSERT_EQ(9, x);
	delete zero;
}

TEST(Tree, get_height)
{
	auto one = new TreeNode<int>(0);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	auto five = new TreeNode<int>(5);
	auto six = new TreeNode<int>(6);
	auto seven = new TreeNode<int>(7);
	two->left = one;
	three->left = two;
	three->right = five;
	five->left = four;
	five->right = six;
	six->right = seven;
	auto height = get_height<int>(three);
	ASSERT_EQ(3, height);
	delete one;
}

TEST(Tree, insert)
{
	auto root = insert<int>(nullptr, 4);
	root = insert<int>(root, 2);
	root = insert<int>(root, 3);
	root = insert<int>(root, 1);
	root = insert<int>(root, 6);
	root = insert<int>(root, 5);
	root = insert<int>(root, 7);
	// validate tree structure
	ASSERT_NE(nullptr, root);
	ASSERT_NE(nullptr, root->left);
	ASSERT_NE(nullptr, root->left->left);
	ASSERT_NE(nullptr, root->left->right);
	ASSERT_EQ(nullptr, root->left->left->left);
	ASSERT_EQ(nullptr, root->left->left->right);
	ASSERT_EQ(nullptr, root->left->right->left);
	ASSERT_EQ(nullptr, root->left->right->right);
	ASSERT_NE(nullptr, root->right);
	ASSERT_NE(nullptr, root->right->left);
	ASSERT_NE(nullptr, root->right->right);
	ASSERT_EQ(nullptr, root->right->left->left);
	ASSERT_EQ(nullptr, root->right->left->right);
	ASSERT_EQ(nullptr, root->right->right->left);
	ASSERT_EQ(nullptr, root->right->right->right);
	// validate node data
	ASSERT_EQ(4, root->data);
	ASSERT_EQ(2, root->left->data);
	ASSERT_EQ(1, root->left->left->data);
	ASSERT_EQ(3, root->left->right->data);
	ASSERT_EQ(6, root->right->data);
	ASSERT_EQ(5, root->right->left->data);
	ASSERT_EQ(7, root->right->right->data);
}

TEST(Tree, huffman_decode)
{
	HuffmanNode<char> bnode('B');
	HuffmanNode<char> cnode('C');
	HuffmanNode<char> anode('A');
	HuffmanNode<char> internal('\0', &bnode, &cnode);
	HuffmanNode<char> huff('\0', &internal, &anode);
	auto s = "1001011";
	auto decoded_str = decode_huffman<char, '\0'>(&huff, s);
	ASSERT_EQ("ABACA", decoded_str) << "Invalid huffman decoding";


}
