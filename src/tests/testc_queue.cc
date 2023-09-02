#include "tests.h"

// Tests for the queue class

// Default constructor
TEST(QueueTest, DefaultConstructor) {
  s21::queue<char> q1;
  EXPECT_TRUE(q1.empty());
  EXPECT_EQ(q1.size(), 0);

  s21::queue<int> q2;
  EXPECT_TRUE(q2.empty());
  EXPECT_EQ(q2.size(), 0);

  s21::queue<double> q3;
  EXPECT_TRUE(q3.empty());
  EXPECT_EQ(q3.size(), 0);
}

// Constructor with initializer list
TEST(QueueTest, ConstructorWithInitializerList) {
  s21::queue<char> q1{'a', 'b', 'c'};
  EXPECT_FALSE(q1.empty());
  EXPECT_EQ(q1.size(), 3);
  EXPECT_EQ(q1.front(), 'a');
  EXPECT_EQ(q1.back(), 'c');

  s21::queue<int> q2{1, 2, 3};
  EXPECT_FALSE(q2.empty());
  EXPECT_EQ(q2.size(), 3);
  EXPECT_EQ(q2.front(), 1);
  EXPECT_EQ(q2.back(), 3);

  s21::queue<double> q3{1.1, 2.2, 3.3};
  EXPECT_FALSE(q3.empty());
  EXPECT_EQ(q3.size(), 3);
  EXPECT_DOUBLE_EQ(q3.front(), 1.1);
  EXPECT_DOUBLE_EQ(q3.back(), 3.3);
}

// Copy constructor
TEST(QueueTest, CopyConstructor) {
  s21::queue<char> q1{'a', 'b', 'c'};
  s21::queue<char> q2(q1);
  EXPECT_EQ(q1.size(), q2.size());
  EXPECT_EQ(q1.front(), q2.front());
  EXPECT_EQ(q1.back(), q2.back());

  s21::queue<int> q3{1, 2, 3};
  s21::queue<int> q4(q3);
  EXPECT_EQ(q3.size(), q4.size());
  EXPECT_EQ(q3.front(), q4.front());
  EXPECT_EQ(q3.back(), q4.back());

  s21::queue<double> q5{1.1, 2.2, 3.3};
  s21::queue<double> q6(q5);
  EXPECT_EQ(q5.size(), q6.size());
  EXPECT_DOUBLE_EQ(q5.front(), q6.front());
  EXPECT_DOUBLE_EQ(q5.back(), q6.back());
}

// Move constructor
TEST(QueueTest, MoveConstructor) {
  s21::queue<char> q1{'a', 'b', 'c'};
  s21::queue<char> q2(std::move(q1));
  EXPECT_TRUE(q1.empty());
  EXPECT_EQ(q1.size(), 0);
  EXPECT_FALSE(q2.empty());
  EXPECT_EQ(q2.size(), 3);
  EXPECT_EQ(q2.front(), 'a');
  EXPECT_EQ(q2.back(), 'c');

  s21::queue<int> q3{1, 2, 3};
  s21::queue<int> q4(std::move(q3));
  EXPECT_TRUE(q3.empty());
  EXPECT_EQ(q3.size(), 0);
  EXPECT_FALSE(q4.empty());
  EXPECT_EQ(q4.size(), 3);
  EXPECT_EQ(q4.front(), 1);
  EXPECT_EQ(q4.back(), 3);

  s21::queue<double> q5{1.1, 2.2, 3.3};
  s21::queue<double> q6(std::move(q5));
  EXPECT_TRUE(q5.empty());
  EXPECT_EQ(q5.size(), 0);
  EXPECT_FALSE(q6.empty());
  EXPECT_EQ(q6.size(), 3);
  EXPECT_DOUBLE_EQ(q6.front(), 1.1);
  EXPECT_DOUBLE_EQ(q6.back(), 3.3);
}

// Destructor
TEST(QueueTest, Destructor) {
  {
    s21::queue<char> q{'a', 'b', 'c'};
    // Do some operations
    EXPECT_EQ(q.size(), 3);
  }  // Destructor called here, make sure no memory leaks
}

