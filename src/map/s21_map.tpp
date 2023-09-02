#ifndef CPP2_S21_CONTAINERS_SRC_MAP_S21_MAP_TPP_
#define CPP2_S21_CONTAINERS_SRC_MAP_S21_MAP_TPP_

namespace s21 {
// Default constructor
template <typename Key, typename T>
map<Key, T>::map() : tree_() {}

// Initializer list constructor, creates the map initizialized using
// std::initializer_list
template <typename Key, typename T>
map<Key, T>::map(std::initializer_list<value_type> const& items) {
  for (const auto& item : items) {
    insert(item);
  }
}

// Copy constructor
template <typename Key, typename T>
map<Key, T>::map(const map& other) : tree_(other.tree_) {}

// Move constructor
template <typename Key, typename T>
map<Key, T>::map(map&& other) : tree_(std::move(other.tree_)) {}

// Assignment Move Constructor
template <typename Key, typename T>
map<Key, T>& map<Key, T>::operator=(map&& other) {
  if (this != &other) {
    tree_ = std::move(other.tree_);
  }
  return *this;
}

// Assignment Copy Constructor
template <typename Key, typename T>
map<Key, T>& map<Key, T>::operator=(const map& other) {
  if (this != &other) {
    clear();
    tree_.root_ = copyTree(other.root_);
  }
  return *this;
}

// Destructor
template <typename Key, typename T>
map<Key, T>::~map() {}

template <typename Key, typename T>
T& map<Key, T>::findKey(const Key& key, int method) {
  if (begin() != nullptr) {
    for (auto it = begin(); it != end(); it++) {
      if (it->first == key) {
        return it->second;
      }
    }
  }
  if (!method) {
    throw std::runtime_error("Key not found");
  }
  auto result = insert(value_type(key, T()));
  return result.first->second;
}

// Access specified element with bounds checking
template <typename Key, typename T>
T& map<Key, T>::at(const Key& key) {
  return findKey(key, 0);
}

// Access or insert specified element
template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  return findKey(key, 1);
}

// Returns an iterator to the beginning
template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::begin() {
  // return iterator(tree_.getMin(tree_.getRoot()), tree_.getNil());
  return tree_.begin();
}

template <typename Key, typename T>
typename map<Key, T>::const_iterator map<Key, T>::begin() const {
  // return const_iterator(tree_.getMin(tree_.getRoot()), tree_.getNil());
  return tree_.begin();
}

// Returns an iterator to the end
template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::end() {
  // return iterator(tree_.getNil(), tree_.getNil());
  return tree_.end();
}

template <typename Key, typename T>
typename map<Key, T>::const_iterator map<Key, T>::end() const {
  return tree_.end();
}

// Checks whether the container is empty
template <typename Key, typename T>
bool map<Key, T>::empty() const {
  return tree_.getRoot() == nullptr;
}

// Returns the number of elements
template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::size() const {
  return tree_.getSize(tree_.getRoot());
}

// Returns the maximum possible number of elements
template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::max_size() const {
  return allocator.max_size();
}

// Clears the contents
template <typename Key, typename T>
void map<Key, T>::clear() {
  tree_.clear(tree_.getRoot());
}

// // // Inserts node and returns iterator to where the element is in the
// container
// // // and bool denoting whether the insertion took place
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type& value) {
  // return insert_helper(value.first, value.second);
  auto it = tree_.searchMap(value);
  if (it == nullptr) {
    it = tree_.insert(value);
    return std::make_pair(iterator(it), true);
  } else {
    return std::make_pair(iterator(it), false);
  }
}

// // Inserts value by key and returns iterator to where the element is in the
// // container and bool denoting whether the insertion took place
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key& key, const T& obj) {
  return insert({key, obj});
}

// Inserts an element or assigns to the current element if the key already
// exists
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key& key, const T& obj) {
  // auto result = insert_helper(key, obj);
  auto it = tree_.searchMap({key, obj});
  if (it == nullptr) {
    it = tree_.insert({key, obj});
    return std::make_pair(iterator(it), true);
  }
  it->key.second = obj;
  return std::make_pair(iterator(it), false);
}

// Erases element at pos
template <typename Key, typename T>
void map<Key, T>::erase(iterator pos) {
  tree_.pop(pos);
}

// Swaps the contents
template <typename Key, typename T>
void map<Key, T>::swap(map& other) {
  tree_.swapNodes(other.tree_);
}

// Splices nodes from another container
template <typename Key, typename T>
void map<Key, T>::merge(map& other) {
  auto it_cop = other.begin();
  std::pair<Key, T> value;
  for (auto it = it_cop; it != other.end();) {
    if (tree_.searchMap({it->first, it->second})) {
      it++;
    } else {
      it_cop = it;
      it++;
      tree_.insert({it_cop->first, it_cop->second});
      other.erase(it_cop);
    }
  }
}

// Checks if there is an element with key equivalent to key in the container
template <typename Key, typename T>
bool map<Key, T>::contains(const Key& key) {
  for (auto it = begin(); it != end(); it++) {
    if (it->first == key) {
      return true;
    }
  }
  return false;
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_MAP_S21_MAP_TPP_
