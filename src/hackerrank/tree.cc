#include <gtest/gtest.h>
#include <iostream>

#include "tree.hh"

using namespace jvanz::tree;

TEST(HackerRankTree, pre_order_iterator) {
	auto zero = new TreeNode<int>(0);
	auto one = new TreeNode<int>(1);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	auto five = new TreeNode<int>(5);
	auto six = new TreeNode<int>(6);
	auto seven = new TreeNode<int>(7);
	auto eight = new TreeNode<int>(8);
	zero->set_left(one);
	one->set_left(two);
	one->set_right(three);
	zero->set_right(four);
	four->set_left(five);
	four->set_right(six);
	six->set_left(seven);
	six->set_right(eight);
	unsigned int x = 0;
	pre_order_iterator<int>(zero, [&x](int data) {
		ASSERT_EQ(x, data);
		x++;
	});
	ASSERT_EQ(9, x);
	delete zero;
}

TEST(HackerRankTree, post_order_iterator) {
	auto zero = new TreeNode<int>(0);
	auto one = new TreeNode<int>(1);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	auto five = new TreeNode<int>(5);
	auto six = new TreeNode<int>(6);
	auto seven = new TreeNode<int>(7);
	auto eight = new TreeNode<int>(8);
	zero->set_left(one);
	one->set_left(two);
	one->set_right(three);
	zero->set_right(four);
	four->set_left(five);
	four->set_right(six);
	six->set_left(seven);
	six->set_right(eight);
	unsigned int order[9] = {2, 3, 1, 5, 7, 8, 6, 4, 0};
	auto x = 0;
	post_order_iterator<int>(zero, [&x, &order](int data) {
		ASSERT_EQ(order[x], data);
		x++;
	});
	ASSERT_EQ(9, x);
	delete zero;
}

TEST(HackerRankTree, in_order_iterator) {
	auto zero = new TreeNode<int>(0);
	auto one = new TreeNode<int>(1);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	auto five = new TreeNode<int>(5);
	auto six = new TreeNode<int>(6);
	auto seven = new TreeNode<int>(7);
	auto eight = new TreeNode<int>(8);
	zero->set_left(one);
	one->set_left(two);
	one->set_right(three);
	zero->set_right(four);
	four->set_left(five);
	four->set_right(six);
	six->set_left(seven);
	six->set_right(eight);
	unsigned int order[9] = {2, 1, 3, 0, 5, 4, 7, 6, 8};
	auto x = 0;
	in_order_iterator<int>(zero, [&x, &order](int data) {
		ASSERT_EQ(order[x], data);
		x++;
	});
	ASSERT_EQ(9, x);
	delete zero;
}

TEST(HackerRankTree, get_height) {
	auto one = new TreeNode<int>(0);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	auto five = new TreeNode<int>(5);
	auto six = new TreeNode<int>(6);
	auto seven = new TreeNode<int>(7);
	two->set_left(one);
	three->set_left(two);
	three->set_right(five);
	five->set_left(four);
	five->set_right(six);
	six->set_right(seven);
	auto height = get_height<int>(three);
	ASSERT_EQ(3, height);
	delete one;
}

TEST(HackerRankTree, insert) {
	auto root = insert<int>(nullptr, 4);
	root = insert<int>(root, 2);
	root = insert<int>(root, 3);
	root = insert<int>(root, 1);
	root = insert<int>(root, 6);
	root = insert<int>(root, 5);
	root = insert<int>(root, 7);
	// validate tree structure
	ASSERT_NE(nullptr, root);
	ASSERT_NE(nullptr, root->get_left());
	ASSERT_NE(nullptr, root->get_left()->get_left());
	ASSERT_NE(nullptr, root->get_left()->get_right());
	ASSERT_EQ(nullptr, root->get_left()->get_left()->get_left());
	ASSERT_EQ(nullptr, root->get_left()->get_left()->get_right());
	ASSERT_EQ(nullptr, root->get_left()->get_right()->get_left());
	ASSERT_EQ(nullptr, root->get_left()->get_right()->get_right());
	ASSERT_NE(nullptr, root->get_right());
	ASSERT_NE(nullptr, root->get_right()->get_left());
	ASSERT_NE(nullptr, root->get_right()->get_right());
	ASSERT_EQ(nullptr, root->get_right()->get_left()->get_left());
	ASSERT_EQ(nullptr, root->get_right()->get_left()->get_right());
	ASSERT_EQ(nullptr, root->get_right()->get_right()->get_left());
	ASSERT_EQ(nullptr, root->get_right()->get_right()->get_right());
	// validate node data
	ASSERT_EQ(4, root->get());
	ASSERT_EQ(2, root->get_left()->get());
	ASSERT_EQ(1, root->get_left()->get_left()->get());
	ASSERT_EQ(3, root->get_left()->get_right()->get());
	ASSERT_EQ(6, root->get_right()->get());
	ASSERT_EQ(5, root->get_right()->get_left()->get());
	ASSERT_EQ(7, root->get_right()->get_right()->get());
}

