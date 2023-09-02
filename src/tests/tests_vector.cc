#include "tests.h"

TEST(Vector, DefaultConstructor) {
  s21::vector<int> v1;
  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v1.capacity(), 0);
}

TEST(Vector, ParamConstructor) {
  s21::vector<std::string> v2(5);
  EXPECT_EQ(v2.size(), 5);
  EXPECT_EQ(v2.capacity(), 5);
}

TEST(Vector, IinitializerConstructor) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v1.capacity(), 3);
  EXPECT_EQ(v1[0], 1);
  EXPECT_EQ(v1[1], 2);
  EXPECT_EQ(v1[2], 3);
}

TEST(Vector, CopyConstructor) {
  s21::vector<std::string> v1{"Hello", "Emily"};
  s21::vector<std::string> v2 = v1;
  EXPECT_EQ(v2.size(), 2);
  EXPECT_EQ(v2[0], "Hello");
  EXPECT_EQ(v2[1], "Emily");
}

TEST(Vector, MoveConstructor) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector v2(std::move(v1));
  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v1.capacity(), 0);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_EQ(v2.capacity(), 3);
  EXPECT_EQ(v2[0], 1);
}

TEST(Vector, Index) {
  s21::vector<std::string> v1{"Hello", "Hi"};
  EXPECT_EQ(v1[0], "Hello");
  v1[0] = "Bye";
  EXPECT_EQ(v1[0], "Bye");
  // EXPECT_ANY_THROW(v1.at(2));
  EXPECT_EQ(v1.at(1), "Hi");
  v1.at(1) = "Adios";
  EXPECT_EQ(v1.at(1), "Adios");
}

TEST(Vector, Front) {
  s21::vector<char> v1{'a', 'b', 'c'};
  EXPECT_EQ(v1.front(), 'a');
}

TEST(Vector, Back) {
  s21::vector<char> v1{'a', 'b', 'c'};
  EXPECT_EQ(v1.back(), 'c');
}

TEST(Vector, Data) {
  s21::vector<int> v1;
  EXPECT_EQ(v1.data(), nullptr);
  s21::vector<int> v2{5, 7};
  EXPECT_EQ(*(v2.data()), 5);
}

TEST(Vector, Begin) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_EQ(*v1.begin(), 1);
  // EXPECT_EQ(v1.begin(), v1.end()); ???
}

TEST(Vector, Iterator) {
  s21::vector<int> v1{3, 5, 99};
  s21::vector<int>::iterator iter = v1.begin();
  EXPECT_EQ(*(++iter), 5);
  EXPECT_EQ(*(--iter), 3);
  *iter = 999;
  EXPECT_EQ(v1[0], 999);
  s21::vector<int>::iterator iter2 = v1.begin();
  EXPECT_TRUE(iter == iter2);
  EXPECT_FALSE(iter != iter2);
  s21::vector<int>::iterator iter3 = v1.begin();
  v1.insert(iter3 + 1, 888);
  EXPECT_EQ(v1[1], 888);
}

TEST(Vector, Reserve) {
  s21::vector<std::string> v1{"Hello", "Bye"};
  v1.reserve(3);
  EXPECT_EQ(v1.capacity(), 3);
  EXPECT_EQ(v1.size(), 2);
}

TEST(Vector, PushPopBack) {
  s21::vector<std::string> v1{"Hello", "Bye"};
  v1.push_back("Hell");
  EXPECT_EQ(v1.capacity(), 4);
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ("Hell", v1[2]);
  v1.pop_back();
  EXPECT_EQ(v1.capacity(), 4);
  EXPECT_EQ(v1.size(), 2);
}

TEST(Vector, Clear) {
  s21::vector<std::string> v1{"bla", "blya"};
  v1.clear();
  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v1.capacity(), 2);
  // EXPECT_ANY_THROW(v1[0]);
}

TEST(Vector, ShrinkToFit) {
  std::vector<int> v1{1, 2, 3};
  v1.reserve(100);
  v1.shrink_to_fit();
  EXPECT_EQ(v1.capacity(), 3);
  EXPECT_EQ(v1.size(), 3);
}

TEST(Vector, Empty) {
  s21::vector<std::string> v1;
  EXPECT_EQ(v1.empty(), true);
  s21::vector<std::string> v2{"Hello"};
  EXPECT_EQ(v2.empty(), false);
  v2.pop_back();
  EXPECT_EQ(v2.empty(), true);
}

