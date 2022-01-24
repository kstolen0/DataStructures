#include "pch.h"
#include <stack>

using namespace std;


void TreeRecursionStartExample(stack<int>& myStack, int n) {

	if (n < 3) {
		myStack.push(n);
		TreeRecursionStartExample(myStack, n+1);
		TreeRecursionStartExample(myStack, n+1);
	}
}

void TreeRecursionMidExample(stack<int>& myStack, int n) {
	
	if (n < 3) {
		TreeRecursionMidExample(myStack, n + 1);
		myStack.push(n);
		TreeRecursionMidExample(myStack, n + 1);
	}
}

void TreeRecursionEndExample(stack<int>& myStack, int n) {

	if (n < 3) {
		TreeRecursionEndExample(myStack, n + 1);
		TreeRecursionEndExample(myStack, n + 1);
		myStack.push(n);
	}
}

TEST(RecursionTests, TreeRecursionEnd) {
	stack<int> testStack;
	TreeRecursionEndExample(testStack, 0);

	EXPECT_EQ(testStack.top(), 0);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 1);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 2);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 2);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 1);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 2);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 2);
}

TEST(RecursionTests, TreeRecursionMid) {
	stack<int> testStack;
	TreeRecursionMidExample(testStack, 0);

	EXPECT_EQ(testStack.top(), 2);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 1);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 2);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 0);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 2);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 1);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 2);
}

TEST(RecursionTests, TreeRecursionStart) {
	stack<int> testStack;
	TreeRecursionStartExample(testStack, 0);

	EXPECT_EQ(testStack.top(), 2);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 2);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 1);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 2);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 2);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 1);
	testStack.pop();
	EXPECT_EQ(testStack.top(), 0);
}