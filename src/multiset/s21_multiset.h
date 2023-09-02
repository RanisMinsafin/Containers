#ifndef CPP2_S21_CONTAINERS_SRC_MULTISET_S21_MULTISET_H_
#define CPP2_S21_CONTAINERS_SRC_MULTISET_S21_MULTISET_H_

#include "../AVL/tree.h"

namespace s21 {

template <typename Key>
class multiset {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = Key&;
  using const_reference = const Key&;
  using iterator = typename AVLTree<Key, int>::iterator;
  using const_iterator = typename AVLTree<Key, int>::const_iterator;
  using Allocator = std::allocator<Key>;
  using size_type = size_t;

  multiset() noexcept;
  multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset& ms) noexcept : tree_(ms.tree_){};
  multiset(multiset&& ms) noexcept : tree_(std::move(ms.tree_)){};
  ~multiset() noexcept {};
  multiset& operator=(multiset&& ms) noexcept;
  multiset& operator=(const multiset& ms) noexcept;

  // MultiSet Iterators
  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;

  // MultiSet Capacity
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  // MultiSet Modifiers
  void clear() noexcept;
  iterator insert(const value_type& value) noexcept;
  void erase(iterator pos) noexcept;
  void swap(multiset& other) noexcept;
  void merge(multiset& other) noexcept;

  // MultiSet Lookup
  size_type count(const Key& key);
  iterator find(const Key& value);
  const_iterator find(const Key& value) const;
  bool contains(const Key& value) const noexcept;
  std::pair<iterator, iterator> equal_range(const Key& key);
  iterator lower_bound(const Key& key);
  iterator upper_bound(const Key& key);

  // Part 3
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

 private:
  AVLTree<Key, int> tree_;
  Allocator allocator;
};

}  // namespace s21

#include "s21_multiset.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_MULTISET_S21_MULTISET_H_
