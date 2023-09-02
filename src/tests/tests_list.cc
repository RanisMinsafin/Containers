#include "tests.h"

// Default constructor test
TEST(ListTest, DefaultConstructor) {
  s21::list<int> myList;
  EXPECT_EQ(myList.size(), 0);
}

TEST(ListTest, DefaultConstructor_Char) {
  s21::list<char> myList;
  EXPECT_EQ(myList.size(), 0);
}

TEST(ListTest, DefaultConstructor_Double) {
  s21::list<double> myList;
  EXPECT_EQ(myList.size(), 0);
}

// Parameterized constructor test
TEST(ListTest, ParameterizedConstructor) {
  s21::list<int> myList(5);
  EXPECT_EQ(myList.size(), 5);
}

TEST(ListTest, ParameterizedConstructor_Char) {
  s21::list<char> myList(5);
  EXPECT_EQ(myList.size(), 5);
}

TEST(ListTest, ParameterizedConstructor_Double) {
  s21::list<double> myList(5);
  EXPECT_EQ(myList.size(), 5);
}

// Initializer list constructor test
TEST(ListTest, InitializerListConstructor) {
  s21::list<int> myList = {1, 2, 3, 4, 5};
  EXPECT_EQ(myList.size(), 5);
}

TEST(ListTest, InitializerListConstructor_Char) {
  s21::list<char> myList = {'a', 'b', 'c'};
  EXPECT_EQ(myList.size(), 3);
}

TEST(ListTest, InitializerListConstructor_Double) {
  s21::list<double> myList = {1.1, 2.2, 3.3};
  EXPECT_EQ(myList.size(), 3);
}

// Copy constructor test
TEST(ListTest, CopyConstructor) {
  s21::list<int> myList = {1, 2, 3};
  s21::list<int> newList(myList);
  EXPECT_EQ(newList.front(), 1);
  EXPECT_EQ(newList.back(), 3);
  EXPECT_EQ(newList.size(), myList.size());
}

TEST(ListTest, CopyConstructor_Char) {
  s21::list<char> myList = {'a', 'b', 'c'};
  s21::list<char> newList(myList);
  EXPECT_EQ(newList.front(), 'a');
  EXPECT_EQ(newList.back(), 'c');
  EXPECT_EQ(newList.size(), myList.size());
}

TEST(ListTest, CopyConstructor_Double) {
  s21::list<double> myList = {1.1, 2.2, 3.3};
  s21::list<double> newList(myList);
  EXPECT_EQ(newList.front(), 1.1);
  EXPECT_EQ(newList.back(), 3.3);
  EXPECT_EQ(newList.size(), myList.size());
}

// Move constructor test
TEST(ListTest, MoveConstructor) {
  s21::list<int> myList = {1, 2, 3};
  s21::list<int> newList(std::move(myList));
  EXPECT_EQ(newList.front(), 1);
  EXPECT_EQ(newList.back(), 3);
  EXPECT_EQ(newList.size(), 3);
  EXPECT_EQ(myList.size(), 0);
}
// Destructor test
TEST(ListTest, Destructor) {
  s21::list<int>* myList = new s21::list<int>;
  delete myList;  // Ensure no memory leaks
  SUCCEED();
}

TEST(ListTest, Destructor_Char) {
  s21::list<char>* myList = new s21::list<char>;
  delete myList;  // Ensure no memory leaks
  SUCCEED();
}

TEST(ListTest, Destructor_Double) {
  s21::list<double>* myList = new s21::list<double>;
  delete myList;  // Ensure no memory leaks
  SUCCEED();
}

// Move assignment operator test
TEST(ListTest, MoveAssignmentOperator) {
  s21::list<int> myList = {1, 2, 3};
  s21::list<int> newList;
  newList = std::move(myList);
  EXPECT_EQ(newList.size(), 3);
  EXPECT_EQ(myList.size(), 0);
}

TEST(ListTest, MoveAssignmentOperator_Char) {
  s21::list<char> myList = {'a', 'b', 'c'};
  s21::list<char> newList;
  newList = std::move(myList);
  EXPECT_EQ(newList.size(), 3);
  EXPECT_EQ(myList.size(), 0);
}

