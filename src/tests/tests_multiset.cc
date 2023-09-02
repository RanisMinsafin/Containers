#include "tests.h"

class TestMultiset : public testing::Test {
 protected:
  std::multiset<int> std_int_1 = {2, 3, 11, 1, 5,  5,  5, 5,  4,  7,  6,
                                  9, 1, 15, 8, 10, 11, 3, 12, 13, 15, 14};
  s21::multiset<int> s21_int_1 = {2, 3, 11, 1, 5,  5,  5, 5,  4,  7,  6,
                                  9, 1, 15, 8, 10, 11, 3, 12, 13, 15, 14};

  s21::multiset<int> s21_int_2 = {2, 3, 11, 1, 5, 5, 5, 5, 4};

  std::multiset<char> std_char_1 = {2, 3, 11, 1, 5,  5,  5, 5,  4,  7,  6,
                                    9, 1, 15, 8, 10, 11, 3, 12, 13, 15, 14};
  s21::multiset<char> s21_char_1 = {2, 3, 11, 1, 5,  5,  5, 5,  4,  7,  6,
                                    9, 1, 15, 8, 10, 11, 3, 12, 13, 15, 14};

  std::multiset<std::string> std_str_1 = {
      "school21", "s21_conteiners", "s21_conteiners", "multiset", "teamwork"};
  s21::multiset<std::string> s21_str_1 = {
      "school21", "s21_conteiners", "s21_conteiners", "multiset", "teamwork"};
};

// Test STRING

// MultiSet Iterators

TEST_F(TestMultiset, BeginStr) {
  std::multiset<std::string> mult1(std::move(std_str_1));
  s21::multiset<std::string> mult2(std::move(s21_str_1));
  auto it1 = mult1.begin();
  auto it2 = mult2.begin();
  EXPECT_TRUE((*it1) == (*it2));
}

TEST_F(TestMultiset, EndStr) {
  s21::multiset<std::string> mult2(std::move(s21_str_1));
  auto it2 = mult2.end();
  EXPECT_TRUE(it2 == nullptr);
}

// MultiSet Capacity

TEST_F(TestMultiset, EmptyStr) {
  std::multiset<std::string> mult1(std::move(std_str_1));
  s21::multiset<std::string> mult2(std::move(s21_str_1));
  bool x1 = mult1.empty();
  bool x2 = mult2.empty();
  EXPECT_TRUE(x1 == x2);
}

TEST_F(TestMultiset, SizeStr) {
  std::multiset<std::string> mult1(std::move(std_str_1));
  s21::multiset<std::string> mult2(std::move(s21_str_1));
  auto x1 = mult1.size();
  auto x2 = mult2.size();
  EXPECT_TRUE(x1 == x2);
}

// MultiSet Modifiers

TEST_F(TestMultiset, ClearStr) {
  s21::multiset<std::string> mult(std::move(s21_str_1));
  auto size = mult.size();
  mult.clear();
  EXPECT_TRUE(size == 5);
  EXPECT_TRUE(mult.size() == 0);
}

TEST_F(TestMultiset, InsertStr) {
  std::multiset<std::string> mult1(std::move(std_str_1));
  s21::multiset<std::string> mult2(std::move(s21_str_1));
  auto size1 = mult1.size();
  auto size2 = mult2.size();
  auto it1 = mult1.insert("Insert");
  auto it2 = mult2.insert("Insert");
  EXPECT_TRUE(*it1 == *it2);
  EXPECT_TRUE(size1 == size2);
  EXPECT_TRUE(mult1.size() == mult2.size());
  EXPECT_TRUE(size2 + 1 == mult2.size());
}

TEST_F(TestMultiset, EraseStr) {
  s21::multiset<std::string> mult(std::move(s21_str_1));
  auto size1 = mult.size();
  auto it = mult.find("multiset");
  mult.erase(it);
  EXPECT_TRUE((size1 - 1) == mult.size());
  EXPECT_FALSE(mult.contains("multiset"));
}

