#include <vector>

#include <gtest/gtest.h>

#include "array.hh"

using namespace std;
using namespace jvanz::array;

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