TEST(ListTest, MoveAssignmentOperator_Double) {
  s21::list<double> myList = {1.1, 2.2, 3.3};
  s21::list<double> newList;
  newList = std::move(myList);
  EXPECT_EQ(newList.size(), 3);
  EXPECT_EQ(myList.size(), 0);
}

// Size test
TEST(ListTest, Size) {
  s21::list<int> myList = {1, 2, 3};
  EXPECT_EQ(myList.size(), 3);
}

TEST(ListTest, Size_Char) {
  s21::list<char> myList = {'a', 'b', 'c'};
  EXPECT_EQ(myList.size(), 3);
}

TEST(ListTest, Size_Double) {
  s21::list<double> myList = {1.1, 2.2, 3.3};
  EXPECT_EQ(myList.size(), 3);
}

// Clear test
TEST(ListTest, Clear) {
  s21::list<int> myList = {1, 2, 3};
  myList.clear();
  EXPECT_EQ(myList.size(), 0);
}

TEST(ListTest, Clear_Char) {
  s21::list<char> myList = {'a', 'b', 'c'};
  myList.clear();
  EXPECT_EQ(myList.size(), 0);
}

TEST(ListTest, Clear_Double) {
  s21::list<double> myList = {1.1, 2.2, 3.3};
  myList.clear();
  EXPECT_EQ(myList.size(), 0);
}

// Push back test
TEST(ListTest, PushBack) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  EXPECT_EQ(myList.size(), 2);
}

TEST(ListTest, PushBack_Char) {
  s21::list<char> myList;
  myList.push_back('a');
  myList.push_back('b');
  EXPECT_EQ(myList.size(), 2);
}

TEST(ListTest, PushBack_Double) {
  s21::list<double> myList;
  myList.push_back(1.1);
  myList.push_back(2.2);
  EXPECT_EQ(myList.size(), 2);
}

// Front test
TEST(ListTest, Front) {
  s21::list<int> myList = {1, 2, 3};
  EXPECT_EQ(myList.front(), 1);
}

TEST(ListTest, Front_Char) {
  s21::list<char> myList = {'a', 'b', 'c'};
  EXPECT_EQ(myList.front(), 'a');
}

TEST(ListTest, Front_Double) {
  s21::list<double> myList = {1.1, 2.2, 3.3};
  EXPECT_EQ(myList.front(), 1.1);
}

// Back test
TEST(ListTest, Back) {
  s21::list<int> myList = {1, 2, 3};
  EXPECT_EQ(myList.back(), 3);
}

TEST(ListTest, Back_Char) {
  s21::list<char> myList = {'a', 'b', 'c'};
  EXPECT_EQ(myList.back(), 'c');
}

TEST(ListTest, Back_Double) {
  s21::list<double> myList = {1.1, 2.2, 3.3};
  EXPECT_EQ(myList.back(), 3.3);
}

// Empty test
TEST(ListTest, Empty) {
  s21::list<int> myList;
  EXPECT_TRUE(myList.empty());

  myList.push_back(1);
  EXPECT_FALSE(myList.empty());
}

TEST(ListTest, Empty_Char) {
  s21::list<char> myList;
  EXPECT_TRUE(myList.empty());

  myList.push_back('a');
  EXPECT_FALSE(myList.empty());
}

TEST(ListTest, Empty_Double) {
  s21::list<double> myList;
  EXPECT_TRUE(myList.empty());

  myList.push_back(1.1);
  EXPECT_FALSE(myList.empty());
}

// Max Size test
TEST(ListTest, MaxSize) {
  s21::list<int> myList{1, 2, 3};
  EXPECT_EQ(myList.max_size(), 384307168202282325);
}

TEST(ListTest, MaxSize_Char) {
  s21::list<char> myList{'a', 'b', 'c'};
  EXPECT_EQ(myList.max_size(), 384307168202282325);
}

TEST(ListTest, MaxSize_Double) {
  s21::list<double> myList{1.1, 2.2, 3.3};
  EXPECT_EQ(myList.max_size(), 384307168202282325);
}

// Testing iterator begin()
TEST(ListTest, Begin) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  // Get iterator to the beginning of the list
  s21::list<int>::iterator it = myList.begin();

  // Check the value of the element pointed by the iterator
  EXPECT_EQ(*it, 1);
}

