#include <gtest/gtest.h>

#include "node.h"

namespace {

TEST(LinkedList, InsertTail)
{
	Node* list = InsertTail(nullptr, 1);
	InsertTail(list, 2);
	InsertTail(list, 3);
	InsertTail(list, 4);
	for (auto i = 1; i <= 4; i++){
		ASSERT_NE(list, nullptr) << "Missing list nodes";
		ASSERT_EQ(list->data, i) << "Invalid node value";
		list = list->next;
	}
	ASSERT_EQ(list, nullptr) << "The list should not have more nodes";
}

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