// Assignment operator (move assignment)
TEST(QueueTest, MoveAssignmentOperator) {
  s21::queue<char> q1{'a', 'b', 'c'};
  s21::queue<char> q2;
  q2 = std::move(q1);
  EXPECT_TRUE(q1.empty());
  EXPECT_EQ(q1.size(), 0);
  EXPECT_FALSE(q2.empty());
  EXPECT_EQ(q2.size(), 3);
  EXPECT_EQ(q2.front(), 'a');
  EXPECT_EQ(q2.back(), 'c');

  s21::queue<int> q3{1, 2, 3};
  s21::queue<int> q4;
  q4 = std::move(q3);
  EXPECT_TRUE(q3.empty());
  EXPECT_EQ(q3.size(), 0);
  EXPECT_FALSE(q4.empty());
  EXPECT_EQ(q4.size(), 3);
  EXPECT_EQ(q4.front(), 1);
  EXPECT_EQ(q4.back(), 3);

  s21::queue<double> q5{1.1, 2.2, 3.3};
  s21::queue<double> q6;
  q6 = std::move(q5);
  EXPECT_TRUE(q5.empty());
  EXPECT_EQ(q5.size(), 0);
  EXPECT_FALSE(q6.empty());
  EXPECT_EQ(q6.size(), 3);
  EXPECT_DOUBLE_EQ(q6.front(), 1.1);
  EXPECT_DOUBLE_EQ(q6.back(), 3.3);
}

// Front method
TEST(QueueTest, Front) {
  s21::queue<char> q1{'a', 'b', 'c'};
  EXPECT_EQ(q1.front(), 'a');

  s21::queue<int> q2{1, 2, 3};
  EXPECT_EQ(q2.front(), 1);

  s21::queue<double> q3{1.1, 2.2, 3.3};
  EXPECT_DOUBLE_EQ(q3.front(), 1.1);
}

// Back method
TEST(QueueTest, Back) {
  s21::queue<char> q1{'a', 'b', 'c'};
  EXPECT_EQ(q1.back(), 'c');

  s21::queue<int> q2{1, 2, 3};
  EXPECT_EQ(q2.back(), 3);

  s21::queue<double> q3{1.1, 2.2, 3.3};
  EXPECT_DOUBLE_EQ(q3.back(), 3.3);
}

// Empty method
TEST(QueueTest, Empty) {
  s21::queue<char> q1;
  EXPECT_TRUE(q1.empty());
  q1.push('a');
  EXPECT_FALSE(q1.empty());

  s21::queue<int> q2;
  EXPECT_TRUE(q2.empty());
  q2.push(42);
  EXPECT_FALSE(q2.empty());

  s21::queue<double> q3;
  EXPECT_TRUE(q3.empty());
  q3.push(3.14);
  EXPECT_FALSE(q3.empty());
}

// Size method
TEST(QueueTest, Size) {
  s21::queue<char> q1{'a', 'b', 'c'};
  EXPECT_EQ(q1.size(), 3);
  q1.pop();
  EXPECT_EQ(q1.size(), 2);

  s21::queue<int> q2{1, 2, 3};
  EXPECT_EQ(q2.size(), 3);
  q2.pop();
  EXPECT_EQ(q2.size(), 2);

  s21::queue<double> q3{1.1, 2.2, 3.3};
  EXPECT_EQ(q3.size(), 3);
  q3.pop();
  EXPECT_EQ(q3.size(), 2);
}

// Push method
TEST(QueueTest, Push) {
  s21::queue<char> q1;
  q1.push('a');
  EXPECT_FALSE(q1.empty());
  EXPECT_EQ(q1.size(), 1);
  EXPECT_EQ(q1.front(), 'a');
  EXPECT_EQ(q1.back(), 'a');
  q1.push('b');
  EXPECT_EQ(q1.size(), 2);
  EXPECT_EQ(q1.front(), 'a');
  EXPECT_EQ(q1.back(), 'b');

  s21::queue<int> q2;
  q2.push(42);
  EXPECT_FALSE(q2.empty());
  EXPECT_EQ(q2.size(), 1);
  EXPECT_EQ(q2.front(), 42);
  EXPECT_EQ(q2.back(), 42);
  q2.push(13);
  EXPECT_EQ(q2.size(), 2);
  EXPECT_EQ(q2.front(), 42);
  EXPECT_EQ(q2.back(), 13);

  s21::queue<double> q3;
  q3.push(3.14);
  EXPECT_FALSE(q3.empty());
  EXPECT_EQ(q3.size(), 1);
  EXPECT_DOUBLE_EQ(q3.front(), 3.14);
  EXPECT_DOUBLE_EQ(q3.back(), 3.14);
  q3.push(2.71);
  EXPECT_EQ(q3.size(), 2);
  EXPECT_DOUBLE_EQ(q3.front(), 3.14);
  EXPECT_DOUBLE_EQ(q3.back(), 2.71);
}

