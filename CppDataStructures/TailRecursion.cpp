#include "pch.h"
#include <stack>

using namespace std;

void TailRecursionExample(stack<int>& myStack, int n) {
	
	if (n < 3)
	{
		myStack.push(n);
		// last operation in function is recursive call
		TailRecursionExample(myStack, n+1);
	}
}

void WhileLoopExampleReplicatingTailRecursion(stack<int>& myStack, int n) {

	while (n < 3) {
		myStack.push(n);
		n++;
	}
}

TEST(RecursionTests, TailRecursion) {
	stack<int> testStack;
	TailRecursionExample(testStack, 0);

	EXPECT_EQ(testStack.top(), 2);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 1);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 0);
}

TEST(RecursionTests, WhileLoopTailRecursion) {
	stack<int> testStack;
	WhileLoopExampleReplicatingTailRecursion(testStack, 0);

	EXPECT_EQ(testStack.top(), 2);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 1);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 0);
}