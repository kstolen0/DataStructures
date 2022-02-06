#include "pch.h"

// declare recursive functions prior to defining them
// so we don't have a build failure
int DoFunctionOne(int number);
int DoFunctionTwo(int number);

int DoFunctionOne(int number) {
	if (number < 0) {
		return DoFunctionTwo(number);
	}

	return number;
}

int DoFunctionTwo(int number) {
	return DoFunctionOne(number + 1);
}

TEST(IndirectRecursion, FunctionACallsFunctionB) {	
	int result = DoFunctionOne(-1);

	EXPECT_EQ(result, 0);
}