#ifndef CPP2_S21_CONTAINERS_SRC_QUEUE_S21_QUEUE_TPP_
#define CPP2_S21_CONTAINERS_SRC_QUEUE_S21_QUEUE_TPP_

namespace s21 {

// Default constructor, creates empty queue
template <typename value_type>
queue<value_type>::queue() : list_() {}

// Initializer list constructor, creates queue initizialized using
// std::initializer_list
template <typename value_type>
queue<value_type>::queue(std::initializer_list<value_type> const& items) {
  for (value_type item : items) {
    push(item);
  }
}

// Copy constructor
template <typename value_type>
queue<value_type>::queue(const queue& q) : list_(q.list_) {}

// Move constructor
template <typename value_type>
queue<value_type>::queue(queue&& q) : list_(std::move(q.list_)) {}

// Destructor
template <typename value_type>
queue<value_type>::~queue() {}

// Assignment operator overload for moving object
template <typename value_type>
queue<value_type>& queue<value_type>::operator=(queue<value_type>&& q) {
  list_ = std::move(q.list_);
  // swap(q);
  return *this;
}

// Access the first element
template <typename value_type>
const value_type& queue<value_type>::front() {
  return list_.front();
}

// Access the last element
template <typename value_type>
const value_type& queue<value_type>::back() {
  return list_.back();
}

// Checks whether the container is empty
template <typename value_type>
bool queue<value_type>::empty() {
  return list_.empty();
}

// Returns the number of elements
template <typename value_type>
size_t queue<value_type>::size() {
  return list_.size();
}

// Inserts element at the end
template <typename value_type>
void queue<value_type>::push(const_reference value) {
  list_.push_back(value);
}

// Removes the first element
template <typename value_type>
void queue<value_type>::pop() {
  if (empty()) {
    throw std::out_of_range("Error: Queue is empty");
  }
  list_.pop_front();
}

// Swaps the contents
template <typename value_type>
void queue<value_type>::swap(queue<value_type>& other) {
  list_.swap(other.list_);
}

// Appends new elements to the end of the queue
template <typename value_type>
template <class... Args>
void queue<value_type>::insert_many_back(Args&&... args) {
  list_.insert_many_back(args...);
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_QUEUE_S21_QUEUE_TPP_