TEST(ListTest, Begin_Char) {
  s21::list<char> myList;
  myList.push_back('a');
  myList.push_back('b');
  myList.push_back('c');

  // Get iterator to the beginning of the list
  s21::list<char>::iterator it = myList.begin();

  // Check the value of the element pointed by the iterator
  EXPECT_EQ(*it, 'a');
}

TEST(ListTest, Begin_Double) {
  s21::list<double> myList;
  myList.push_back(1.1);
  myList.push_back(2.2);
  myList.push_back(3.3);

  // Get iterator to the beginning of the list
  s21::list<double>::iterator it = myList.begin();

  // Check the value of the element pointed by the iterator
  EXPECT_EQ(*it, 1.1);
}

// Testing iterator end()
TEST(ListTest, End) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  // Get iterator to the end of the list
  s21::list<int>::iterator it = myList.end();
  *it--;
  // Check that the end iterator does not point to any element
  EXPECT_EQ(*it, 3);
}

TEST(ListTest, End_Char) {
  s21::list<char> myList;
  myList.push_back('a');
  myList.push_back('b');
  myList.push_back('c');

  // Get iterator to the end of the list
  s21::list<char>::iterator it = myList.end();
  *it--;
  // Check that the end iterator does not point to any element
  EXPECT_EQ(*it, 'c');
}

TEST(ListTest, End_Double) {
  s21::list<double> myList;
  myList.push_back(1.1);
  myList.push_back(2.2);
  myList.push_back(3.3);

  // Get iterator to the end of the list
  s21::list<double>::iterator it = myList.end();
  *it--;
  // Check that the end iterator does not point to any element
  EXPECT_EQ(*it, 3.3);
}

// Testing prefix increment (++it)
TEST(ListTest, PreIncrement) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  s21::list<int>::iterator it = myList.begin();
  ++it;

  // Check the value of the element after increment
  EXPECT_EQ(*it, 2);
}

TEST(ListTest, PreIncrement_Char) {
  s21::list<char> myList;
  myList.push_back('a');
  myList.push_back('b');
  myList.push_back('c');

  s21::list<char>::iterator it = myList.begin();
  ++it;

  // Check the value of the element after increment
  EXPECT_EQ(*it, 'b');
}

TEST(ListTest, PreIncrement_Double) {
  s21::list<double> myList;
  myList.push_back(1.1);
  myList.push_back(2.2);
  myList.push_back(3.3);

  s21::list<double>::iterator it = myList.begin();
  ++it;

  // Check the value of the element after increment
  EXPECT_EQ(*it, 2.2);
}

// Testing prefix decrement (--it)
TEST(ListTest, PreDecrement) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  s21::list<int>::iterator it = myList.end();
  --it;

  // Check the value of the element after decrement
  EXPECT_EQ(*it, 3);
}

TEST(ListTest, PreDecrement_Char) {
  s21::list<char> myList;
  myList.push_back('a');
  myList.push_back('b');
  myList.push_back('c');

  s21::list<char>::iterator it = myList.end();
  --it;

  // Check the value of the element after decrement
  EXPECT_EQ(*it, 'c');
}

TEST(ListTest, PreDecrement_Double) {
  s21::list<double> myList;
  myList.push_back(1.1);
  myList.push_back(2.2);
  myList.push_back(3.3);

  s21::list<double>::iterator it = myList.end();
  --it;

  // Check the value of the element after decrement
  EXPECT_EQ(*it, 3.3);
}

// Testing postfix increment (it++)
TEST(ListTest, PostIncrement_0) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  s21::list<int>::iterator it = myList.begin();
  it++;

  // Check the value of the element after increment
  EXPECT_EQ(*it, 2);
}

TEST(ListTest, PostIncrement_0_Char) {
  s21::list<char> myList;
  myList.push_back('a');
  myList.push_back('b');
  myList.push_back('c');

  s21::list<char>::iterator it = myList.begin();
  it++;

  // Check the value of the element after increment
  EXPECT_EQ(*it, 'b');
}

TEST(ListTest, PostIncrement_0_Double) {
  s21::list<double> myList;
  myList.push_back(1.1);
  myList.push_back(2.2);
  myList.push_back(3.3);

  s21::list<double>::iterator it = myList.begin();
  it++;

  // Check the value of the element after increment
  EXPECT_EQ(*it, 2.2);
}

