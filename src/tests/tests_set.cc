#include "tests.h"

TEST(setTest, DefaultConstructor) {
  s21::set<int> s;
  EXPECT_TRUE(s.empty());
  EXPECT_EQ(s.size(), 0);
}

TEST(setTest, InitializerListConstructor) {
  s21::set<int> s = {1, 2, 3};
  EXPECT_EQ(s.size(), 3);
  EXPECT_TRUE(s.contains(1));
  EXPECT_TRUE(s.contains(2));
  EXPECT_TRUE(s.contains(3));
}

TEST(setTest, CopyConstructor) {
  s21::set<int> s1 = {1, 2, 3};
  s21::set<int> s2(s1);
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(setTest, MoveConstructor) {
  s21::set<int> s1 = {1, 2, 3};
  s21::set<int> s2(std::move(s1));
  EXPECT_EQ(s2.size(), 3);
  EXPECT_TRUE(s2.contains(1));
  EXPECT_TRUE(s2.contains(2));
  EXPECT_TRUE(s2.contains(3));
}
TEST(setTest, BeginEnd) {
  s21::set<int> s{3, 5, 1, 4, 2};
  auto it = s.begin();
  ASSERT_EQ(*it, 1);

  it = s.end();
  ASSERT_EQ(it, nullptr);

  s.clear();
  it = s.begin();
  ASSERT_EQ(it, nullptr);
}

TEST(setTest, SizeMaxSize) {
  s21::set<int> s{3, 5, 1, 4, 2};
  std::set<int> s1{3, 5, 1, 4, 2};
  ASSERT_EQ(s.size(), 5);
  ASSERT_GE(s.max_size(), s1.max_size());

  s.clear();
  ASSERT_EQ(s.size(), 0);
}

TEST(setTest, Swap) {
  s21::set<int> s1{1, 2, 3};
  s21::set<int> s2{4, 5, 6};
  s1.swap(s2);
  EXPECT_EQ(s1.size(), 3);
  EXPECT_EQ(s2.size(), 3);
  EXPECT_TRUE(s2.contains(1));
  EXPECT_TRUE(s1.contains(4));
}

TEST(setTest, MergeEmpty) {
  s21::set<int> s1;
  s21::set<int> s2;

  s1.merge(s2);
  EXPECT_TRUE(s1.empty());
  EXPECT_TRUE(s2.empty());
}

TEST(setTest, MergeIntoEmpty) {
  s21::set<int> s1;
  s21::set<int> s2{5, 2, 8};

  s1.merge(s2);
  EXPECT_EQ(s1.size(), 3);
  EXPECT_TRUE(s2.empty());

  EXPECT_TRUE(s1.contains(5));
  EXPECT_TRUE(s1.contains(2));
  EXPECT_TRUE(s1.contains(8));
}

TEST(setTest, MergeNonEmpty) {
  s21::set<int> s1{5, 2, 8};
  s21::set<int> s2{3, 7, 2};

  s1.merge(s2);
  EXPECT_EQ(s1.size(), 5);
  EXPECT_EQ(s2.size(), 1);

  EXPECT_TRUE(s1.contains(5));
  EXPECT_TRUE(s1.contains(2));
  EXPECT_TRUE(s1.contains(8));
  EXPECT_TRUE(s1.contains(3));
  EXPECT_TRUE(s1.contains(7));
  EXPECT_TRUE(s2.contains(2));
}

TEST(setTest, MergeDuplicate) {
  s21::set<int> s1{5, 2, 8};
  s21::set<int> s2{3, 8, 7};

  s1.merge(s2);
  EXPECT_EQ(s1.size(), 5);
  EXPECT_EQ(s2.size(), 1);

  EXPECT_TRUE(s1.contains(5));
  EXPECT_TRUE(s1.contains(2));
  EXPECT_TRUE(s1.contains(8));
  EXPECT_TRUE(s1.contains(3));
  EXPECT_TRUE(s1.contains(7));
  EXPECT_TRUE(s2.contains(8));
  EXPECT_FALSE(s2.contains(7));
}

TEST(setTest, FindEmpty) {
  s21::set<int> s;
  auto it = s.find(5);
  EXPECT_EQ(it, s.end());
}

TEST(setTest, FindSingleElement) {
  s21::set<int> s{5};
  auto it = s.find(5);
  EXPECT_EQ(*it, 5);

  it = s.find(10);
  EXPECT_EQ(it, s.end());
}

TEST(setTest, FindMultipleElements) {
  s21::set<int> s{3, 5, 1, 4, 2};

  auto it1 = s.find(3);
  EXPECT_EQ(*it1, 3);

  auto it2 = s.find(5);
  EXPECT_EQ(*it2, 5);

  auto it3 = s.find(1);
  EXPECT_EQ(*it3, 1);

  auto it4 = s.find(4);
  EXPECT_EQ(*it4, 4);

  auto it5 = s.find(2);
  EXPECT_EQ(*it5, 2);

  auto it6 = s.find(0);
  EXPECT_EQ(it6, s.end());

  auto it7 = s.find(6);
  EXPECT_EQ(it7, s.end());
}

TEST(setTest, ContainsEmpty) {
  s21::set<int> s;
  EXPECT_FALSE(s.contains(5));
}

TEST(setTest, ContainsSingleElement) {
  s21::set<int> s{5};
  EXPECT_TRUE(s.contains(5));
  EXPECT_FALSE(s.contains(10));
}

TEST(setTest, ContainsMultipleElements) {
  s21::set<int> s{3, 5, 1, 4, 2};
  EXPECT_TRUE(s.contains(3));
  EXPECT_TRUE(s.contains(5));
  EXPECT_TRUE(s.contains(1));
  EXPECT_TRUE(s.contains(4));
  EXPECT_TRUE(s.contains(2));
  EXPECT_FALSE(s.contains(0));
  EXPECT_FALSE(s.contains(6));
}

TEST(setTest, EraseSingleElement) {
  s21::set<int> s = {1, 2, 3};
  auto it = s.find(2);
  s.erase(it);
  EXPECT_EQ(s.size(), 2);
  EXPECT_TRUE(s.contains(1));
  EXPECT_FALSE(s.contains(2));
  EXPECT_TRUE(s.contains(3));
}

TEST(setTest, EraseNonExistentElement) {
  s21::set<int> s = {1, 2, 3};
  auto it = s.find(4);
  s.erase(it);
  EXPECT_EQ(s.size(), 3);
  EXPECT_TRUE(s.contains(1));
  EXPECT_TRUE(s.contains(2));
  EXPECT_TRUE(s.contains(3));
}

TEST(setTest, EraseLastElement) {
  s21::set<int> s = {1, 2, 3};
  auto it = s.find(3);
  s.erase(it);
  EXPECT_EQ(s.size(), 2);
  EXPECT_TRUE(s.contains(1));
  EXPECT_TRUE(s.contains(2));
  EXPECT_FALSE(s.contains(3));
}

TEST(setTest, EraseFirstElement) {
  s21::set<int> s = {1, 2, 3};
  auto it = s.find(1);
  s.erase(it);
  EXPECT_EQ(s.size(), 2);
  EXPECT_FALSE(s.contains(1));
  EXPECT_TRUE(s.contains(2));
  EXPECT_TRUE(s.contains(3));
}

TEST(setTest, EraseAllElements) {
  s21::set<int> s = {1, 2, 3};
  auto it1 = s.find(1);
  s.erase(it1);
  auto it2 = s.find(2);
  s.erase(it2);
  auto it3 = s.find(3);
  s.erase(it3);
  EXPECT_EQ(s.size(), 0);
  EXPECT_FALSE(s.contains(1));
  EXPECT_FALSE(s.contains(2));
  EXPECT_FALSE(s.contains(3));
}

TEST(setTest, InsertMany) {
  s21::set<int> s;
  auto results = s.insert_many(5, 2, 8);

  EXPECT_EQ(s.size(), 3);
  EXPECT_EQ(results.size(), 3);

  EXPECT_TRUE(s.contains(5));
  EXPECT_TRUE(s.contains(2));
  EXPECT_TRUE(s.contains(8));

  // Check that all elements were successfully inserted
  for (const auto& result : results) {
    EXPECT_TRUE(result.second);
  }

  // Try inserting duplicates
  results = s.insert_many(5, 2, 8, 2);

  // Since duplicates are not inserted, the size and results vector size should
  // remain the same
  EXPECT_EQ(s.size(), 3);
  EXPECT_EQ(results.size(), 4);

  // Check that duplicates were not inserted
  for (const auto& result : results) {
    EXPECT_FALSE(result.second);
  }
}