TEST_F(TestMultiset, SwapStr) {
  s21::multiset<std::string> mult1(std::move(s21_str_1));
  s21::multiset<std::string> mult2;
  mult1.swap(mult2);
  EXPECT_TRUE(mult1.begin() == nullptr);
  EXPECT_TRUE(mult2.begin() != nullptr);
  EXPECT_FALSE(mult1.size());
  EXPECT_TRUE(mult2.size());
}

TEST_F(TestMultiset, MergeStr) {
  s21::multiset<std::string> mult1(s21_str_1);
  s21::multiset<std::string> mult2(s21_str_1);
  auto size = mult1.size();
  mult1.merge(mult2);
  EXPECT_TRUE(mult1.size() == 2 * size);
  EXPECT_TRUE(mult2.size() == 0);
}

// // MultiSet Lookup

TEST_F(TestMultiset, CountStr) {
  std::multiset<std::string> mult1(std::move(std_str_1));
  s21::multiset<std::string> mult2(std::move(s21_str_1));
  EXPECT_TRUE(mult1.count("s21_conteiners") == mult2.count("s21_conteiners"));
  EXPECT_TRUE(mult2.count("s21_conteiners") == 2);
}

TEST_F(TestMultiset, FindStr) {
  std::multiset<std::string> mult1(std::move(std_str_1));
  s21::multiset<std::string> mult2(std::move(s21_str_1));
  auto it1 = mult1.find("multiset");
  auto it2 = mult2.find("multiset");
  EXPECT_TRUE(*it1 == *it2);
}

TEST_F(TestMultiset, ContainsStr) {
  s21::multiset<std::string> mult(std::move(s21_str_1));
  bool x = mult.contains("teamwork");
  EXPECT_TRUE(x == true);
  bool y = mult.contains("not string");
  EXPECT_TRUE(y == false);
}

TEST_F(TestMultiset, EqualRangeStr) {
  s21::multiset<std::string> mult(std::move(s21_str_1));
  auto x = mult.equal_range("s21_conteiners");
  EXPECT_TRUE(*(x.first) == "s21_conteiners");
  EXPECT_TRUE(*(x.second) == "school21");
}

TEST_F(TestMultiset, LowerBoundStr1) {
  std::multiset<std::string> mult1(std::move(std_str_1));
  s21::multiset<std::string> mult2(std::move(s21_str_1));
  auto it1 = mult1.lower_bound("s21_conteiners");
  auto it2 = mult2.lower_bound("s21_conteiners");
  EXPECT_TRUE(*it1 == *it2);
}

TEST_F(TestMultiset, LowerBoundStr2) {
  s21::multiset<std::string> mult(std::move(s21_str_1));
  auto it = mult.lower_bound("zzzzzz");
  EXPECT_TRUE(it == mult.end());
}

TEST_F(TestMultiset, UpperBoundStr1) {
  std::multiset<std::string> mult1(std_str_1);
  s21::multiset<std::string> mult2(s21_str_1);
  auto it1 = mult1.upper_bound("s21_conteiners");
  auto it2 = mult2.upper_bound("s21_conteiners");
  EXPECT_TRUE(*it1 == *it2);
}

TEST_F(TestMultiset, UpperBoundStr2) {
  s21::multiset<std::string> mult(s21_str_1);
  auto it = mult.upper_bound("zzzzzz");
  EXPECT_TRUE(it == mult.end());
}

TEST_F(TestMultiset, InsertManyStr) {
  s21::multiset<std::string> mult(s21_str_1);
  auto size = mult.size();
  auto vect =
      mult.insert_many("school21", "21school", "InsertManyStr", "TestMultiset");
  auto it = vect.begin();
  EXPECT_TRUE(size + 4 == mult.size());
  EXPECT_TRUE(vect.size() == 4);
  EXPECT_TRUE(*(it->first) == "school21");
  EXPECT_TRUE((it->second) == true);
}

// Test INT

