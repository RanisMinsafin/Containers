#ifndef CPP2_S21_CONTAINERS_SRC_MULTISET_S21_MULTISET_TPP_
#define CPP2_S21_CONTAINERS_SRC_MULTISET_S21_MULTISET_TPP_

namespace s21 {

template <typename T>
multiset<T>::multiset() noexcept {}

template <typename T>
multiset<T>::multiset(std::initializer_list<T> const& items) {
  for (const auto& item : items) {
    tree_.insertMult(item);
  }
}

// Assignment Move Constructor   ERROR
template <typename T>
multiset<T>& multiset<T>::operator=(multiset&& ms) noexcept {
  this->tree_ = std::move(ms.tree_);
  return *this;
}

template <typename T>
multiset<T>& multiset<T>::operator=(const multiset& ms) noexcept {
  this->tree_ = ms.tree_;
  return *this;
}

// multiset Iterators

// returns an iterator to the beginning
template <typename T>
typename multiset<T>::iterator multiset<T>::begin() noexcept {
  return tree_.begin();
}

// returns an iterator to the end
template <typename T>
typename multiset<T>::iterator multiset<T>::end() noexcept {
  return tree_.end();
}

// returns a const iterator to the begin
template <typename T>
typename multiset<T>::const_iterator multiset<T>::begin() const noexcept {
  return tree_.begin();
}

// returns a const iterator to the end
template <typename T>
typename multiset<T>::const_iterator multiset<T>::end() const noexcept {
  return tree_.end();
}

// multiset Capacity

// checks whether the container is empty
template <typename T>
bool multiset<T>::empty() const noexcept {
  return tree_.getRoot() == nullptr;
}

// returns the number of elements
template <typename T>
typename multiset<T>::size_type multiset<T>::size() const noexcept {
  if (tree_.getRoot() == nullptr) return 0;
  return tree_.getSize(tree_.getRoot());
}

// returns the maximum possible number of elements
template <typename T>
typename multiset<T>::size_type multiset<T>::max_size() const noexcept {
  return allocator.max_size();
}

//  multiset Modifiers

// clears the contents
template <typename T>
void multiset<T>::clear() noexcept {
  tree_.clear(tree_.getRoot());
}

// inserts node and returns iterator to where the element is in the container
// and bool denoting whether the insertion took place
template <typename T>
typename multiset<T>::iterator multiset<T>::insert(const T& value) noexcept {
  return tree_.insertMult(value);
}

// erases element at pos
template <typename T>
void multiset<T>::erase(multiset<T>::iterator pos) noexcept {
  tree_.pop(pos);
}

// swaps the contents
template <typename T>
void multiset<T>::swap(multiset& other) noexcept {
  tree_.swapNodes(other.tree_);
}

//
template <typename T>
void multiset<T>::merge(multiset& other) noexcept {
  tree_.fullMerge(other.tree_);
}

// MultiSet Lookup

//
template <typename T>
size_t multiset<T>::count(const T& key) {
  size_t res = 0;
  for (auto i = begin(); i != end(); i++) {
    if ((*i) == key) res++;
  }
  return res;
}

// finds element with specific key
template <typename T>
typename multiset<T>::iterator multiset<T>::find(const T& value) {
  return iterator(tree_.search(value));
}

// finds element with specific key
template <typename T>
typename multiset<T>::const_iterator multiset<T>::find(const T& value) const {
  return const_iterator(tree_.search(value));
}

// checks if the container contains element with specific key
template <typename T>
bool multiset<T>::contains(const T& value) const noexcept {
  return tree_.search(value) != nullptr;
}

template <typename T>
std::pair<typename multiset<T>::iterator, typename multiset<T>::iterator>
multiset<T>::equal_range(const T& key) {
  auto it1 = lower_bound(key);
  auto it2 = upper_bound(key);

  return std::make_pair(it1, it2);
}

template <typename T>
typename multiset<T>::iterator multiset<T>::lower_bound(const T& key) {
  multiset<T>::iterator it = begin();
  while (it != end() && (*it) < key) {
    it++;
  }
  return it;
}

template <typename T>
typename multiset<T>::iterator multiset<T>::upper_bound(const T& key) {
  multiset<T>::iterator it = begin();
  while (it != end() && (*it) <= key) {
    it++;
  }
  return it;
}

template <typename T>
template <typename... Args>
std::vector<std::pair<typename multiset<T>::iterator, bool>>
multiset<T>::insert_many(Args&&... args) {
  std::vector<std::pair<iterator, bool>> results;
  multiset::iterator ret = nullptr;
  for (auto& i : {std::forward<Args>(args)...}) {
    ret = insert(i);
    results.push_back(std::pair(ret, true));
  }
  return results;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_MULTISET_S21_MULTISET_TPP_