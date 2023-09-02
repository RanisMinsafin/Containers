#ifndef CPP2_S21_CONTAINERS_SRC_MAP_S21_MAP_H_
#define CPP2_S21_CONTAINERS_SRC_MAP_S21_MAP_H_

#include "../AVL/tree.h"

namespace s21 {
template <typename Key, typename T>
class map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Iterator<value_type, mapped_type>;
  using const_iterator = ConstIterator<value_type, mapped_type>;
  using size_type = size_t;
  using Allocator = std::allocator<value_type>;

  // Map Constructors
  map();
  map(std::initializer_list<value_type> const& items);
  map(const map& other);
  map(map&& other);
  map& operator=(map&& other);
  map& operator=(const map& other);

  // Map Destructor
  ~map();

  // Map Element access
  T& at(const Key& key);
  T& operator[](const Key& key);

  // Map Iterators
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

  // Map Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  // Map Modifiers
  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const Key& key, const T& obj);
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
  void erase(iterator pos);
  void swap(map& other);
  void merge(map& other);

  // Map Lookup
  bool contains(const Key& key);

 private:
  AVLTree<value_type, T> tree_;
  Allocator allocator;

  T& findKey(const Key& key, int method);
  std::pair<typename map<Key, T>::iterator, bool> insert_helper(const Key& key,
                                                                const T& obj);
};
}  // namespace s21

#include "s21_map.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_MAP_S21_MAP_H_
