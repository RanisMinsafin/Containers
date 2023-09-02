#include "tests.h"

TEST(MapTests, DefaultConstructor) {
  s21::map<int, std::string> myMap;
  EXPECT_TRUE(myMap.empty());
  EXPECT_EQ(myMap.size(), 0);
}

TEST(MapTests, InitializerListConstructor) {
  s21::map<int, std::string> myMap{{1, "one"}, {2, "two"}};
  EXPECT_EQ(myMap.size(), 2);
  EXPECT_EQ(myMap[1], "one");
  EXPECT_EQ(myMap[2], "two");
}

TEST(MapTests, CopyConstructor) {
  s21::map<int, std::string> originalMap{{1, "one"}, {2, "two"}};
  s21::map<int, std::string> copiedMap(originalMap);
  EXPECT_EQ(copiedMap.size(), 2);
  EXPECT_EQ(copiedMap[1], "one");
  EXPECT_EQ(copiedMap[2], "two");
}

TEST(MapTests, InsertAndAccess) {
  s21::map<int, std::string> myMap;
  myMap.insert({1, "one"});
  myMap.insert({2, "two"});
  EXPECT_EQ(myMap[1], "one");
  EXPECT_EQ(myMap[2], "two");
}

TEST(MapTests, AtMethod) {
  s21::map<int, std::string> myMap{{1, "one"}, {2, "two"}};
  EXPECT_EQ(myMap.at(1), "one");
  EXPECT_EQ(myMap.at(2), "two");
  // EXPECT_THROW(myMap.at(3), std::runtime_error);
}

TEST(MapTests, BeginMethod) {
  s21::map<int, std::string> myMap{{1, "one"}, {2, "two"}};
  auto it = myMap.begin();
  EXPECT_EQ(it->first, 1);
  EXPECT_EQ(it->second, "one");
}

TEST(MapTests, EndMethod) {
  s21::map<int, std::string> myMap{{1, "one"}, {2, "two"}};
  auto it = myMap.end();
  EXPECT_EQ(it, myMap.begin() + 2);  // myMap has 2 elements
}

TEST(MapTests, EmptyMethod) {
  s21::map<int, std::string> myMap;
  EXPECT_TRUE(myMap.empty());
  myMap[1] = "one";
  EXPECT_FALSE(myMap.empty());
}

TEST(MapTests, ClearMethod) {
  s21::map<int, std::string> myMap{{1, "one"}, {2, "two"}};
  myMap.clear();
  EXPECT_TRUE(myMap.empty());
}

TEST(MapTests, SizeAndEmptyMethods) {
  s21::map<int, std::string> myMap{{1, "one"}, {2, "two"}};
  EXPECT_EQ(myMap.size(), 2);
  EXPECT_FALSE(myMap.empty());
  myMap.clear();
  EXPECT_EQ(myMap.size(), 0);
  EXPECT_TRUE(myMap.empty());
}

TEST(MapTests, MaxSizeMethod) {
  s21::map<int, std::string> myMap;
  std::map<int, std::string> standartMap;
  EXPECT_EQ(230584300921369395, myMap.max_size());
}

TEST(MapTests, InsertMethod) {
  s21::map<int, std::string> myMap;
  auto result = myMap.insert({1, "one"});
  EXPECT_TRUE(result.second);
  EXPECT_EQ(result.first->second, "one");

  result = myMap.insert({1, "new_one"});
  EXPECT_FALSE(result.second);
}

TEST(MapTests, InsertMethod_2) {
  s21::map<int, std::string> myMap;

  auto result1 = myMap.insert(1, "one");
  auto result2 = myMap.insert(2, "two");
  auto result3 = myMap.insert(1, "new_one");

  EXPECT_EQ(result1.second, true);
  EXPECT_EQ(result2.second, true);
  EXPECT_FALSE(result3.second);
}

TEST(MapTests, InsertOrAssign) {
  s21::map<int, std::string> myMap;

  auto result1 = myMap.insert_or_assign(1, "one");
  auto result2 = myMap.insert_or_assign(2, "two");
  auto result3 = myMap.insert_or_assign(1, "new_one");

  EXPECT_EQ(result1.second, true);
  EXPECT_EQ(result2.second, true);
  EXPECT_EQ(result3.second, false);

  EXPECT_EQ(myMap[1], "new_one");
  EXPECT_EQ(myMap[2], "two");
}

TEST(MapTest, EraseTest) {
  s21::map<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};

  auto it = myMap.begin();
  myMap.erase(it);

  ASSERT_EQ(myMap.size(), 2);
  ASSERT_FALSE(myMap.contains(1));
}

TEST(MapTest, SwapTest) {
  s21::map<int, std::string> myMap = {{1, "one"}, {2, "two"}};
  s21::map<int, std::string> otherMap = {{10, "ten"}, {20, "twenty"}};

  myMap.swap(otherMap);

  ASSERT_EQ(myMap.size(), 2);
  ASSERT_TRUE(myMap.contains(10));
  ASSERT_TRUE(myMap.contains(20));

  ASSERT_EQ(otherMap.size(), 2);
  ASSERT_TRUE(otherMap.contains(1));
  ASSERT_TRUE(otherMap.contains(2));
}

TEST(MapTest, MergeTest) {
  s21::map<int, std::string> myMap = {{1, "one"}, {2, "two"}};
  s21::map<int, std::string> mergeMap = {{3, "three"}, {4, "four"}};

  myMap.merge(mergeMap);

  ASSERT_EQ(myMap.size(), 4);
  ASSERT_TRUE(myMap.contains(1));
  ASSERT_TRUE(myMap.contains(2));
  ASSERT_TRUE(myMap.contains(3));
  ASSERT_TRUE(myMap.contains(4));

  ASSERT_EQ(mergeMap.size(), 0);
}

TEST(MapTests, ContainsMethod) {
  s21::map<int, std::string> myMap{{1, "aaa"}, {2, "bbb"}};
  EXPECT_TRUE(myMap.contains(1));
  EXPECT_FALSE(myMap.contains(4));
}