TEST(ListTest, PostIncrement_1) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  s21::list<int>::iterator it = myList.begin();
  it = it + 1;

  // Check the value of the element after increment
  EXPECT_EQ(*it, 2);
}

TEST(ListTest, PostIncrement_1_Char) {
  s21::list<char> myList;
  myList.push_back('a');
  myList.push_back('b');
  myList.push_back('c');

  s21::list<char>::iterator it = myList.begin();
  it = it + 1;

  // Check the value of the element after increment
  EXPECT_EQ(*it, 'b');
}

TEST(ListTest, PostIncrement_1_Double) {
  s21::list<double> myList;
  myList.push_back(1.1);
  myList.push_back(2.2);
  myList.push_back(3.3);

  s21::list<double>::iterator it = myList.begin();
  it = it + 1;

  // Check the value of the element after increment
  EXPECT_EQ(*it, 2.2);
}

TEST(ListTest, PostIncrement_2) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  s21::list<int>::iterator it = myList.begin();
  it += 1;

  // Check the value of the element after increment
  EXPECT_EQ(*it, 2);
}

TEST(ListTest, PostIncrement_2_Char) {
  s21::list<char> myList;
  myList.push_back('a');
  myList.push_back('b');
  myList.push_back('c');

  s21::list<char>::iterator it = myList.begin();
  it += 1;

  // Check the value of the element after increment
  EXPECT_EQ(*it, 'b');
}

TEST(ListTest, PostIncrement_2_Double) {
  s21::list<double> myList;
  myList.push_back(1.1);
  myList.push_back(2.2);
  myList.push_back(3.3);

  s21::list<double>::iterator it = myList.begin();
  it += 1;

  // Check the value of the element after increment
  EXPECT_EQ(*it, 2.2);
}

// Testing postfix decrement (it--)
TEST(ListTest, PostDecrement_0) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  s21::list<int>::iterator it = myList.end();
  it--;

  // Check the value of the element after decrement
  EXPECT_EQ(*it, 3);
}

TEST(ListTest, PostDecrement_0_Char) {
  s21::list<char> myList;
  myList.push_back('a');
  myList.push_back('b');
  myList.push_back('c');

  s21::list<char>::iterator it = myList.end();
  it--;

  // Check the value of the element after decrement
  EXPECT_EQ(*it, 'c');
}

TEST(ListTest, PostDecrement_0_Double) {
  s21::list<double> myList;
  myList.push_back(1.1);
  myList.push_back(2.2);
  myList.push_back(3.3);

  s21::list<double>::iterator it = myList.end();
  it--;

  // Check the value of the element after decrement
  EXPECT_EQ(*it, 3.3);
}

TEST(ListTest, PostDecrement_1) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  s21::list<int>::iterator it = myList.end();
  it = it - 1;

  // Check the value of the element after decrement
  EXPECT_EQ(*it, 3);
}

TEST(ListTest, PostDecrement_1_Char) {
  s21::list<char> myList;
  myList.push_back('a');
  myList.push_back('b');
  myList.push_back('c');

  s21::list<char>::iterator it = myList.end();
  it = it - 1;

  // Check the value of the element after decrement
  EXPECT_EQ(*it, 'c');
}

TEST(ListTest, PostDecrement_1_Double) {
  s21::list<double> myList;
  myList.push_back(1.1);
  myList.push_back(2.2);
  myList.push_back(3.3);

  s21::list<double>::iterator it = myList.end();
  it = it - 1;

  // Check the value of the element after decrement
  EXPECT_EQ(*it, 3.3);
}

TEST(ListTest, PostDecrement_2) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  s21::list<int>::iterator it = myList.end();
  it -= 1;

  // Check the value of the element after decrement
  EXPECT_EQ(*it, 3);
}

TEST(ListTest, PostDecrement_2_Char) {
  s21::list<char> myList;
  myList.push_back('a');
  myList.push_back('b');
  myList.push_back('c');

  s21::list<char>::iterator it = myList.end();
  it -= 1;

  // Check the value of the element after decrement
  EXPECT_EQ(*it, 'c');
}

