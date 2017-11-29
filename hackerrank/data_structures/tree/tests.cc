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

TEST(Tree, pre_order_iterator)
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
	pre_order_iterator(zero,
		[&x] (int data) {
			ASSERT_EQ(x, data);
			x++;
		}
	);
	ASSERT_EQ(9, x);
}

TEST(Tree, post_order_iterator)
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
	unsigned int order[9] = {2, 3, 1, 5, 7, 8, 6, 4, 0};
	auto x = 0;
	post_order_iterator(zero,
		[&x, &order] (int data) {
			ASSERT_EQ(order[x], data);
			x++;
		}
	);
	ASSERT_EQ(9, x);
}

TEST(Tree, in_order_iterator)
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
	unsigned int order[9] = {2, 1, 3, 0, 5, 4, 7, 6, 8};
	auto x = 0;
	in_order_iterator(zero,
		[&x, &order] (int data) {
			ASSERT_EQ(order[x], data);
			x++;
		}
	);
	ASSERT_EQ(9, x);
}

TEST(Tree, get_height)
{
	auto one = new TreeNode(0);
	auto two = new TreeNode(2);
	auto three = new TreeNode(3);
	auto four = new TreeNode(4);
	auto five = new TreeNode(5);
	auto six = new TreeNode(6);
	auto seven = new TreeNode(7);
	two->left = one;
	three->left = two;
	three->right = five;
	five->left = four;
	five->right = six;
	six->right = seven;
	auto height = get_height(three);
	ASSERT_EQ(3, height);
}

TEST(Tree, insert)
{
	auto root = insert(nullptr, 4);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 5);
	root = insert(root, 7);
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

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