TEST(Vector, Insert) {
  s21::vector<std::string> v1;
  s21::vector<std::string>::iterator it = v1.insert(v1.begin(), "bla");
  EXPECT_EQ(*it, v1[0]);
  EXPECT_EQ(v1.size(), 1);
  EXPECT_EQ(v1.capacity(), 1);
  EXPECT_EQ(v1[0], "bla");

  s21::vector<std::string> v2{"bla", "summer", "lala"};
  s21::vector<std::string>::iterator it2 = v2.begin() + 2;
  s21::vector<std::string>::iterator pos = v2.insert(it2, "haha");
  EXPECT_EQ(v2[2], *pos);
  EXPECT_EQ(v2.size(), 4);
  EXPECT_EQ(v2.capacity(), 6);
  EXPECT_EQ(v2[2], "haha");
  EXPECT_EQ(v2[3], "lala");

  it2 = v2.begin() + 2;
  pos = v2.insert(it2, "check");
  EXPECT_EQ(v2[2], *pos);
  EXPECT_EQ(v2.size(), 5);
  EXPECT_EQ(v2.capacity(), 6);
  EXPECT_EQ(v2[2], "check");
  EXPECT_EQ(v2[3], "haha");

  it2 = v2.begin() + 5;
  pos = v2.insert(it2, "abc");
  EXPECT_EQ(v2[5], *pos);
  EXPECT_EQ(v2.size(), 6);
  EXPECT_EQ(v2.capacity(), 6);
  EXPECT_EQ(v2[4], "lala");
  EXPECT_EQ(v2[5], "abc");
}

TEST(Vector, Erase) {
  s21::vector<std::string> v1{"bla", "summer", "lala", "abc"};
  v1.erase(v1.begin() + 2);
  EXPECT_EQ(v1.capacity(), 4);
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v1[1], "summer");
  EXPECT_EQ(v1[2], "abc");
  v1.erase(v1.begin() + 2);
  EXPECT_EQ(v1.capacity(), 4);
  EXPECT_EQ(v1.size(), 2);
  EXPECT_EQ(v1[0], "bla");
  EXPECT_EQ(v1[1], "summer");
}

TEST(Vector, Swap) {
  s21::vector<std::string> v1{"Hello", "Bye", "Emily"};
  s21::vector<std::string> v2{"NO", "YES"};
  v1.swap(v2);
  EXPECT_EQ(v1.capacity(), 2);
  EXPECT_EQ(v1.size(), 2);
  EXPECT_EQ(v2.capacity(), 3);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_EQ(v1[0], "NO");
  EXPECT_EQ(v2[0], "Hello");
}

TEST(Vector, Insert_many) {
  s21::vector<std::string> v1{"Hello", "Bye"};
  v1.insert_many(v1.begin(), "Good", "Bad", "Ok");
  EXPECT_EQ(v1.size(), 5);
  EXPECT_EQ(v1.capacity(), 8);
  EXPECT_EQ(v1[0], "Good");

  s21::vector<std::string>::iterator pos =
      v1.insert_many(v1.begin() + 5, "abc", "bla");
  EXPECT_EQ(v1.size(), 7);
  EXPECT_EQ(v1.capacity(), 8);
  EXPECT_EQ(*pos, v1[5]);
  EXPECT_EQ(v1[5], "abc");
  EXPECT_EQ(v1[6], "bla");
  s21::vector<std::string> v2;
  s21::vector<std::string>::iterator pos2 =
      v2.insert_many(v2.begin(), "Hello", "Bye");
  EXPECT_EQ(v2.size(), 2);
  EXPECT_EQ(v2.capacity(), 2);
  EXPECT_EQ(*pos2, v2[0]);
  EXPECT_EQ(v2[0], "Hello");
  EXPECT_EQ(v2[1], "Bye");
}

TEST(Vector, Insert_many_back) {
  s21::vector<int> v1{10, 9, 8};
  v1.insert_many_back(100, 200, 999);
  EXPECT_EQ(v1.capacity(), 6);
  EXPECT_EQ(v1.size(), 6);
  EXPECT_EQ(v1[3], 100);

  s21::vector<std::string> v2;
  v2.insert_many_back("bla", "blaaa");
  EXPECT_EQ(v2.capacity(), 2);
  EXPECT_EQ(v2.size(), 2);
  EXPECT_EQ(v2[0], "bla");
  EXPECT_EQ(v2[1], "blaaa");

  s21::vector<std::string> v3{"hello"};
  v3.reserve(5);
  v3.insert_many_back("hi", "bla");
  EXPECT_EQ(v3.size(), 3);
  EXPECT_EQ(v3.capacity(), 5);
  EXPECT_EQ(v3[0], "hello");
  EXPECT_EQ(v3[1], "hi");
  EXPECT_EQ(v3[2], "bla");
}
