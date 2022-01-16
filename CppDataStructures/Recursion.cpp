#include "pch.h"
#include <stack>

using namespace std;

void AddBeforeRecursion(stack<int>& testStack, int n)
{
	if (n > 0)
	{
		testStack.push(n);
		AddBeforeRecursion(testStack, n - 1);
	}
}

void AddAfterRecursion(stack<int>& testStack, int n)
{
	if (n > 0)
	{
		AddAfterRecursion(testStack, n - 1);
		testStack.push(n);
	}
}

TEST(RecursionTests, TestOperationBeforeRecusiveCall) {
	stack<int> testStack;

	AddBeforeRecursion(testStack, 3);

	EXPECT_EQ(testStack.top(), 1);
}

TEST(RecursionTests, TestOperationAfterRecursiveCall) {
	stack<int> testStack;

	AddAfterRecursion(testStack, 3);

	EXPECT_EQ(testStack.top(), 3);
}