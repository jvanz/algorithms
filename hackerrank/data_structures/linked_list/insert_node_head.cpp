#include <gtest/gtest.h>

#include "node.h"

namespace {

TEST(LinkedList, InsertHead)
{
	Node* head = nullptr;
	head = InsertHead(head, 1);
	head = InsertHead(head, 2);
	head = InsertHead(head, 3);
	for (auto i = 3; i >= 1; i--){
		ASSERT_NE(head, nullptr);
		ASSERT_EQ(head->data, i);
		head = head->next;
	}
	ASSERT_EQ(head, nullptr);
}

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
