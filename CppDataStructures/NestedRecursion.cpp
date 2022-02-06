#include "pch.h"

int NestedFunction(int number) {
	if (number > 100) {
		return number - 10;
	}
	else {
		return NestedFunction(NestedFunction(number + 11));
	}
}

TEST(NestedRecursion, Example) {
	
	int result = NestedFunction(95);

	EXPECT_EQ(result, 91);
}