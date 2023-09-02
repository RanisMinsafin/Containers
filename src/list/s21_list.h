#ifndef CPP2_S21_CONTAINERS_SRC_LIST_S21_LIST_H_
#define CPP2_S21_CONTAINERS_SRC_LIST_S21_LIST_H_

#include <initializer_list>

namespace s21 {
template <typename T>
class list {
 public:
  using value_type = T;
  using reference = T&;
  using pointer = T*;
  using const_reference = const T&;
  using size_type = std::size_t;

 private:
  struct Node {
    Node* prev_;
    Node* next_;
    value_type value_;
    Node(value_type value) : prev_(nullptr), next_(nullptr), value_(value) {}
  };

 public:
  // List Constructors
  list();
  list(size_type count);
  list(std::initializer_list<value_type> const& items);
  list(const list& other);
  list(list&& other);

  // Move assignment operator
  list& operator=(list&& other);

  // List Destructor
  ~list();

  // List Element access
  const_reference front();
  const_reference back();

  // List Capacity
  bool empty();
  size_type size() const;
  size_type max_size();

  // Iterator class
  template <typename value_type>
  class ListIterator {
   public:
    // ListIterator Constructors
    ListIterator() : node_(nullptr) {}
    explicit ListIterator(Node* node) : node_(node) {}

    // Dereference operators
    reference operator*() const { return node_->value_; }
    pointer operator->() const { return &(node_->value_); }

    // Comparison operators
    bool operator==(const ListIterator& other) const {
      return node_ == other.node_;
    }

    bool operator!=(const ListIterator& other) const {
      return node_ != other.node_;
    }

    bool operator==(std::nullptr_t) const { return node_ == nullptr; }

    bool operator!=(std::nullptr_t) const { return node_ != nullptr; }

    // Iterator movement operators

    // Prefix increment
    ListIterator& operator++() {
      if (node_) {
        node_ = node_->next_;
      }
      return *this;
    }

    // Prefix decrement
    ListIterator& operator--() {
      if (node_) {
        node_ = node_->prev_;
      }
      return *this;
    }

    // Postfix increment
    ListIterator operator++(int) {
      ListIterator tmp = *this;
      ++(*this);
      return tmp;
    }

    // Postfix decrement
    ListIterator operator--(int) {
      ListIterator tmp = *this;
      --(*this);
      return tmp;
    }

    // Adds number to the iterator
    ListIterator operator+(const size_type count) {
      ListIterator result = *this;
      for (size_type i = count; i > 0; i--) {
        ++result;
      }
      return result;
    }

    // Subtracts number to the iterator
    ListIterator operator-(const size_type count) {
      ListIterator result = *this;
      for (size_type i = count; i > 0; i--) {
        --result;
      }
      return result;
    }

    // Addition assignment
    ListIterator operator+=(const size_type count) {
      for (size_type i = count; i > 0; i--) {
        ++(*this);
      }
      return *this;
    }

    // Difference assignment
    ListIterator operator-=(const size_type count) {
      for (size_type i = count; i > 0; i--) {
        --(*this);
      }
      return *this;
    }

   private:
    Node* node_;
    list<value_type>* list_;
    friend class list<value_type>;
  };

  // Const iterator class
  template <typename value_type>
  class ListConstIterator {
   public:
    // ListConstIterator Constructors
    ListConstIterator() : node_(nullptr) {}
    explicit ListConstIterator(const Node* node) : node_(node) {}

   private:
    const Node* node_;
    friend class list<value_type>;
  };

  // List Member type
  using iterator = ListIterator<value_type>;
  using const_iterator = ListConstIterator<value_type>;

  // List Iterators
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

  // List Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list& other);
  void merge(list& other);
  void splice(const_iterator pos, list& other);
  void splice(iterator pos, list& other);
  void reverse();
  void unique();
  void sort();

  // Bonus List Modifiers
  template <class... Args>
  iterator insert_many(iterator pos, Args&&... args);
  template <class... Args>
  void insert_many_back(Args&&... args);
  template <class... Args>
  void insert_many_front(Args&&... args);

 private:
  Node* end_;
  Node* head_;
  Node* tail_;
  size_type size_;

  void move_other(list& other);
  void splice_helper(iterator pos, list& other);
  void insert_many_helper(iterator pos, list& insert_list);
};

}  // namespace s21

#include "s21_list.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_LIST_S21_LIST_H_
