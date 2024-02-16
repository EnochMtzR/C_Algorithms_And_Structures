#include <gtest/gtest.h>
#include <stdbool.h>

extern "C" {
#include "algorithms.h"
}

void EXPECT_ARRAY_EQ(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(a[i], b[i]);
    }
}

TEST(LinearSearch, Algorithms) {
	int array[] = { 1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420 };

	EXPECT_EQ(linearSearch(array, 11, 69), true);
	EXPECT_EQ(linearSearch(array, 11, 1336), false);
	EXPECT_EQ(linearSearch(array, 11, 69420), true);
	EXPECT_EQ(linearSearch(array, 11, 69421), false);
	EXPECT_EQ(linearSearch(array, 11, 1), true);
	EXPECT_EQ(linearSearch(array, 11, 0), false);
}

TEST(BinarySearch, Algorithms) {
	int array[] = { 1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420 };

	EXPECT_EQ(binarySearch(array, 11, 69), true);
	EXPECT_EQ(binarySearch(array, 11, 1336), false);
	EXPECT_EQ(binarySearch(array, 11, 69420), true);
	EXPECT_EQ(binarySearch(array, 11, 69421), false);
	EXPECT_EQ(binarySearch(array, 11, 1), true);
	EXPECT_EQ(binarySearch(array, 11, 0), false);
}


