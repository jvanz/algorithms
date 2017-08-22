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

TEST(LinkedList, MergeList)
{
	Node* list = InsertTail(nullptr, 2);
	InsertTail(list, 4);
	InsertTail(list, 7);
	Node* list2 = InsertTail(nullptr, 3);
	InsertTail(list2, 10);
	InsertTail(list2, 15);
	Node* merge = MergeLists(list, list2);
	ASSERT_NE(nullptr, merge) << "Node cannot be null";
	ASSERT_EQ(2, merge->data) << "Invalid value";
	merge = merge->next;
	ASSERT_EQ(3, merge->data) << "Invalid value";
	merge = merge->next;
	ASSERT_EQ(4, merge->data) << "Invalid value";
	merge = merge->next;
	ASSERT_EQ(7, merge->data) << "Invalid value";
	merge = merge->next;
	ASSERT_EQ(10, merge->data) << "Invalid value";
	merge = merge->next;
	ASSERT_EQ(15, merge->data) << "Invalid value";
	merge = merge->next;
	ASSERT_EQ(nullptr, merge) << "Node should be null";
}

TEST(LinkedList, MergeListWithNullPointer)
{
	Node* list = InsertTail(nullptr, 2);
	InsertTail(list, 4);
	InsertTail(list, 7);
	Node* list2 = nullptr;
	Node* merge = MergeLists(list, list2);
	ASSERT_NE(nullptr, merge) << "Node cannot be null";
	ASSERT_EQ(2, merge->data) << "Invalid value";
	merge = merge->next;
	ASSERT_EQ(4, merge->data) << "Invalid value";
	merge = merge->next;
	ASSERT_EQ(7, merge->data) << "Invalid value";
	merge = merge->next;
	ASSERT_EQ(nullptr, merge) << "Node should be null";
}

TEST(LinkedList, MergeListWithTwoNullPointer)
{
	ASSERT_EQ(nullptr, MergeLists(nullptr, nullptr));
}

TEST(LinkedList, GetNodeFromTail)
{
	Node* list = InsertTail(nullptr, 1);
	InsertTail(list, 2);
	InsertTail(list, 3);
	InsertTail(list, 4);
	InsertTail(list, 5);

	ASSERT_EQ(5, GetNode(list, 0));
	ASSERT_EQ(4, GetNode(list, 1));
	ASSERT_EQ(3, GetNode(list, 2));
	ASSERT_EQ(2, GetNode(list, 3));
	ASSERT_EQ(1, GetNode(list, 4));
}

TEST(LinkedList, RemoveDuplicateNode)
{
	ASSERT_EQ(nullptr, RemoveDuplicates(nullptr));

	Node* list = InsertTail(nullptr, 1);
	InsertTail(list, 1);
	InsertTail(list, 2);
	list = RemoveDuplicates(list);

	ASSERT_EQ(1, list->data) << "Invalid value";
	list = list->next;
	ASSERT_EQ(2, list->data) << "Invalid value";
	list = list->next;
	ASSERT_EQ(nullptr, list) << "Invalid value";

	list = InsertTail(nullptr, 1);
	InsertTail(list, 2);
	InsertTail(list, 3);
	InsertTail(list, 3);
	InsertTail(list, 4);
	list = RemoveDuplicates(list);

	ASSERT_EQ(1, list->data) << "Invalid value";
	list = list->next;
	ASSERT_EQ(2, list->data) << "Invalid value";
	list = list->next;
	ASSERT_EQ(3, list->data) << "Invalid value";
	list = list->next;
	ASSERT_EQ(4, list->data) << "Invalid value";
	list = list->next;
	ASSERT_EQ(nullptr, list) << "Invalid value";

	list = InsertTail(nullptr, 1);
	InsertTail(list, 2);
	InsertTail(list, 3);
	InsertTail(list, 4);
	InsertTail(list, 4);
	list = RemoveDuplicates(list);

	ASSERT_EQ(1, list->data) << "Invalid value";
	list = list->next;
	ASSERT_EQ(2, list->data) << "Invalid value";
	list = list->next;
	ASSERT_EQ(3, list->data) << "Invalid value";
	list = list->next;
	ASSERT_EQ(4, list->data) << "Invalid value";
	list = list->next;
	ASSERT_EQ(nullptr, list) << "Invalid value";
}

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
	ASSERT_EQ(list, nullptr) << "The list should not have more nodes";
}

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

TEST(LinkedList, DeleteNode)
{
	Node* list = InsertTail(nullptr, 1);
	InsertTail(list, 2);
	InsertTail(list, 3);
	InsertTail(list, 4);
	InsertTail(list, 5);
	InsertTail(list, 6);
	list = Delete(list, 5);
	list = Delete(list, 0);
	for (auto i = 2; i <= 5; i++){
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
