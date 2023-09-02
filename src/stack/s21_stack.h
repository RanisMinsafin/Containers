#ifndef CPP2_S21_CONTAINERS_SRC_STACK_S21_STACK_H_
#define CPP2_S21_CONTAINERS_SRC_STACK_S21_STACK_H_

#include "../list/s21_list.h"

namespace s21 {
template <typename T>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // Stack Constructors
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);
  ~stack();
  stack &operator=(stack<value_type> &&s);

  // Stack Element access
  const_reference top();

  // Stack Capacity
  bool empty();
  size_type size();

  // Stack Modifiers
  void push(const_reference value);
  void pop();
  void swap(stack &other);

  // Bonus Stack Modifier
  template <class... Args>
  void insert_many_front(Args &&...args);

 private:
  s21::list<value_type> list_;
};

}  // namespace s21

#include "s21_stack.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_STACK_S21_STACK_H_
