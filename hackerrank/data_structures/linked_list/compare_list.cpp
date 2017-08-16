#include <gtest/gtest.h>

#include "node.h"

namespace {

TEST(LinkedList, CompareList)
{
	Node* list = Insert(nullptr, 1, 0);
	Node* list2 = Insert(nullptr, 1, 0);
	Node* list3 = Insert(nullptr, 1, 0);
	Node* list4 = Insert(nullptr, 1, 0);
	for (int i = 1; i < 11; i++)
		list = Insert(list, i+1, i);
	for (int i = 1; i < 11; i++)
		list2 = Insert(list2, i+1, i);
	for (int i = 1; i < 11; i++)
		list3 = Insert(list3, i+2, i);
	ASSERT_TRUE(CompareLists(list, list2));
	ASSERT_FALSE(CompareLists(list, list3));
	ASSERT_FALSE(CompareLists(list2, list3));
	ASSERT_FALSE(CompareLists(list, list4));
	ASSERT_FALSE(CompareLists(list, nullptr));
}

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
