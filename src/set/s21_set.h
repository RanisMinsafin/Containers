#ifndef CPP2_S21_CONTAINERS_SRC_SET_S21_SET_H_
#define CPP2_S21_CONTAINERS_SRC_SET_S21_SET_H_

#include "../AVL/tree.h"

namespace s21 {

template <typename T>
class set {
 public:
  //  Member type
  using key_type = T;
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = typename AVLTree<T, T>::iterator;
  using const_iterator = typename AVLTree<T, T>::const_iterator;
  using Allocator = std::allocator<T>;
  using size_type = size_t;

  // set Member functions (Rule of Five)
  set() noexcept;
  set(std::initializer_list<T> const& items);
  set(const set& other) noexcept;
  set(set&& other) noexcept;
  set& operator=(const set& other) noexcept;
  set& operator=(set&& other) noexcept;
  ~set() noexcept;

  // set Iterators
  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;

  // set Capacity
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  // set Modifiers
  void clear() noexcept;
  std::pair<iterator, bool> insert(const T& value) noexcept;
  void erase(iterator pos) noexcept;
  void swap(set& other) noexcept;
  void merge(set& other) noexcept;
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

  // set Lookup
  iterator find(const T& value) noexcept;
  const_iterator find(const T& value) const noexcept;
  bool contains(const T& value) const noexcept;

 private:
  AVLTree<T, T> tree_;
  Allocator allocator;
};

}  // namespace s21

#include "s21_set.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_SET_S21_SET_H_