TEST(HackerRankTree, huffman_decode) {
	HuffmanNode<char> bnode('B');
	HuffmanNode<char> cnode('C');
	HuffmanNode<char> anode('A');
	HuffmanNode<char> internal('\0', &bnode, &cnode);
	HuffmanNode<char> huff('\0', &internal, &anode);
	auto s = "1001011";
	auto decoded_str = decode_huffman<char, '\0'>(&huff, s);
	ASSERT_EQ("ABACA", decoded_str) << "Invalid huffman decoding";
}

TEST(HackerRankTree, PreOrderIterator) {
	auto zero = new TreeNode<int>(0);
	auto one = new TreeNode<int>(1);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	zero->set_left(one);
	zero->set_right(four);
	one->set_left(two);
	one->set_right(three);
	unsigned int x = 0;
	for (auto&& n : *zero) {
		ASSERT_EQ(x, n.get());
		x++;
	}
	ASSERT_EQ(5, x);
}

TEST(HackerRankTree, PreOrderIterator2) {
	auto zero = new TreeNode<int>(0);
	auto one = new TreeNode<int>(1);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	auto five = new TreeNode<int>(5);
	auto six = new TreeNode<int>(6);
	auto seven = new TreeNode<int>(7);
	auto eight = new TreeNode<int>(8);
	zero->set_left(one);
	one->set_left(two);
	one->set_right(three);
	zero->set_right(four);
	four->set_left(five);
	four->set_right(six);
	six->set_left(seven);
	six->set_right(eight);
	unsigned int x = 0;
	for (auto&& n : *zero) {
		ASSERT_EQ(x, n.get());
		x++;
	}
	ASSERT_EQ(9, x);
}

TEST(HackerRankTree, TopView) {
	// https://www.hackerrank.com/challenges/tree-top-view/problem
	auto one = new TreeNode<int>(1);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	auto five = new TreeNode<int>(5);
	auto six = new TreeNode<int>(6);
	one->set_right(two);
	two->set_right(five);
	five->set_left(three);
	five->set_right(six);
	three->set_right(four);

	std::array<int, 4> expectedvalues = {1, 2, 5, 6};
	std::queue<int> expected;
	for (auto v : expectedvalues)
		expected.push(v);

	top_view<int>(one, [&expected](TreeNode<int>* node) {
		ASSERT_EQ(expected.front(), node->get());
		expected.pop();
	});
	ASSERT_EQ(expected.size(), 0);
	delete one;
}

TEST(HackerRankTree, TopView2) {
	// https://www.hackerrank.com/challenges/tree-top-view/problem
	auto one = new TreeNode<int>(1);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	auto five = new TreeNode<int>(5);
	auto six = new TreeNode<int>(6);
	auto seven = new TreeNode<int>(7);
	auto eight = new TreeNode<int>(8);
	auto nine = new TreeNode<int>(9);
	one->set_right(two);
	two->set_right(five);
	five->set_left(three);
	five->set_right(six);
	three->set_right(four);
	one->set_left(seven);
	seven->set_right(eight);
	seven->set_left(nine);
	std::array<int, 6> expectedvalues = {9, 7, 1, 2, 5, 6};
	std::queue<int> expected;
	for (auto v : expectedvalues)
		expected.push(v);

	top_view<int>(one, [&expected](TreeNode<int>* node) {
		ASSERT_EQ(expected.front(), node->get());
		expected.pop();
	});
	ASSERT_EQ(expected.size(), 0);
	delete one;
}

TEST(HackerRankTree, TopView3) {
	// https://www.hackerrank.com/challenges/tree-top-view/problem
	vector<int> input{1, 14, 3, 7, 4, 5, 15, 6, 13, 10, 11, 2, 12, 8, 9};
	vector<TreeNode<int>*> nodes;
	for (auto i : input)
		nodes.push_back(new TreeNode<int>(i));
	auto comp_func = [](TreeNode<int>* root, TreeNode<int>* child) -> int {
		return child->get() - root->get();
	};
	for (unsigned int i = 1; i < nodes.size(); i++)
		insert<int>(nodes[0], nodes[i], comp_func);

	std::array<int, 5> expectedvalues = {2, 1, 14, 15, 12};
	std::queue<int> expected;
	for (auto v : expectedvalues)
		expected.push(v);

	top_view<int>(nodes[0], [&expected](TreeNode<int>* node) {
		ASSERT_EQ(expected.front(), node->get());
		expected.pop();
	});
	ASSERT_EQ(expected.size(), 0);
}