// Pop method
TEST(QueueTest, Pop) {
  s21::queue<char> q1{'a', 'b', 'c'};
  q1.pop();
  EXPECT_EQ(q1.size(), 2);
  EXPECT_EQ(q1.front(), 'b');
  q1.pop();
  EXPECT_EQ(q1.size(), 1);
  EXPECT_EQ(q1.front(), 'c');
  q1.pop();
  EXPECT_TRUE(q1.empty());

  s21::queue<int> q2{1, 2, 3};
  q2.pop();
  EXPECT_EQ(q2.size(), 2);
  EXPECT_EQ(q2.front(), 2);
  q2.pop();
  EXPECT_EQ(q2.size(), 1);
  EXPECT_EQ(q2.front(), 3);
  q2.pop();
  EXPECT_TRUE(q2.empty());

  s21::queue<double> q3{1.1, 2.2, 3.3};
  q3.pop();
  EXPECT_EQ(q3.size(), 2);
  EXPECT_DOUBLE_EQ(q3.front(), 2.2);
  q3.pop();
  EXPECT_EQ(q3.size(), 1);
  EXPECT_DOUBLE_EQ(q3.front(), 3.3);
  q3.pop();
  EXPECT_TRUE(q3.empty());
}

// Swap method
TEST(QueueTest, Swap) {
  s21::queue<char> q1{'a', 'b', 'c'};
  s21::queue<char> q2{'x', 'y', 'z'};
  q1.swap(q2);
  EXPECT_EQ(q1.size(), 3);
  EXPECT_EQ(q1.front(), 'x');
  EXPECT_EQ(q1.back(), 'z');
  EXPECT_EQ(q2.size(), 3);
  EXPECT_EQ(q2.front(), 'a');
  EXPECT_EQ(q2.back(), 'c');

  s21::queue<int> q3{1, 2, 3};
  s21::queue<int> q4{4, 5, 6};
  q3.swap(q4);
  EXPECT_EQ(q3.size(), 3);
  EXPECT_EQ(q3.front(), 4);
  EXPECT_EQ(q3.back(), 6);
  EXPECT_EQ(q4.size(), 3);
  EXPECT_EQ(q4.front(), 1);
  EXPECT_EQ(q4.back(), 3);

  s21::queue<double> q5{1.1, 2.2, 3.3};
  s21::queue<double> q6{4.4, 5.5, 6.6};
  q5.swap(q6);
  EXPECT_EQ(q5.size(), 3);
  EXPECT_DOUBLE_EQ(q5.front(), 4.4);
  EXPECT_DOUBLE_EQ(q5.back(), 6.6);
  EXPECT_EQ(q6.size(), 3);
  EXPECT_DOUBLE_EQ(q6.front(), 1.1);
  EXPECT_DOUBLE_EQ(q6.back(), 3.3);
}

TEST(QueueTest, InsertManyBack) {
  s21::queue<int> my_queue;

  // Insert multiple elements at the back of the queue
  my_queue.insert_many_back(1, 2, 3);

  // Verify the contents of the queue after insertion
  ASSERT_EQ(my_queue.size(), 3);
  EXPECT_EQ(my_queue.front(), 1);

  my_queue.push(4);
  // After pushing 4, the queue should be: 1 -> 2 -> 3 -> 4

  // Insert more elements at the back of the queue
  my_queue.insert_many_back(5, 6);

  // Verify the contents of the queue after insertion
  ASSERT_EQ(my_queue.size(), 6);
  EXPECT_EQ(my_queue.front(), 1);
  EXPECT_EQ(my_queue.back(), 6);
}
