#include <vector>

#include <gtest/gtest.h>

#include <array/array.hh>

using namespace std;

TEST(Array, LeftRotation) {
	vector<int> v = {1,2,3,4,5,6,7,8,9};
	vector<int> v2 = {3,4,5,6,7,8,9,1,2};
	auto rv = jvanz::array::rotate_left<int>(v, 2);
	EXPECT_EQ(rv,v2);
}

TEST(Array, LeftRotationException) {
	vector<int> v = {1,2,3,4,5,6,7,8,9};
	ASSERT_ANY_THROW(jvanz::array::rotate_left<int>(v, 0));
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