TEST(ListTest, PostDecrement_2_Double) {
  s21::list<double> myList;
  myList.push_back(1.1);
  myList.push_back(2.2);
  myList.push_back(3.3);

  s21::list<double>::iterator it = myList.end();
  it -= 1;

  // Check the value of the element after decrement
  EXPECT_EQ(*it, 3.3);
}

// Testing iterator equality (it == other)
TEST(ListTest, Equality) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  s21::list<int>::iterator it1 = myList.begin();
  s21::list<int>::iterator it2 = myList.begin();
  s21::list<int>::iterator it3 = myList.end();

  // Check equality of iterators pointing to the same element
  EXPECT_EQ(it1, it2);

  // Check inequality of iterators pointing to different elements
  EXPECT_NE(it1, it3);
}

TEST(ListTest, Equality_Char) {
  s21::list<char> myList;
  myList.push_back('a');
  myList.push_back('b');
  myList.push_back('c');

  s21::list<char>::iterator it1 = myList.begin();
  s21::list<char>::iterator it2 = myList.begin();
  s21::list<char>::iterator it3 = myList.end();

  // Check equality of iterators pointing to the same element
  EXPECT_EQ(it1, it2);

  // Check inequality of iterators pointing to different elements
  EXPECT_NE(it1, it3);
}

TEST(ListTest, Equality_Double) {
  s21::list<double> myList;
  myList.push_back(1.1);
  myList.push_back(2.2);
  myList.push_back(3.3);

  s21::list<double>::iterator it1 = myList.begin();
  s21::list<double>::iterator it2 = myList.begin();
  s21::list<double>::iterator it3 = myList.end();

  // Check equality of iterators pointing to the same element
  EXPECT_EQ(it1, it2);

  // Check inequality of iterators pointing to different elements
  EXPECT_NE(it1, it3);
}

// Testing iterator inequality (it != other)
TEST(ListTest, Inequality) {
  s21::list<int> myList;
  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  s21::list<int>::iterator it1 = myList.begin();
  s21::list<int>::iterator it2 = myList.end();
  s21::list<int>::iterator it3 = myList.begin();

  // Check inequality of iterators pointing to different elements
  EXPECT_NE(it1, it2);

  // Check equality of iterators pointing to the same element
  EXPECT_EQ(it1, it3);
}

TEST(ListTest, Inequality_Char) {
  s21::list<char> myList;
  myList.push_back('a');
  myList.push_back('b');
  myList.push_back('c');

  s21::list<char>::iterator it1 = myList.begin();
  s21::list<char>::iterator it2 = myList.end();
  s21::list<char>::iterator it3 = myList.begin();

  // Check inequality of iterators pointing to different elements
  EXPECT_NE(it1, it2);

  // Check equality of iterators pointing to the same element
  EXPECT_EQ(it1, it3);
}

TEST(ListTest, Inequality_Double) {
  s21::list<double> myList;
  myList.push_back(1.1);
  myList.push_back(2.2);
  myList.push_back(3.3);

  s21::list<double>::iterator it1 = myList.begin();
  s21::list<double>::iterator it2 = myList.end();
  s21::list<double>::iterator it3 = myList.begin();

  // Check inequality of iterators pointing to different elements
  EXPECT_NE(it1, it2);

  // Check equality of iterators pointing to the same element
  EXPECT_EQ(it1, it3);
}

TEST(ListTest, Insert) {
  s21::list<int> my_list;
  my_list.push_back(1);
  my_list.push_back(3);

  my_list.insert(my_list.begin(), 2);
  ASSERT_EQ(my_list.size(), 3);

  auto verify_it = my_list.begin();
  EXPECT_EQ(*verify_it, 2);
  ++verify_it;
  EXPECT_EQ(*verify_it, 1);
  ++verify_it;
  EXPECT_EQ(*verify_it, 3);
}

TEST(ListTest, InsertIntoMiddle) {
  s21::list<int> lst;
  lst.push_back(1);
  lst.push_back(3);

  auto it = lst.begin();
  ++it;  // Move iterator to the second element
  it = lst.insert(it, 2);

  // Verify the contents of the list after insertion
  ASSERT_EQ(lst.size(), 3);

  auto verify_it = lst.begin();
  EXPECT_EQ(*verify_it, 1);
  ++verify_it;
  EXPECT_EQ(*verify_it, 2);
  ++verify_it;
  EXPECT_EQ(*verify_it, 3);

  it = lst.begin();
  EXPECT_EQ(*it, 1);
}

