#include <gtest/gtest.h>

#include "node.h"

namespace {

TEST(LinkedList, InsertPosition)
{
	Node* list = Insert(nullptr, 1, 0);
	Insert(list, 2, 1);
	Insert(list, 3, 2);
	Insert(list, 4, 3);
	Insert(list, 5, 4);
	list = Insert(list, 6, 0);
	ASSERT_EQ(list->data, 6);
	list = list->next;
	for (auto i = 1; i <= 5; i++){
		ASSERT_NE(list, nullptr) << "Missing list nodes";
		ASSERT_EQ(list->data, i) << "Invalid node value";
		list = list->next;
	}
	std::cout << list->data << std::endl;
	ASSERT_EQ(list, nullptr) << "The list should not have more nodes";
}

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
