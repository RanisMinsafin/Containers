#ifndef CPP2_S21_CONTAINERS_SRC_SET_S21_SET_TPP_
#define CPP2_S21_CONTAINERS_SRC_SET_S21_SET_TPP_

namespace s21 {

// set Member functions (Rule of Five)

// Default Constructor
template <typename T>
set<T>::set() noexcept {}

// Inititalizer List Constrtuctor
template <typename T>
set<T>::set(std::initializer_list<T> const& items) {
  for (const auto& item : items) {
    tree_.insert(item);
  }
}

// Copy Constuctor
template <typename T>
set<T>::set(const set& other) noexcept : tree_(other.tree_) {}

// Move Constructor
template <typename T>
set<T>::set(set&& other) noexcept : tree_(std::move(other.tree_)) {}

// Destructor
template <typename T>
set<T>::~set() noexcept {}

// Assignment Move Constructor
template <typename T>
set<T>& set<T>::operator=(set&& other) noexcept {
  tree_ = std::move(other.tree_);
  return *this;
}

// Assignment Copy Constructor
template <typename T>
set<T>& set<T>::operator=(const set& other) noexcept {
  tree_ = other.tree_;
  return *this;
}

// set Iterators

// returns an iterator to the beginning
template <typename T>
typename set<T>::iterator set<T>::begin() noexcept {
  return tree_.begin();
}

// returns an iterator to the end
template <typename T>
typename set<T>::iterator set<T>::end() noexcept {
  return tree_.end();
}

// returns a const iterator to the begin
template <typename T>
typename set<T>::const_iterator set<T>::begin() const noexcept {
  return tree_.begin();
}

// returns a const iterator to the end
template <typename T>
typename set<T>::const_iterator set<T>::end() const noexcept {
  return tree_.end();
}

// set Capacity

// checks whether the container is empty
template <typename T>
bool set<T>::empty() const noexcept {
  return tree_.getRoot() == nullptr;
}

// returns the number of elements
template <typename T>
typename set<T>::size_type set<T>::size() const noexcept {
  if (tree_.getRoot() == nullptr) return 0;
  return tree_.getSize(tree_.getRoot());
}

// returns the maximum possible number of elements
template <typename T>
typename set<T>::size_type set<T>::max_size() const noexcept {
  return allocator.max_size();
}

//  set Modifiers

// clears the contents
template <typename T>
void set<T>::clear() noexcept {
  tree_.clear(tree_.getRoot());
}

// inserts node and returns iterator to where the element is in the container
// and bool denoting whether the insertion took place
template <typename T>
std::pair<typename set<T>::iterator, bool> set<T>::insert(
    const T& value) noexcept {
  Node<T, T>* insertedNode = tree_.insert(value);
  if (insertedNode != nullptr) {
    // If insertion took place, return an iterator to the inserted node and
    // 'true'
    return std::make_pair(iterator(insertedNode), true);
  } else {
    // If insertion did not take place (element already exists),
    // return an iterator to the existing node and 'false'
    Node<T, T>* existingNode = tree_.search(value);
    return std::make_pair(iterator(existingNode), false);
  }
}

// erases element at pos
template <typename T>
void set<T>::erase(iterator pos) noexcept {
  tree_.pop(pos);
}

// swaps the contents
template <typename T>
void set<T>::swap(set& other) noexcept {
  tree_.swapNodes(other.tree_);
}

// splices nodes from another container
template <typename T>
void set<T>::merge(set& other) noexcept {
  tree_.merge(other.tree_);
}

template <typename T>
template <typename... Args>
std::vector<std::pair<typename set<T>::iterator, bool>> set<T>::insert_many(
    Args&&... args) {
  std::vector<std::pair<iterator, bool>> results;
  iterator ret = nullptr;
  for (auto& i : {std::forward<Args>(args)...}) {
    results.push_back(insert(i));
  }
  return results;
}

//  set Lookup

// finds element with specific key
template <typename T>
typename set<T>::iterator set<T>::find(const T& value) noexcept {
  return iterator(tree_.search(value));
}

// finds element with specific key
template <typename T>
typename set<T>::const_iterator set<T>::find(const T& value) const noexcept {
  return const_iterator(tree_.search(value));
}

// checks if the container contains element with specific key
template <typename T>
bool set<T>::contains(const T& value) const noexcept {
  return tree_.search(value) != nullptr;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_SET_S21_S21_SET_TPP_