TEST(ListTest, InsertIntoEnd) {
  s21::list<int> lst;
  lst.push_back(1);
  lst.push_back(2);

  auto it = lst.begin();
  it += 2;  // Move iterator to the second element
  it = lst.insert(it, 3);

  // Verify the contents of the list after insertion
  ASSERT_EQ(lst.size(), 3);

  auto verify_it = lst.begin();
  EXPECT_EQ(*verify_it, 1);
  ++verify_it;
  EXPECT_EQ(*verify_it, 2);
  ++verify_it;
  EXPECT_EQ(*verify_it, 3);
}

TEST(ListTest, InsertIntoEmptyList) {
  s21::list<int> lst;

  auto it = lst.begin();
  it = lst.insert(it, 10);

  // Verify the contents of the list after insertion
  ASSERT_EQ(lst.size(), 1);

  auto verify_it = lst.begin();
  EXPECT_EQ(*verify_it, 10);

  // Verify the iterator returned by insert
  it = lst.begin();
  EXPECT_EQ(*it, 10);
}

TEST(ListTest, EraseElement) {
  s21::list<int> lst{1, 2, 3, 4, 5};
  auto it = lst.begin();
  lst.erase(it);

  EXPECT_EQ(4, lst.size());
  EXPECT_EQ(2, lst.front());
  EXPECT_EQ(5, lst.back());
}

TEST(ListTest, EraseElement_2) {
  s21::list<int> lst{1, 2, 3, 4, 5};
  auto it = lst.begin();
  it++;
  lst.erase(it);

  EXPECT_EQ(2, *it);
  EXPECT_EQ(4, lst.size());
  EXPECT_EQ(1, lst.front());
  EXPECT_EQ(5, lst.back());
}

TEST(ListTest, Swap) {
  s21::list<int> list1;
  list1.push_back(1);
  list1.push_back(2);
  list1.push_back(3);
  list1.push_back(4);

  s21::list<int> list2;
  list2.push_back(4);
  list2.push_back(5);
  list2.push_back(6);

  // Perform the swap
  list1.swap(list2);

  // Verify the contents of list1 after the swap
  EXPECT_EQ(3, list1.size());
  EXPECT_EQ(4, list1.front());
  EXPECT_EQ(6, list1.back());

  // Verify the contents of list2 after the swap
  EXPECT_EQ(4, list2.size());
  EXPECT_EQ(1, list2.front());
  EXPECT_EQ(4, list2.back());
}

TEST(ListTest, PushFront) {
  s21::list<int> myList;

  myList.push_front(3);
  myList.push_front(2);
  myList.push_front(1);

  EXPECT_EQ(myList.size(), 3);

  EXPECT_EQ(myList.front(), 1);
  EXPECT_EQ(myList.back(), 3);
}

// Test case for pop_front method
TEST(ListTest, PopFront) {
  s21::list<int> myList;

  myList.push_back(1);
  myList.push_back(2);
  myList.push_back(3);

  // Remove the first element
  myList.pop_front();

  // Check the size of the list
  EXPECT_EQ(myList.size(), 2);

  // Check the values of the new front and back elements
  EXPECT_EQ(myList.front(), 2);
  EXPECT_EQ(myList.back(), 3);
}

TEST(ListTest, MergeEmptyListWithEmptyList) {
  s21::list<int> lst1;
  s21::list<int> lst2;
  lst1.merge(lst2);
  EXPECT_TRUE(lst1.empty());
  EXPECT_TRUE(lst2.empty());
}

TEST(ListTest, MergeNonEmptyListWithEmptyList) {
  s21::list<int> lst1 = {1, 3, 5};
  s21::list<int> lst2;
  s21::list<int> expected = {1, 3, 5};
  lst1.merge(lst2);

  // Проверка содержимого lst1
  auto it = lst1.begin();
  for (const auto& value : expected) {
    EXPECT_EQ(*it, value);
    ++it;
  }

  EXPECT_TRUE(lst2.empty());
}

