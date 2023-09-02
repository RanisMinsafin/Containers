#include "tests.h"

TEST(Array, DefaultConstructor) {
  s21::array<int, 100> a1;
  s21::array<std::string, 5> a2;
  EXPECT_EQ(a1.size(), 100);
  EXPECT_EQ(a1[99], 0);
  EXPECT_EQ(a2.size(), 5);
  EXPECT_EQ(a2[4], "");
}

TEST(Array, InstalizerConstructor) {
  s21::array<char, 3> a2{'h', 'i', '\n'};
  EXPECT_EQ(a2.size(), 3);
  EXPECT_EQ(a2[0], 'h');
  EXPECT_EQ(a2[1], 'i');
  EXPECT_EQ(a2[2], '\n');
  s21::array<const char*, 2> a3{"hello", "bye"};
  EXPECT_STREQ(a3[0], "hello");
  EXPECT_STREQ(a3[1], "bye");
  EXPECT_EQ(a3.size(), 2);
}

TEST(Array, CopyConstructor) {
  s21::array<int, 3> a1{1, 2, 3};
  s21::array<int, 3> a2 = a1;
  EXPECT_EQ(a1[0], a2[0]);
  EXPECT_EQ(a1[1], a2[1]);
  EXPECT_EQ(a1[2], a2[2]);
}

TEST(Array, MoveConstructor) {
  s21::array<std::string, 3> s1{"Hello", "Emily", "Bye"};
  s21::array s2(std::move(s1));
  EXPECT_EQ(s2[0], "Hello");
  EXPECT_EQ(s2[1], "Emily");
  EXPECT_EQ(s2[2], "Bye");
  EXPECT_EQ(s1[0], "");
}

TEST(Array, At) {
  s21::array<std::string, 2> a1{"bla", "lala"};
  EXPECT_EQ(a1.at(0), "bla");
  // EXPECT_ANY_THROW(a1.at(2));
  const s21::array<double, 3> a2{0.99, 0.999, 0.9999};
  EXPECT_EQ(a2.at(1), 0.999);
}

TEST(Array, Brackets) {
  s21::array<std::string, 3> a1{"Hello", "hell", "he"};
  EXPECT_EQ(a1[2], "he");
  EXPECT_EQ(a1[1], "hell");
  EXPECT_EQ(a1[0], "Hello");
  const s21::array<int, 2> a2{0, 1};
  EXPECT_EQ(a2[0], 0);
  EXPECT_EQ(a2[1], 1);
}

TEST(Array, Front) {
  s21::array<char, 3> a1{'h', 'i', 'o'};
  EXPECT_EQ('h', a1.front());
  s21::array<std::string, 3> a2{"Hello", "Bye"};
  EXPECT_EQ(a2.front(), "Hello");
}

TEST(Array, Back) {
  s21::array<char, 5> a1{'E', 'm', 'i', 'l', 'y'};
  EXPECT_EQ('y', a1.back());
}

TEST(Array, Data) {
  s21::array<int, 3> a1{1, 2, 3};
  EXPECT_EQ(1, *(a1.data()));
  s21::array<std::string, 2> a2{"bla", "lala"};
  EXPECT_EQ("bla", *(a2.data()));
}

TEST(Array, IteratorBegin) {
  s21::array<int, 3> a1{1, 2, 3};
  EXPECT_EQ(&a1[0], a1.begin());
  const s21::array<std::string, 2> a2{"abc", "bla"};
  EXPECT_EQ(&a2[0], a2.begin());
}

TEST(Array, IteratorEnd) {
  const s21::array<std::string, 3> a1{"1", "2", "3"};
  EXPECT_EQ(&a1[2], a1.end() - 1);
  s21::array<int, 2> a2{100, 200};
  EXPECT_EQ(&a2[1], a2.end() - 1);
}

TEST(Array, Empty) {
  s21::array<int, 0> a1;
  s21::array<int, 2> a2;
  EXPECT_TRUE(a1.empty());
  EXPECT_FALSE(a2.empty());
}

TEST(Array, Size) {
  s21::array<std::string, 0> a1;
  s21::array<std::string, 2> a2{"bla", "blaaaaaaaaaa"};
  EXPECT_EQ(a1.size(), 0);
  EXPECT_EQ(a1.max_size(), 0);
  EXPECT_EQ(a2.size(), 2);
  EXPECT_EQ(a2.max_size(), 2);
}

TEST(Array, Swap) {
  s21::array<std::string, 2> a1{"hello", "bye"};
  s21::array<std::string, 2> a2{"bla", "blaa"};
  a1.swap(a2);
  EXPECT_EQ(a1[0], "bla");
  EXPECT_EQ(a1[1], "blaa");
  EXPECT_EQ(a2[0], "hello");
  EXPECT_EQ(a2[1], "bye");
}

TEST(Array, Fill) {
  s21::array<int, 3> a1;
  a1.fill(100);
  for (auto elem : a1) {
    EXPECT_TRUE(elem == 100);
  }
}
