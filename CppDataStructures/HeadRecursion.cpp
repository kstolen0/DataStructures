#include "pch.h"
#include <stack>

using namespace std;

void HeadRecursionExample(stack<int>& myStack, int n) {

	if (n < 3)
	{
		// first operation is the recursive call
		HeadRecursionExample(myStack, n + 1);
		myStack.push(n);
	}
}

void WhileLoopExampleReplicatingHeadRecursion(stack<int>& myStack, int n) {
	
	int i = 3;

	while (i > n) {
		i--;
		myStack.push(i);
	}
}

TEST(RecursionTests, HeadRecursion) {
	stack<int> testStack;
	HeadRecursionExample(testStack, 0);

	EXPECT_EQ(testStack.top(), 0);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 1);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 2);	
}

TEST(RecursionTests, WhileLoopHeadRecursion) {
	stack<int> testStack;
	WhileLoopExampleReplicatingHeadRecursion(testStack, 0);

	EXPECT_EQ(testStack.top(), 0);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 1);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 2);
}