// MultiSet Iterators

TEST_F(TestMultiset, Begin) {
  std::multiset<int> mult1(std::move(std_int_1));
  s21::multiset<int> mult2(std::move(s21_int_1));
  auto it1 = mult1.begin();
  auto it2 = mult2.begin();
  EXPECT_TRUE((*it1) == (*it2));
}

TEST_F(TestMultiset, End) {
  s21::multiset<int> mult2(std::move(s21_int_1));
  auto it2 = mult2.end();
  EXPECT_TRUE(it2 == nullptr);
}

// MultiSet Capacity

TEST_F(TestMultiset, Empty) {
  std::multiset<int> mult1(std::move(std_int_1));
  s21::multiset<int> mult2(std::move(s21_int_1));
  bool x1 = mult1.empty();
  bool x2 = mult2.empty();
  EXPECT_TRUE(x1 == x2);
}

TEST_F(TestMultiset, Size) {
  std::multiset<int> mult1(std::move(std_int_1));
  s21::multiset<int> mult2(std::move(s21_int_1));
  auto x1 = mult1.size();
  auto x2 = mult2.size();
  EXPECT_TRUE(x1 == x2);
}

// MultiSet Modifiers

TEST_F(TestMultiset, Clear) {
  s21::multiset<int> mult(std::move(s21_int_1));
  auto size = mult.size();
  mult.clear();
  EXPECT_TRUE(size == 22);
  EXPECT_TRUE(mult.size() == 0);
}

TEST_F(TestMultiset, Insert) {
  std::multiset<int> mult1(std::move(std_int_1));
  s21::multiset<int> mult2(std::move(s21_int_1));
  auto size1 = mult1.size();
  auto size2 = mult2.size();
  auto it1 = mult1.insert(6);
  auto it2 = mult2.insert(6);
  EXPECT_TRUE(*it1 == *it2);
  EXPECT_TRUE(size1 == size2);
  EXPECT_TRUE(mult1.size() == mult2.size());
  EXPECT_TRUE(size2 + 1 == mult2.size());
}

TEST_F(TestMultiset, Erase) {
  s21::multiset<int> mult(std::move(s21_int_1));
  auto size1 = mult.size();
  auto it = mult.find(7);
  mult.erase(it);
  int x = 7;
  EXPECT_TRUE((size1 - 1) == mult.size());
  EXPECT_FALSE(mult.contains(x));
}

TEST_F(TestMultiset, Swap) {
  s21::multiset<int> mult1(std::move(s21_int_1));
  s21::multiset<int> mult2;
  mult1.swap(mult2);
  EXPECT_TRUE(mult1.begin() == nullptr);
  EXPECT_TRUE(mult2.begin() != nullptr);
  EXPECT_FALSE(mult1.size());
  EXPECT_TRUE(mult2.size());
}

TEST_F(TestMultiset, Merge) {
  s21::multiset<int> mult1(s21_int_1);
  s21::multiset<int> mult2(s21_int_1);
  auto size = mult1.size();
  mult1.merge(mult2);
  EXPECT_TRUE(mult1.size() == 2 * size);
  EXPECT_TRUE(mult2.size() == 0);
}

// // MultiSet Lookup

TEST_F(TestMultiset, Count) {
  std::multiset<int> mult1(std::move(std_int_1));
  s21::multiset<int> mult2(std::move(s21_int_1));
  EXPECT_TRUE(mult1.count(5) == mult2.count(5));
}

TEST_F(TestMultiset, Find) {
  std::multiset<int> mult1(std::move(std_int_1));
  s21::multiset<int> mult2(std::move(s21_int_1));
  auto it1 = mult1.find(5);
  auto it2 = mult2.find(5);
  EXPECT_TRUE(*it1 == *it2);
}

TEST_F(TestMultiset, Contains) {
  s21::multiset<int> mult(std::move(s21_int_1));
  bool x = mult.contains(5);
  EXPECT_TRUE(x == true);
  bool y = mult.contains(50);
  EXPECT_TRUE(y == false);
}

