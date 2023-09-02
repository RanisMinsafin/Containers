#include "tests.h"

// Test stack default constructor
TEST(StackTest, DefaultConstructor) {
  s21::stack<int> stack;
  EXPECT_TRUE(stack.empty());
  EXPECT_EQ(stack.size(), 0);
}

// Test stack initializer list constructor
TEST(StackTest, InitializerListConstructor) {
  s21::stack<int> stack{1, 2, 3};
  EXPECT_FALSE(stack.empty());
  EXPECT_EQ(stack.size(), 3);
  EXPECT_EQ(stack.top(), 3);
}

// Test stack push and top methods
TEST(StackTest, PushAndTop) {
  s21::stack<int> stack;
  stack.push(1);
  EXPECT_FALSE(stack.empty());
  EXPECT_EQ(stack.size(), 1);
  EXPECT_EQ(stack.top(), 1);

  stack.push(2);
  EXPECT_EQ(stack.size(), 2);
  EXPECT_EQ(stack.top(), 2);

  stack.push(3);
  EXPECT_EQ(stack.size(), 3);
  EXPECT_EQ(stack.top(), 3);
}

// Test stack pop method
TEST(StackTest, Pop) {
  s21::stack<int> stack{1, 2, 3};
  EXPECT_EQ(stack.size(), 3);

  stack.pop();
  EXPECT_EQ(stack.size(), 2);
  EXPECT_EQ(stack.top(), 2);

  stack.pop();
  EXPECT_EQ(stack.size(), 1);
  EXPECT_EQ(stack.top(), 1);

  stack.pop();
  EXPECT_TRUE(stack.empty());
}

// Test stack swap method
TEST(StackTest, Swap) {
  s21::stack<int> stack1{1, 2, 3};
  s21::stack<int> stack2{4, 5};

  stack1.swap(stack2);

  EXPECT_EQ(stack1.size(), 2);
  EXPECT_EQ(stack1.top(), 5);

  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 3);
}

// Test stack empty method
TEST(StackTest, Empty) {
  s21::stack<int> stack;
  EXPECT_TRUE(stack.empty());

  stack.push(1);
  EXPECT_FALSE(stack.empty());

  stack.pop();
  EXPECT_TRUE(stack.empty());
}

// Test stack size method
TEST(StackTest, Size) {
  s21::stack<int> stack;
  EXPECT_EQ(stack.size(), 0);

  stack.push(1);
  EXPECT_EQ(stack.size(), 1);

  stack.push(2);
  EXPECT_EQ(stack.size(), 2);

  stack.pop();
  EXPECT_EQ(stack.size(), 1);

  stack.pop();
  EXPECT_EQ(stack.size(), 0);
}

// Test stack destructor
TEST(StackTest, Destructor) {
  s21::stack<int>* stack = new s21::stack<int>{1, 2, 3};
  delete stack;
}

// Test stack move constructor
TEST(StackTest, MoveConstructor) {
  s21::stack<int> stack1{1, 2, 3};
  s21::stack<int> stack2 = std::move(stack1);

  EXPECT_EQ(stack1.size(), 0);
  EXPECT_TRUE(stack1.empty());

  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 3);
}

// Test stack with char type
TEST(StackTest, CharType) {
  s21::stack<char> stack;
  stack.push('a');
  stack.push('b');
  stack.push('c');

  EXPECT_EQ(stack.top(), 'c');
  stack.pop();
  EXPECT_EQ(stack.top(), 'b');
  stack.pop();
  EXPECT_EQ(stack.top(), 'a');
  stack.pop();
  EXPECT_TRUE(stack.empty());
}

// Test stack with double type
TEST(StackTest, DoubleType) {
  s21::stack<double> stack;
  stack.push(1.1);
  stack.push(2.2);
  stack.push(3.3);

  EXPECT_EQ(stack.top(), 3.3);
  stack.pop();
  EXPECT_EQ(stack.top(), 2.2);
  stack.pop();
  EXPECT_EQ(stack.top(), 1.1);
  stack.pop();
  EXPECT_TRUE(stack.empty());
}

TEST(StackTest, InsertManyFront) {
  s21::stack<int> my_stack;

  // Insert multiple elements at the top of the stack
  my_stack.insert_many_front(1, 2, 3);

  // Verify the contents of the stack after insertion
  ASSERT_EQ(my_stack.size(), 3);
  EXPECT_EQ(my_stack.top(), 1);

  my_stack.push(4);
  // After pushing 4, the stack should be: 4 -> 3 -> 2 -> 1
  EXPECT_EQ(my_stack.top(), 4);

  // Insert more elements at the top of the stack
  my_stack.insert_many_front(5, 6);

  // Verify the contents of the stack after insertion
  ASSERT_EQ(my_stack.size(), 6);
  EXPECT_EQ(my_stack.top(), 5);
}
