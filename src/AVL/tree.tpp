#ifndef CPP2_S21_CONTAINERS_SRC_AVL_TREE_TPP_
#define CPP2_S21_CONTAINERS_SRC_AVL_TREE_TPP_

namespace s21 {

// Rule of five

// Default constructor
template <typename T, typename V>
AVLTree<T, V>::AVLTree() noexcept : root_(nullptr), nil_(nullptr) {}

// Copy constructor
template <typename T, typename V>
AVLTree<T, V>::AVLTree(const AVLTree& other) noexcept {
  if (this != &other) {
    root_ = copyTree(other.getRoot());  // Copy the tree rooted at 'other'
  }
}

// move constructor
template <typename T, typename V>
AVLTree<T, V>::AVLTree(AVLTree&& other) noexcept
    : root_(other.root_), nil_(other.nil_), add_(other.add_) {
  other.root_ = nullptr;
  other.root_ = nullptr;
  other.add_ = nullptr;
}

template <typename T, typename V>
AVLTree<T, V>& AVLTree<T, V>::operator=(AVLTree&& other) noexcept {
  if (this != &other) {
    clear(root_);
    root_ = exchange(other.root_, nullptr);
    nil_ = other.nil_;
  }
  return *this;
}

// Copy operator
template <typename T, typename V>
AVLTree<T, V>& AVLTree<T, V>::operator=(const AVLTree& other) noexcept {
  if (this != &other) {
    clear(root_);                       // Clear the current tree before copying
    root_ = copyTree(other.getRoot());  // Copy the tree rooted at 'other'
  }
  return *this;
}

// Destructor
template <typename T, typename V>
AVLTree<T, V>::~AVLTree() noexcept {
  clear(root_);  // Clear the tree upon destruction
}

// Main methods

// Returns Node if key is found, nullptr if not
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::search(T key) const noexcept {
  return searchRecursive(root_, key);  // Recursively search for the key
}

template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::searchMap(T key) const noexcept {
  return searchRecursiveMap(root_, key);  // Recursively search for the key
}

// Helping methods

// Returns the root of the tree
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::getRoot() const noexcept {
  return root_;
}

// Returns the nil of the tree
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::getNil() const noexcept {
  return nil_;
}

// Sets a new root for the tree
template <typename T, typename V>
void AVLTree<T, V>::setRoot(Node<T, V>* newRoot) noexcept {
  root_ = newRoot;
  if (root_ != nullptr) {
    root_->parent = nullptr;
  }
}

// Swaps roots with another tree
template <typename T, typename V>
void AVLTree<T, V>::swapNodes(AVLTree<T, V>& other) noexcept {
  std::swap(root_, other.root_);
}

// Splices nodes from another container
template <typename T, typename V>
void AVLTree<T, V>::merge(AVLTree<T, V>& other) noexcept {
  for (auto it = other.begin(); it != other.end();) {
    Node<T, V>* insertedNode = insert(*it);
    if (insertedNode != nullptr) {
      auto itcop = it;
      it++;
      other.pop(itcop);
    } else {
      ++it;
    }
  }
}

// Splices nodes from another container
template <typename T, typename V>
void AVLTree<T, V>::fullMerge(AVLTree<T, V>& other) noexcept {
  for (auto& element : other) {
    insertMult(element);
  }
  other.clear(other.getRoot());
}

// Clears the tree and releases memory
template <typename T, typename V>
void AVLTree<T, V>::clear(Node<T, V>* node) noexcept {
  if (node != nullptr) {
    clear(node->left);   // Recursively clear the left subtree
    clear(node->right);  // Recursively clear the right subtree
    delete node;         // Delete the node
  }
  root_ = nullptr;
}

// Getters

// Returns the node with the minimum key value
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::getMin(Node<T, V>* node) const noexcept {
  if (node->left == nullptr) return node;
  return getMin(node->left);  // Recursively find the minimum node
}

// Returns the node with the maximum key value
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::getMax(Node<T, V>* node) const noexcept {
  if (node->right == nullptr) return node;
  return getMax(node->right);  // Recursively find the maximum node
}

// Returns the size of the node (number of nodes in its subtree)
template <typename T, typename V>
int AVLTree<T, V>::getSize(Node<T, V>* node) const noexcept {
  if (node != nullptr) {
    if (node->left == nullptr && node->right == nullptr) node->size_ = 1;
    return node->size_;
  }
  return 0;
}

// Iterators (begin, end)

template <typename T, typename V>
typename AVLTree<T, V>::iterator AVLTree<T, V>::begin() noexcept {
  if (root_ == nullptr) {
    return iterator(nil_, nil_);
  }
  Node<T, V>* min_node = getMin(root_);
  return iterator(min_node, nil_);
}

template <typename T, typename V>
typename AVLTree<T, V>::iterator AVLTree<T, V>::end() noexcept {
  if (root_ == nullptr) {
    return iterator(nil_, nil_);
  }
  Node<T, V>* max_node = getMax(root_);
  return iterator(max_node->right);
}

template <typename T, typename V>
typename AVLTree<T, V>::const_iterator AVLTree<T, V>::begin() const noexcept {
  if (root_ == nullptr) {
    return const_iterator(nil_, nil_);
  }
  Node<T, V>* min_node = getMin(root_);
  return const_iterator(min_node, nil_);
}

template <typename T, typename V>
typename AVLTree<T, V>::const_iterator AVLTree<T, V>::end() const noexcept {
  if (root_ == nullptr) {
    return iterator(nil_, nil_);
  }
  Node<T, V>* max_node = getMax(root_);
  return const_iterator(max_node->right);
}

// Copy constructor helper

// Recursively copies the tree and returns the new root node
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::copyTree(Node<T, V>* node) noexcept {
  if (node == nullptr) {
    return nullptr;
  }
  Node<T, V>* new_node = new Node<T, V>(node->key);
  new_node->size_ = node->size_;
  new_node->left = copyTree(node->left);  // Recursively copy the left subtree
  new_node->right =
      copyTree(node->right);  // Recursively copy the right subtree
  new_node->parent = node->parent;
  return new_node;
}

// Balancing methods

// Balances the tree and returns the new root node
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::balance(Node<T, V>* node) noexcept {
  updateHeight(node);
  if (getBalanceFactor(node) == 2) {
    if (getBalanceFactor(node->right) < 0) {
      node->left = leftRotate(node->left);
      updateSize(node->left);
    }
    node = rightRotate(node);
    updateSize(node);
  }
  if (getBalanceFactor(node) == -2) {
    if (getBalanceFactor(node->left) > 0) {
      node->right = rightRotate(node->right);
      updateSize(node->right);
    }
    node = leftRotate(node);
    updateSize(node);
  }
  updateSize(node);
  return node;
}

// Updates the height of the node based on its children's heights
template <typename T, typename V>
void AVLTree<T, V>::updateHeight(Node<T, V>* node) noexcept {
  int hl = getHeight(node->left);
  int hr = getHeight(node->right);
  node->height_ = (hl > hr ? hl : hr) + 1;
}

// Returns the height of the node (height of the longest subtree + 1)
template <typename T, typename V>
int AVLTree<T, V>::getHeight(Node<T, V>* node) const noexcept {
  if (node == nullptr) return 0;
  return node->height_;
}

// Returns the balance factor of the node (difference in heights of left and
// right subtrees)
template <typename T, typename V>
int AVLTree<T, V>::getBalanceFactor(Node<T, V>* node) const noexcept {
  if (node == nullptr) return 0;
  return (getHeight(node->left) - getHeight(node->right));
}

// Left rotation for the tree
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::leftRotate(Node<T, V>* node) noexcept {
  Node<T, V>* buffer = node->right;
  if (buffer) {
    node->right = buffer->left;
    if (buffer->left != nullptr) buffer->left->parent = node;
    buffer->left = node;
    buffer->parent = node->parent;
    node->parent = buffer;
    updateHeight(node);
    updateHeight(buffer);
    return buffer;
  }
  return node;
}

// Right rotation for the tree
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::rightRotate(Node<T, V>* node) noexcept {
  Node<T, V>* buffer = node->left;
  if (buffer) {
    node->left = buffer->right;
    if (buffer->right != nullptr) buffer->right->parent = node;
    buffer->right = node;
    buffer->parent = node->parent;
    node->parent = buffer;
    updateHeight(buffer);
    updateHeight(node);
    return buffer;
  }
  return node;
}

// Update the size of the node and its children
template <typename T, typename V>
void AVLTree<T, V>::updateSize(Node<T, V>* node) noexcept {
  if (node != nullptr) {
    updateSize(node->left);
    updateSize(node->right);
    node->size_ = 1 + getSize(node->left) + getSize(node->right);
  }
}

// Main helping methods

// Helper method for searching a key in the tree
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::searchRecursive(Node<T, V>* node,
                                           T key) const noexcept {
  if (node == nullptr || node->key == key) return node;
  if (key < node->key) return searchRecursive(node->left, key);
  return searchRecursive(node->right, key);
}

// Helper method for searching a key in the tree
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::searchRecursiveMap(Node<T, V>* node,
                                              T key) const noexcept {
  if (node == nullptr || node->key.first == key.first) return node;
  if (key.first < node->key.first) return searchRecursiveMap(node->left, key);
  return searchRecursive(node->right, key);
}

// Iterators

// Rule of FIve

template <typename T, typename V>
Iterator<T, V>::Iterator() noexcept : current_(nullptr), nil_(nullptr) {}

template <typename T, typename V>
Iterator<T, V>::Iterator(Node<T, V>* node) noexcept
    : current_(node), nil_(nullptr) {}

template <typename T, typename V>
Iterator<T, V>::Iterator(Node<T, V>* nil, Node<T, V>* root) noexcept
    : current_(nil), nil_(root) {}

template <typename T, typename V>
Iterator<T, V>::Iterator(const Iterator& other) noexcept
    : current_(other.current_), nil_(other.nil_) {}

template <typename T, typename V>
Iterator<T, V>& Iterator<T, V>::operator=(const Iterator& other) noexcept {
  if (this != &other) {
    current_ = other.current_;
    nil_ = other.nil_;
  }
  return *this;
}

template <typename T, typename V>
Iterator<T, V>& Iterator<T, V>::operator=(Iterator&& other) noexcept {
  if (this != &other) {
    current_ = other.current_;
    nil_ = other.nil_;
    other.current_ = nullptr;
    other.nil_ = nullptr;
  }
  return *this;
}

// Operators

template <typename T, typename V>
Iterator<T, V>& Iterator<T, V>::operator+(const size_t range) noexcept {
  Iterator* tmp = this;
  for (size_t i = 0; i < range; i++, ++tmp) {
  }
  return *tmp;
}

template <typename T, typename V>
Iterator<T, V>& Iterator<T, V>::operator++() noexcept {
  if (current_ != nullptr) {
    // If the current node has a right subtree, move to the leftmost node in
    // that subtree
    if (current_->right != nullptr) {
      current_ = current_->right;
      while (current_->left != nullptr) {
        current_ = current_->left;
      }
    } else {
      // Otherwise, go up the tree until we find the first node whose left child
      // is an ancestor of the current node
      while (current_->parent != nullptr &&
             current_->parent->right == current_) {
        current_ = current_->parent;
      }
      current_ = current_->parent;
    }
  }
  return *this;
}

template <typename T, typename V>
Iterator<T, V> Iterator<T, V>::operator++(int) noexcept {
  Iterator<T, V> tmp = *this;
  ++(*this);
  return tmp;
}

template <typename T, typename V>
Iterator<T, V>& Iterator<T, V>::operator--() noexcept {
  if (current_ != nullptr) {
    if (current_->left != nil_) {
      // If the current node has a left subtree,
      // move to the rightmost node in that subtree
      current_ = current_->left;
      while (current_->right != nil_) {
        current_ = current_->right;
      }
    } else {
      // If the current node doesn't have a left subtree,
      // move up the tree until we find the first node
      // whose right child is an ancestor of the current node
      while (current_->parent != nullptr &&
             current_->parent->left == current_) {
        current_ = current_->parent;
      }
      // Move to the parent of the current node
      current_ = current_->parent;
    }
  }
  return *this;
}

template <typename T, typename V>
Iterator<T, V> Iterator<T, V>::operator--(int) noexcept {
  Iterator<T, V> tmp = *this;
  --(*this);
  return tmp;
}

template <typename T, typename V>
bool Iterator<T, V>::operator==(const Iterator& other) const noexcept {
  return current_ == other.current_;
}

template <typename T, typename V>
bool Iterator<T, V>::operator!=(const Iterator& other) const noexcept {
  return current_ != other.current_;
}

template <typename T, typename V>
typename Iterator<T, V>::reference Iterator<T, V>::operator*() const noexcept {
  return current_->key;
}

template <typename T, typename V>
typename Iterator<T, V>::pointer Iterator<T, V>::operator->() const noexcept {
  if (current_ == nullptr) {
    return nullptr;
  }
  return &(current_->key);
}

// Inserts a key into the tree
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::insert(T key) {
  root_ = insertRecursive(root_, key,
                          nullptr);  // Insert and balance the tree
  return add_;
}

// Helper method for inserting a key into the tree
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::insertRecursive(Node<T, V>* node, T key,
                                           Node<T, V>* p) {
  if (node == nullptr) {
    node = new Node<T, V>(key, p);
    add_ = node;
    return balance(node);
  }
  if (key < node->key) {
    node->left = insertRecursive(node->left, key, node);
  } else if (key > node->key) {
    node->right = insertRecursive(node->right, key, node);
  } else {
    add_ = nullptr;
  }
  return balance(node);
}

template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::insertMult(T key) {
  root_ = insertRecursiveMult(root_, key,
                              nullptr);  // Insert and balance the tree
  return add_;
}
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::insertRecursiveMult(Node<T, V>* node, T key,
                                               Node<T, V>* p) {
  if (node == nullptr) {
    node = new Node<T, V>(key, p);
    add_ = node;
    return balance(node);
  }
  if (key <= node->key) {
    node->left = insertRecursiveMult(node->left, key, node);
  } else if (key > node->key) {
    node->right = insertRecursiveMult(node->right, key, node);
  }
  return balance(node);
}

// Deletes a node with the given key if it exists
template <typename T, typename V>
void AVLTree<T, V>::pop(iterator key) noexcept {
  if (key != nullptr && this->search(*key) != nullptr)
    root_ = deleteRecursive(root_, key);  // Delete and balance the tree
}

// Deletes Node with minimum value
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::deleteMin(Node<T, V>* node) {
  if (node->left == nullptr) return node->right;
  node->left = deleteMin(node->left);
  return balance(node);
}

// Helper method for deleting a node with the given key from the tree
template <typename T, typename V>
Node<T, V>* AVLTree<T, V>::deleteRecursive(Node<T, V>* node,
                                           iterator key) noexcept {
  if (node == nullptr) return nullptr;
  if ((*key) < node->key || ((*key) == node->key && key.getCurrent() != node)) {
    node->left = deleteRecursive(node->left, key);
    if (node->left != nullptr) node->left->parent = node;
  } else if ((*key) > node->key ||
             ((*key) == node->key && key.getCurrent() != node)) {
    node->right = deleteRecursive(node->right, key);
    if (node->right != nullptr) node->right->parent = node;
  } else {
    Node<T, V>* left = node->left;
    Node<T, V>* right = node->right;
    delete node;
    if (right == nullptr) return left;
    if (left == nullptr) return right;
    Node<T, V>* tmp = getMin(right);
    tmp->right = deleteMin(right);
    tmp->left = left;
    tmp->parent = node->parent;
    return balance(tmp);
  }
  updateSize(node);
  return node;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_AVL_TREE_TPP_