TEST_F(TestMultiset, EqualRange) {
  s21::multiset<int> mult(std::move(s21_int_1));
  auto x = mult.equal_range(5);
  EXPECT_TRUE(*(x.first) == 5);
  EXPECT_TRUE(*(x.second) == 6);
}

TEST_F(TestMultiset, LowerBound1) {
  std::multiset<int> mult1(std::move(std_int_1));
  s21::multiset<int> mult2(std::move(s21_int_1));
  auto it1 = mult1.lower_bound(5);
  auto it2 = mult2.lower_bound(5);
  EXPECT_TRUE(*it1 == *it2);
}

TEST_F(TestMultiset, LowerBound2) {
  s21::multiset<int> mult(std::move(s21_int_1));
  auto it = mult.lower_bound(50);
  EXPECT_TRUE(it == mult.end());
}

TEST_F(TestMultiset, UpperBound1) {
  std::multiset<int> mult1(std_int_1);
  s21::multiset<int> mult2(s21_int_1);
  auto it1 = mult1.upper_bound(5);
  auto it2 = mult2.upper_bound(5);
  EXPECT_TRUE(*it1 == *it2);
}

TEST_F(TestMultiset, UpperBound2) {
  s21::multiset<int> mult(s21_int_1);
  auto it = mult.upper_bound(50);
  EXPECT_TRUE(it == mult.end());
}

TEST_F(TestMultiset, InsertMany) {
  s21::multiset<int> mult(s21_int_1);
  auto size = mult.size();
  auto vect = mult.insert_many(50, 40, 40, 3, 2);
  auto it = vect.begin();
  EXPECT_TRUE(size + 5 == mult.size());
  EXPECT_TRUE(vect.size() == 5);
  EXPECT_TRUE(*(it->first) == 50);
  EXPECT_TRUE((it->second) == true);
}

// Test CHAR

// MultiSet Iterators

TEST_F(TestMultiset, BeginChar) {
  std::multiset<char> mult1(std::move(std_char_1));
  s21::multiset<char> mult2(std::move(s21_char_1));
  auto it1 = mult1.begin();
  auto it2 = mult2.begin();
  EXPECT_TRUE((*it1) == (*it2));
}

TEST_F(TestMultiset, EndChar) {
  s21::multiset<char> mult2(std::move(s21_char_1));
  auto it2 = mult2.end();
  EXPECT_TRUE(it2 == nullptr);
}

// MultiSet Capacity

TEST_F(TestMultiset, EmptyChar) {
  std::multiset<char> mult1(std::move(std_char_1));
  s21::multiset<char> mult2(std::move(s21_char_1));
  bool x1 = mult1.empty();
  bool x2 = mult2.empty();
  EXPECT_TRUE(x1 == x2);
}

TEST_F(TestMultiset, SizeChar) {
  std::multiset<char> mult1(std::move(std_char_1));
  s21::multiset<char> mult2(std::move(s21_char_1));
  auto x1 = mult1.size();
  auto x2 = mult2.size();
  EXPECT_TRUE(x1 == x2);
}

// MultiSet Modifiers

TEST_F(TestMultiset, ClearChar) {
  s21::multiset<char> mult(std::move(s21_char_1));
  auto size = mult.size();
  mult.clear();
  EXPECT_TRUE(size == 22);
  EXPECT_TRUE(mult.size() == 0);
}

TEST_F(TestMultiset, InsertChar) {
  std::multiset<char> mult1(std::move(std_char_1));
  s21::multiset<char> mult2(std::move(s21_char_1));
  auto size1 = mult1.size();
  auto size2 = mult2.size();
  auto it1 = mult1.insert(6);
  auto it2 = mult2.insert(6);
  EXPECT_TRUE(*it1 == *it2);
  EXPECT_TRUE(size1 == size2);
  EXPECT_TRUE(mult1.size() == mult2.size());
  EXPECT_TRUE(size2 + 1 == mult2.size());
}

