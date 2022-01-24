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

TEST(RecursionTests, RecursionWithoutAndStaticOrGlobalVariables) {
	int result = RecursionWithNoStaticVariable(5);

	EXPECT_EQ(result, 15);
}

TEST(RecursionTests, RecursionWithStaticVariable) {
	int result = RecursionWithStaticVariable(5);

	EXPECT_EQ(result, 25);
}

TEST(RecursionTests, RecursionWithGlobalVariable) {
	int result = RecursionWithGlobalVariable(5);	

	EXPECT_EQ(result, 25);
}