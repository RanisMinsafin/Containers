#ifndef CPP2_S21_CONTAINERS_SRC_AVL_TREE_H_
#define CPP2_S21_CONTAINERS_SRC_AVL_TREE_H_

#include <initializer_list>
// #include <iostream>
#include <cstddef>
#include <memory>
#include <utility>

namespace s21 {

template <typename T, typename V>
class Node {
 public:
  mutable T key;
  int height_;
  size_t size_;
  Node<T, V>* left;
  Node<T, V>* right;
  Node<T, V>* parent;

  Node(const T& k, Node* p = nullptr)
      : key(k),
        height_(1),
        size_(1),
        left(nullptr),
        right(nullptr),
        parent(p) {}
};

template <typename T, typename V>
class Iterator {
 public:
  using key_type = T;
  using reference = T&;
  using const_reference = const reference;
  using pointer = T*;

  //  Rule of five
  Iterator() noexcept;
  Iterator(Node<T, V>* node) noexcept;
  Iterator(Node<T, V>* nil, Node<T, V>* root) noexcept;
  Iterator(const Iterator&) noexcept;
  Iterator& operator=(const Iterator&) noexcept;
  Iterator& operator=(Iterator&&) noexcept;
  ~Iterator() = default;

  //  Operators
  Iterator& operator+(const size_t range) noexcept;
  Iterator& operator++() noexcept;
  Iterator operator++(int) noexcept;
  Iterator& operator--() noexcept;
  Iterator operator--(int) noexcept;
  bool operator==(const Iterator& other) const noexcept;
  bool operator!=(const Iterator& other) const noexcept;
  reference operator*() const noexcept;
  pointer operator->() const noexcept;
  Node<T, V>* getCurrent() const noexcept { return current_; };

 protected:
  Node<T, V>* current_;
  Node<T, V>* nil_;
};

template <typename T, typename V>
class ConstIterator : public Iterator<const T, const V> {
 public:
  using Iterator<const T, const V>::Iterator;

  using typename Iterator<const T, const V>::key_type;
  using typename Iterator<const T, const V>::reference;
  using typename Iterator<const T, const V>::const_reference;
  using typename Iterator<const T, const V>::pointer;
};

template <typename T, typename V>
class AVLTree {
 public:
  // Helping classes

  using iterator = Iterator<T, V>;
  using const_iterator = ConstIterator<T, V>;
  // using value_type = std::pair<const T, V>;

  // Rule of five

  AVLTree() noexcept;
  AVLTree(const AVLTree& other) noexcept;
  AVLTree(AVLTree&& other) noexcept;
  AVLTree<T, V>& operator=(AVLTree&& other) noexcept;
  AVLTree<T, V>& operator=(const AVLTree& other) noexcept;
  ~AVLTree() noexcept;

  // Main methods

  Node<T, V>* search(T key) const noexcept;
  Node<T, V>* searchMap(T key) const noexcept;
  Node<T, V>* insert(T key);
  Node<T, V>* insertMult(T key);
  void pop(iterator key) noexcept;

  // Helping methods

  Node<T, V>* getRoot() const noexcept;
  Node<T, V>* getNil() const noexcept;
  void setRoot(Node<T, V>* newRoot) noexcept;
  void swapNodes(AVLTree<T, V>& other) noexcept;
  void merge(AVLTree<T, V>& other) noexcept;
  void fullMerge(AVLTree<T, V>& other) noexcept;
  void clear(Node<T, V>* node) noexcept;

  // Getters

  Node<T, V>* getMin(Node<T, V>* node) const noexcept;
  Node<T, V>* getMax(Node<T, V>* node) const noexcept;
  int getSize(Node<T, V>* node) const noexcept;

  // Iterators (begin, end)

  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;

 private:
  // Attributes

  Node<T, V>* root_;
  Node<T, V>* nil_;
  Node<T, V>* add_ = nullptr;

  // Copy constructor helper
  Node<T, V>* copyTree(Node<T, V>* node) noexcept;

  // Balancing methods
  Node<T, V>* balance(Node<T, V>* node) noexcept;
  void updateHeight(Node<T, V>* node) noexcept;
  int getHeight(Node<T, V>* node) const noexcept;
  int getBalanceFactor(Node<T, V>* node) const noexcept;
  Node<T, V>* leftRotate(Node<T, V>* node) noexcept;
  Node<T, V>* rightRotate(Node<T, V>* node) noexcept;
  void updateSize(Node<T, V>* node) noexcept;

  // Main helping methods
  Node<T, V>* searchRecursive(Node<T, V>* node, T key) const noexcept;
  Node<T, V>* searchRecursiveMap(Node<T, V>* node, T key) const noexcept;
  Node<T, V>* insertRecursive(Node<T, V>* node, T key, Node<T, V>* p);
  Node<T, V>* insertRecursiveMult(Node<T, V>* node, T key, Node<T, V>* p);
  Node<T, V>* deleteRecursive(Node<T, V>* node, iterator key) noexcept;
  Node<T, V>* deleteMin(Node<T, V>* node);
};

}  // namespace s21

#include "tree.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_AVL_TREE_H_
