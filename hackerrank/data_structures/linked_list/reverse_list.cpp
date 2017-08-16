#include <gtest/gtest.h>

#include "node.h"

namespace {

TEST(LinkedList, ReverseList)
{
	Node* list = Insert(nullptr, 1, 0);
	for (int i = 1; i <= 9; i++)
		list = Insert(list, i+1, i);
	int i = 0;
	Node* bck = list;
	while (bck){
		ASSERT_EQ(i+1, bck->data);
		i++;
		bck = bck->next;
	}
	list = Reverse(list);
	i = 10;
	while (list){
		ASSERT_EQ(list->data, i--);
		list = list->next;
	}
}

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