TEST(ListTest, MergeEmptyListWithNonEmptyList) {
  s21::list<int> lst1;
  s21::list<int> lst2 = {2, 4, 6};
  s21::list<int> expected = {2, 4, 6};
  lst1.merge(lst2);

  // Проверка содержимого lst1
  auto it = lst1.begin();
  for (const auto& value : expected) {
    EXPECT_EQ(*it, value);
    ++it;
  }

  EXPECT_TRUE(lst2.empty());
}

TEST(ListTest, MergeNonEmptyLists) {
  s21::list<int> lst1 = {1, 2, 3};
  s21::list<int> lst2 = {4, 5, 6};
  s21::list<int> expected = {1, 2, 3, 4, 5, 6};
  lst1.merge(lst2);

  // Проверка содержимого lst1
  auto it = lst1.begin();
  for (const auto& value : expected) {
    EXPECT_EQ(*it, value);
    ++it;
  }

  EXPECT_TRUE(lst2.empty());
}

TEST(ListTest, MergeEmptyListWithSelf) {
  s21::list<int> lst;
  lst.merge(lst);
  EXPECT_TRUE(lst.empty());
}

TEST(ListTest, MergeNonEmptyListWithSelf) {
  s21::list<int> lst = {1, 2, 3};
  lst.merge(lst);
  EXPECT_FALSE(lst.empty());
}

TEST(ListTest, Splice) {
  // Create two lists and add elements
  s21::list<int> list1{1, 2, 3};
  s21::list<int> list2{4, 5, 6};

  // Perform splice at position 3 in list1
  auto it = list1.begin();
  it += 2;
  list1.splice(it, list2);

  // Check the contents of list1 after splice
  ASSERT_EQ(list1.size(), 6);
  it = list1.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 4);
  ++it;
  EXPECT_EQ(*it, 5);
  ++it;
  EXPECT_EQ(*it, 6);
  ++it;
  EXPECT_EQ(*it, 3);

  // Check the contents of list2 after splice (should be empty)
  ASSERT_EQ(list2.size(), 0);
}

TEST(ListTest, ReverseEmptyList) {
  s21::list<int> list;

  list.reverse();

  EXPECT_TRUE(list.empty());
}

TEST(ListTest, ReverseSingleElement) {
  s21::list<int> list{42};

  list.reverse();

  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.front(), 42);
  EXPECT_EQ(list.back(), 42);
}

TEST(ListTest, ReverseElements) {
  s21::list<int> list{42, 32, 22, 12, 2};

  list.reverse();

  EXPECT_EQ(list.size(), 5);
  EXPECT_EQ(list.front(), 2);
  EXPECT_EQ(list.back(), 42);
}

TEST(ListTest, RemovesConsecutiveDuplicates) {
  s21::list<int> list1{1, 2, 2, 3, 4};
  list1.unique();

  EXPECT_EQ(list1.size(), 4);
  EXPECT_EQ(list1.front(), 1);
  EXPECT_EQ(list1.back(), 4);
}

TEST(ListTest, UniqueNoConsecutiveDuplicates) {
  s21::list<int> list2{1, 2, 3, 4};
  list2.unique();

  EXPECT_EQ(list2.size(), 4);
  EXPECT_EQ(list2.front(), 1);
  EXPECT_EQ(list2.back(), 4);
}

TEST(ListTest, UniqieEmptyList) {
  s21::list<int> list3;
  list3.unique();

  EXPECT_EQ(list3.size(), 0);
  EXPECT_TRUE(list3.empty());
}

TEST(ListTest, UniqieSingleElement) {
  s21::list<int> list4{1};
  list4.unique();

  EXPECT_EQ(list4.size(), 1);
  EXPECT_EQ(list4.front(), 1);
  EXPECT_EQ(list4.back(), 1);
}

TEST(ListTest, UniqieAllDuplicates) {
  s21::list<int> list5{1, 1, 1, 1, 1};
  list5.unique();

  EXPECT_EQ(list5.size(), 1);
  EXPECT_EQ(list5.front(), 1);
  EXPECT_EQ(list5.back(), 1);
}

TEST(ListTest, SortsEmptyList) {
  s21::list<int> lst;
  lst.sort();
  EXPECT_TRUE(lst.empty());
}

