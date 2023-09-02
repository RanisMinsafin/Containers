#ifndef CPP2_S21_CONTAINERS_SRC_STACK_S21_STACK_TPP_
#define CPP2_S21_CONTAINERS_SRC_STACK_S21_STACK_TPP_

namespace s21 {

// Default constructor, creates empty stack
template <typename value_type>
stack<value_type>::stack() : list_() {}

// Initializer list constructor, creates stack initizialized using
// std::initializer_list
template <typename value_type>
stack<value_type>::stack(std::initializer_list<value_type> const& items) {
  for (value_type item : items) {
    push(item);
  }
}

// Copy constructor
template <typename value_type>
stack<value_type>::stack(const stack& s) : list_(s.list_) {}

// Move constructor
template <typename value_type>
stack<value_type>::stack(stack&& s) : list_(std::move(s.list_)) {}

// Destructor
template <typename value_type>
stack<value_type>::~stack() {}

// Assignment operator overload for moving object
template <typename value_type>
stack<value_type>& stack<value_type>::operator=(stack<value_type>&& s) {
  list_ = std::move(s.list_);
  return *this;
}

// Accesses the top element
template <typename value_type>
const value_type& stack<value_type>::top() {
  return list_.front();
}

// Checks whether the container is empty
template <typename value_type>
bool stack<value_type>::empty() {
  return list_.empty();
}

// Returns the number of elements
template <typename value_type>
size_t stack<value_type>::size() {
  return list_.size();
}

// Inserts element at the top
template <typename value_type>
void stack<value_type>::push(const_reference value) {
  list_.push_front(value);
}

// Removes the top element
template <typename value_type>
void stack<value_type>::pop() {
  if (empty()) {
    throw std::out_of_range("Error: Stack is empty");
  }
  list_.pop_front();
}

// Swaps the contents
template <typename value_type>
void stack<value_type>::swap(stack<value_type>& other) {
  list_.swap(other.list_);
}

// Appends new elements to the top of the stack
template <typename value_type>
template <class... Args>
void stack<value_type>::insert_many_front(Args&&... args) {
  list_.insert_many_front(args...);
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_STACK_S21_STACK_TPP_
