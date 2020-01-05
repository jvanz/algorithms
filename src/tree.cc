#include <gtest/gtest.h>

#include "tree.hh"

using namespace jvanz::tree;

TreeNode<int> call_move_assignment(TreeNode<int> t)
{
	return t;
}

TEST(Tree, CopyTree)
{
	ASSERT_TRUE(is_copy_assignable<TreeNode<int>>::value);
	ASSERT_TRUE(is_copy_assignable<TreeNode<long>>::value);
	ASSERT_TRUE(is_copy_assignable<TreeNode<double>>::value);
	ASSERT_TRUE(is_copy_assignable<TreeNode<float>>::value);

	ASSERT_TRUE(is_copy_constructible<TreeNode<int>>::value);
	ASSERT_TRUE(is_copy_constructible<TreeNode<long>>::value);
	ASSERT_TRUE(is_copy_constructible<TreeNode<double>>::value);
	ASSERT_TRUE(is_copy_constructible<TreeNode<float>>::value);

	TreeNode<int> a(1);
	TreeNode<int> b = a; // copy assignment
	ASSERT_EQ(a.data, b.data);
	ASSERT_NE(&a, &b);
	b.data = 2;
	ASSERT_EQ(a.data, 1);
	ASSERT_EQ(b.data, 2);
	b = a; // copy constructor
	ASSERT_EQ(a.data, b.data);
	ASSERT_NE(&a, &b);


}

TEST(Tree, MoveTree)
{
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
	ASSERT_EQ(a.data, 1);
	t.data = 2;
	TreeNode<int> b;
	b = call_move_assignment(t);
	ASSERT_EQ(b.data, 2);
	ASSERT_EQ(a.data, 1);

}