TEST_F(TestMultiset, EraseChar) {
  s21::multiset<char> mult(std::move(s21_char_1));
  auto size1 = mult.size();
  auto it = mult.find(7);
  mult.erase(it);
  int x = 7;
  EXPECT_TRUE((size1 - 1) == mult.size());
  EXPECT_FALSE(mult.contains(x));
}

TEST_F(TestMultiset, SwapChar) {
  s21::multiset<char> mult1(std::move(s21_char_1));
  s21::multiset<char> mult2;
  mult1.swap(mult2);
  EXPECT_TRUE(mult1.begin() == nullptr);
  EXPECT_TRUE(mult2.begin() != nullptr);
  EXPECT_FALSE(mult1.size());
  EXPECT_TRUE(mult2.size());
}

TEST_F(TestMultiset, MergeChar) {
  s21::multiset<char> mult1(s21_char_1);
  s21::multiset<char> mult2(s21_char_1);
  auto size = mult1.size();
  mult1.merge(mult2);
  EXPECT_TRUE(mult1.size() == 2 * size);
  EXPECT_TRUE(mult2.size() == 0);
}

// // MultiSet Lookup

TEST_F(TestMultiset, CountChar) {
  std::multiset<char> mult1(std::move(std_char_1));
  s21::multiset<char> mult2(std::move(s21_char_1));
  EXPECT_TRUE(mult1.count(5) == mult2.count(5));
}

TEST_F(TestMultiset, FindChar) {
  std::multiset<char> mult1(std::move(std_char_1));
  s21::multiset<char> mult2(std::move(s21_char_1));
  auto it1 = mult1.find(5);
  auto it2 = mult2.find(5);
  EXPECT_TRUE(*it1 == *it2);
}

TEST_F(TestMultiset, ContainsChar) {
  s21::multiset<char> mult(std::move(s21_char_1));
  bool x = mult.contains(5);
  EXPECT_TRUE(x == true);
  bool y = mult.contains(50);
  EXPECT_TRUE(y == false);
}

TEST_F(TestMultiset, EqualRangeChar) {
  s21::multiset<char> mult(std::move(s21_char_1));
  auto x = mult.equal_range(5);
  EXPECT_TRUE(*(x.first) == 5);
  EXPECT_TRUE(*(x.second) == 6);
}

TEST_F(TestMultiset, LowerBoundChar1) {
  std::multiset<char> mult1(std::move(std_char_1));
  s21::multiset<char> mult2(std::move(s21_char_1));
  auto it1 = mult1.lower_bound(5);
  auto it2 = mult2.lower_bound(5);
  EXPECT_TRUE(*it1 == *it2);
}

TEST_F(TestMultiset, LowerBoundChar2) {
  s21::multiset<char> mult(std::move(s21_char_1));
  auto it = mult.lower_bound(50);
  EXPECT_TRUE(it == mult.end());
}

TEST_F(TestMultiset, UpperBoundChar1) {
  std::multiset<char> mult1(std_char_1);
  s21::multiset<char> mult2(s21_char_1);
  auto it1 = mult1.upper_bound(5);
  auto it2 = mult2.upper_bound(5);
  EXPECT_TRUE(*it1 == *it2);
}

TEST_F(TestMultiset, UpperBoundChar2) {
  s21::multiset<char> mult(s21_char_1);
  auto it = mult.upper_bound(50);
  EXPECT_TRUE(it == mult.end());
}

TEST_F(TestMultiset, InsertManyChar) {
  s21::multiset<char> mult(s21_char_1);
  auto size = mult.size();
  auto vect = mult.insert_many(50, 40, 40, 3, 2);
  auto it = vect.begin();
  EXPECT_TRUE(size + 5 == mult.size());
  EXPECT_TRUE(vect.size() == 5);
  EXPECT_TRUE(*(it->first) == 50);
  EXPECT_TRUE((it->second) == true);
}
