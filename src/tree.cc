#include <gtest/gtest.h>
#include <array>
#include <iostream>
#include <queue>

#include "tree.hh"

using namespace jvanz::tree;

TreeNode<int> call_move_assignment(TreeNode<int> t) {
	return t;
}

TEST(Tree, CopyTree) {
	ASSERT_TRUE(is_copy_assignable<TreeNode<int>>::value);
	ASSERT_TRUE(is_copy_assignable<TreeNode<long>>::value);
	ASSERT_TRUE(is_copy_assignable<TreeNode<double>>::value);
	ASSERT_TRUE(is_copy_assignable<TreeNode<float>>::value);

	ASSERT_TRUE(is_copy_constructible<TreeNode<int>>::value);
	ASSERT_TRUE(is_copy_constructible<TreeNode<long>>::value);
	ASSERT_TRUE(is_copy_constructible<TreeNode<double>>::value);
	ASSERT_TRUE(is_copy_constructible<TreeNode<float>>::value);

	TreeNode<int> a(1);
	TreeNode<int> b = a;  // copy assignment
	ASSERT_EQ(a.get(), b.get());
	ASSERT_NE(&a, &b);
	b.set(2);
	ASSERT_EQ(a.get(), 1);
	ASSERT_EQ(b.get(), 2);
	b = a;  // copy constructor
	ASSERT_EQ(a.get(), b.get());
	ASSERT_NE(&a, &b);
}

TEST(Tree, MoveTree) {
	ASSERT_TRUE(is_move_assignable<TreeNode<int>>::value);
	ASSERT_TRUE(is_move_assignable<TreeNode<long>>::value);
	ASSERT_TRUE(is_move_assignable<TreeNode<double>>::value);
	ASSERT_TRUE(is_move_assignable<TreeNode<float>>::value);

	ASSERT_TRUE(is_move_constructible<TreeNode<int>>::value);
	ASSERT_TRUE(is_move_constructible<TreeNode<long>>::value);
	ASSERT_TRUE(is_move_constructible<TreeNode<double>>::value);
	ASSERT_TRUE(is_move_constructible<TreeNode<float>>::value);

	TreeNode<int> t(1);
	TreeNode<int> a = std::move(t);
	ASSERT_EQ(a.get(), 1);
	t.set(2);
	TreeNode<int> b;
	b = call_move_assignment(t);
	ASSERT_EQ(b.get(), 2);
	ASSERT_EQ(a.get(), 1);
}

TEST(Tree, Insert) {
	auto root = new TreeNode<int>(1);
	auto left = new TreeNode<int>(0);
	auto right = new TreeNode<int>(2);
	auto comp_func = [](TreeNode<int>* root, TreeNode<int>* child) -> int {
		return child->get() - root->get();
	};
	insert<int>(root, left, comp_func);
	insert<int>(root, right, comp_func);
	ASSERT_EQ(root->get_left(), left);
	ASSERT_EQ(root->get_right(), right);
	ASSERT_EQ(root->get(), 1);
	ASSERT_EQ(root->get_left()->get(), 0);
	ASSERT_EQ(root->get_right()->get(), 2);
	delete root;
}

TEST(Tree, Insert2) {
	auto one = new TreeNode<int>(1);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	auto five = new TreeNode<int>(5);
	auto comp_func = [](TreeNode<int>* root, TreeNode<int>* child) -> int {
		return child->get() - root->get();
	};
	insert<int>(one, two, comp_func);
	insert<int>(one, three, comp_func);
	insert<int>(one, four, comp_func);
	insert<int>(one, five, comp_func);
	ASSERT_EQ(one->get_left(), nullptr);
	ASSERT_EQ(one->get_right(), two);
	ASSERT_EQ(one->get_right()->get(), 2);
	ASSERT_EQ(two->get_left(), nullptr);
	ASSERT_EQ(two->get_right(), three);
	ASSERT_EQ(two->get_right()->get(), 3);
	ASSERT_EQ(three->get_left(), nullptr);
	ASSERT_EQ(three->get_right(), four);
	ASSERT_EQ(three->get_right()->get(), 4);
	ASSERT_EQ(four->get_left(), nullptr);
	ASSERT_EQ(four->get_right(), five);
	ASSERT_EQ(four->get_right()->get(), 5);
	ASSERT_EQ(five->get_left(), nullptr);
	ASSERT_EQ(five->get_right(), nullptr);
	delete one;
}

TEST(Tree, VertialOrderTraversal) {
	vector<int> input{1, 14, 3, 7, 4, 5, 15, 6, 13, 10, 11, 2, 12, 8, 9};
	vector<TreeNode<int>*> nodes;
	for (auto i : input)
		nodes.push_back(new TreeNode<int>(i));
	auto comp_func = [](TreeNode<int>* root, TreeNode<int>* child) -> int {
		return child->get() - root->get();
	};
	for (unsigned int i = 1; i < nodes.size(); i++)
		insert<int>(nodes[0], nodes[i], comp_func);
	map<int, int> distances{{1, 0},  {14, 1}, {3, 0},  {7, 1},  {4, 0},
				{5, 1},  {15, 2}, {6, 2},  {13, 2}, {10, 1},
				{11, 2}, {2, -1}, {12, 3}, {8, 0},  {9, 1}};
	vertical_traversal<int>(
	    nodes[0], [&distances](TreeNode<int>* node, unsigned int distance) {
		    ASSERT_EQ(distances[node->get()], distance);
	    });
}

