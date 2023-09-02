#ifndef CPP2_S21_CONTAINERS_SRC_QUEUE_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_SRC_QUEUE_S21_QUEUE_H_

#include "../list/s21_list.h"

namespace s21 {
template <typename T>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // Queue Constructors
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();
  queue &operator=(queue<value_type> &&q);

  // Queue Element access
  const_reference front();
  const_reference back();

  // Queue Capacity
  bool empty();
  size_type size();

  // Queue Modifiers
  void push(const_reference value);
  void pop();
  void swap(queue &other);

  // Bonus Queue Modifier
  template <class... Args>
  void insert_many_back(Args &&...args);

 private:
  s21::list<value_type> list_;
};

}  // namespace s21

#include "s21_queue.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_QUEUE_S21_QUEUE_H_
