#include "pch.h"

int RecursionWithNoStaticVariable(int n)
{	
	if (n > 0)
	{
		return RecursionWithNoStaticVariable(n - 1) + n;
	}

	return 0;
}

int RecursionWithStaticVariable(int n)
{
	static int val = 0;

	if (n > 0)
	{
		val++;
		return RecursionWithStaticVariable(n - 1) + val;
	}

	return 0;
}

int globalVal = 0;

int RecursionWithGlobalVariable(int n)
{

	if (n > 0)
	{
		globalVal++;
		return RecursionWithGlobalVariable(n - 1) + globalVal;
	}
	return 0;
}

TEST(RecursionTest, RecursionWithoutAndStaticOrGlobalVariables) {
	int result = RecursionWithNoStaticVariable(5);

	EXPECT_EQ(result, 15);
}

TEST(RecursionTest, RecursionWithStaticVariable) {
	int result = RecursionWithStaticVariable(5);

	EXPECT_EQ(result, 25);
}

TEST(RecursionTest, RecursionWithGlobalVariable) {
	int result = RecursionWithGlobalVariable(5);	

	EXPECT_EQ(result, 25);
}