TEST(Tree, VertialOrderTraversal2) {
	auto one = new TreeNode<int>(1);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	auto five = new TreeNode<int>(5);
	auto comp_func = [](TreeNode<int>* root, TreeNode<int>* child) -> int {
		return child->get() - root->get();
	};
	insert<int>(one, two, comp_func);
	insert<int>(one, three, comp_func);
	insert<int>(one, four, comp_func);
	insert<int>(one, five, comp_func);

	map<int, int> distances{{1, 0}, {2, 1}, {3, 2}, {4, 3}, {5, 4}};
	vertical_traversal<int>(
	    one, [&distances](TreeNode<int>* node, int distance) {
		    ASSERT_EQ(distances[node->get()], distance);
	    });
	delete one;
}

TEST(Tree, VertialOrderTraversal3) {
	auto one = new TreeNode<int>(1);
	auto two = new TreeNode<int>(2);
	auto three = new TreeNode<int>(3);
	auto four = new TreeNode<int>(4);
	auto five = new TreeNode<int>(5);
	auto comp_func = [](TreeNode<int>* root, TreeNode<int>* child) -> int {
		return child->get() - root->get();
	};
	insert<int>(five, four, comp_func);
	insert<int>(five, three, comp_func);
	insert<int>(five, two, comp_func);
	insert<int>(five, one, comp_func);

	map<int, int> distances{{1, -4}, {2, -3}, {3, -2}, {4, -1}, {5, 0}};
	vertical_traversal<int>(
	    five, [&distances](TreeNode<int>* node, int distance) {
		    ASSERT_EQ(distances[node->get()], distance);
	    });
	delete five;
}

TEST(Tree, LevelOrderTraversal) {
	auto root = new TreeNode<int>(1);
	auto left = new TreeNode<int>(0);
	auto right = new TreeNode<int>(2);
	auto comp_func = [](TreeNode<int>* root, TreeNode<int>* child) -> int {
		return child->get() - root->get();
	};
	insert<int>(root, left, comp_func);
	insert<int>(root, right, comp_func);
	ASSERT_EQ(root->get_left(), left);
	ASSERT_EQ(root->get_right(), right);
	ASSERT_EQ(root->get(), 1);
	ASSERT_EQ(root->get_left()->get(), 0);
	ASSERT_EQ(root->get_right()->get(), 2);

	std::array<int, 3> expectedvalues = {1, 0, 2};
	std::array<int, 3> distances = {0, -1, 1};
	std::queue<int> expected;
	std::queue<int> expecteddistances;
	for (auto v : expectedvalues)
		expected.push(v);
	for (auto v : distances)
		expecteddistances.push(v);
	level_traversal<int>(root, [&expected, &expecteddistances](
				       TreeNode<int>* node, int distance) {
		ASSERT_EQ(expected.front(), node->get());
		ASSERT_EQ(expecteddistances.front(), distance);
		expected.pop();
		expecteddistances.pop();
	});
	ASSERT_EQ(expected.size(), 0);
	ASSERT_EQ(expecteddistances.size(), 0);
	delete root;
}

TEST(Tree, LevelOrderTraversal2) {
	vector<int> input{1, 14, 3, 7, 4, 5, 15, 6, 13, 10, 11, 2, 12, 8, 9};
	vector<TreeNode<int>*> nodes;
	for (auto i : input)
		nodes.push_back(new TreeNode<int>(i));
	auto comp_func = [](TreeNode<int>* root, TreeNode<int>* child) -> int {
		return child->get() - root->get();
	};
	for (unsigned int i = 1; i < nodes.size(); i++)
		insert<int>(nodes[0], nodes[i], comp_func);

	std::array<int, 15> expectedvalues = {1, 14, 3, 15, 2,  7, 4, 13,
					      5, 10, 6, 8,  11, 9, 12};
	std::array<int, 15> distances = {0, 1, 0, 2, -1, 1, 0, 2,
					 1, 1, 2, 0, 2,  1, 3};
	std::queue<int> expected;
	std::queue<int> expecteddistances;
	for (auto v : expectedvalues)
		expected.push(v);
	for (auto v : distances)
		expecteddistances.push(v);
	level_traversal<int>(nodes[0], [&expected, &expecteddistances](
					   TreeNode<int>* node, int distance) {
		ASSERT_EQ(expected.front(), node->get());
		expected.pop();
		ASSERT_EQ(expecteddistances.front(), distance);
		expecteddistances.pop();
	});
	ASSERT_EQ(expected.size(), 0);
	ASSERT_EQ(expecteddistances.size(), 0);
}