TEST(ListTest, SortsConsecutiveDuplicates) {
  s21::list<int> lst = {4, 2, 2, 1, 4, 3, 3, 2};
  s21::list<int> expected = {1, 2, 2, 2, 3, 3, 4, 4};
  lst.sort();

  auto it_actual = lst.begin();
  auto it_expected = expected.begin();
  while (it_actual != lst.end() && it_expected != expected.end()) {
    EXPECT_EQ(*it_actual, *it_expected);
    ++it_actual;
    ++it_expected;
  }

  EXPECT_EQ(it_actual, lst.end());
  EXPECT_EQ(it_expected, expected.end());
}

TEST(ListTest, SortsAlreadySortedList) {
  s21::list<int> lst = {1, 2, 3, 4, 5};
  s21::list<int> expected = {1, 2, 3, 4, 5};
  lst.sort();

  auto it_actual = lst.begin();
  auto it_expected = expected.begin();
  while (it_actual != lst.end() && it_expected != expected.end()) {
    EXPECT_EQ(*it_actual, *it_expected);
    ++it_actual;
    ++it_expected;
  }

  EXPECT_EQ(it_actual, lst.end());
  EXPECT_EQ(it_expected, expected.end());
}

TEST(ListTest, SortsReversedOrderList) {
  s21::list<int> lst = {5, 4, 3, 2, 1};
  s21::list<int> expected = {1, 2, 3, 4, 5};
  lst.sort();

  auto it_actual = lst.begin();
  auto it_expected = expected.begin();
  while (it_actual != lst.end() && it_expected != expected.end()) {
    EXPECT_EQ(*it_actual, *it_expected);
    ++it_actual;
    ++it_expected;
  }

  EXPECT_EQ(it_actual, lst.end());
  EXPECT_EQ(it_expected, expected.end());
}

TEST(ListTest, InsertMany) {
  s21::list<int> my_list;
  my_list.push_back(1);
  my_list.push_back(2);
  my_list.push_back(3);

  auto it = my_list.begin();
  ++it;  // Move iterator to the second element

  // Insert multiple elements before the second element
  my_list.insert_many(it, 4, 5, 6);

  // Verify the contents of the list after insertion
  ASSERT_EQ(my_list.size(), 6);

  auto verify_it = my_list.begin();
  EXPECT_EQ(*verify_it, 1);
  ++verify_it;
  EXPECT_EQ(*verify_it, 4);
  ++verify_it;
  EXPECT_EQ(*verify_it, 5);
  ++verify_it;
  EXPECT_EQ(*verify_it, 6);
  ++verify_it;
  EXPECT_EQ(*verify_it, 2);
  ++verify_it;
  EXPECT_EQ(*verify_it, 3);
}

TEST(ListTest, InsertManyBack) {
  s21::list<int> my_list;
  my_list.push_back(1);
  my_list.push_back(2);
  my_list.push_back(3);

  // Insert multiple elements before the second element
  my_list.insert_many_back(4, 5, 6);

  // Verify the contents of the list after insertion
  ASSERT_EQ(my_list.size(), 6);

  auto verify_it = my_list.begin();
  EXPECT_EQ(*verify_it, 1);
  ++verify_it;
  EXPECT_EQ(*verify_it, 2);
  ++verify_it;
  EXPECT_EQ(*verify_it, 3);
  ++verify_it;
  EXPECT_EQ(*verify_it, 4);
  ++verify_it;
  EXPECT_EQ(*verify_it, 5);
  ++verify_it;
  EXPECT_EQ(*verify_it, 6);
}

TEST(ListTest, InsertManyFront) {
  s21::list<int> my_list;
  my_list.push_back(1);
  my_list.push_back(2);
  my_list.push_back(3);

  // Insert multiple elements before the second element
  my_list.insert_many_front(4, 5, 6);

  // Verify the contents of the list after insertion
  ASSERT_EQ(my_list.size(), 6);

  auto verify_it = my_list.begin();
  EXPECT_EQ(*verify_it, 4);
  ++verify_it;
  EXPECT_EQ(*verify_it, 5);
  ++verify_it;
  EXPECT_EQ(*verify_it, 6);
  ++verify_it;
  EXPECT_EQ(*verify_it, 1);
  ++verify_it;
  EXPECT_EQ(*verify_it, 2);
  ++verify_it;
  EXPECT_EQ(*verify_it, 3);
}
