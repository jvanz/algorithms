#include <gtest/gtest.h>

#include "tree.hh"

using namespace jvanz::tree;

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
}
