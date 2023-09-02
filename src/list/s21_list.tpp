#ifndef CPP2_S21_CONTAINERS_SRC_LIST_S21_LIST_TPP_
#define CPP2_S21_CONTAINERS_SRC_LIST_S21_LIST_TPP_

namespace s21 {

// Default constructor, creates empty list 
template <typename value_type>
list<value_type>::list() : head_(nullptr), tail_(nullptr), size_(0) {
  end_ = new Node(value_type());
}

// Parameterized constructor, creates the list of size n
template <typename value_type>
list<value_type>::list(size_t count) : list() {
  if (count >= max_size()) {
    throw std::out_of_range("Error: List limit reached");
  }
  for (size_type i = 0; i < count; i++) {
    push_back(value_type());
  }
}

// Initializer list constructor
template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const& items)
    : list() {
  for (const auto& item : items) {
    push_back(item);
  }
}

// Copy constructor
template <typename value_type>
list<value_type>::list(const list& other) : list() {
  Node* current = other.head_;
  while (current != other.end_) {
    push_back(current->value_);
    current = current->next_;
  }
}

// Move constructor
template <typename value_type>
list<value_type>::list(list<value_type>&& other) {
  move_other(other);
}

// // Move constructor
// template <typename value_type>
// list<value_type>::list(list<value_type>&& other):  end_(other.end_),
// head_(other.head_), tail_(other.tail_), size_(other.size_){
//   other.size_ = 0;
//   other.end_ = nullptr;
//   other.head_ = nullptr;
//   other.tail_ = nullptr;

// }

// Assignment operator overload for moving object
template <typename value_type>
list<value_type>& list<value_type>::operator=(list<value_type>&& other) {
  if (this == &other) {
    return *this;
  }
  clear();
  swap(other);
  return *this;
}

// Destructor
template <typename value_type>
list<value_type>::~list() {
  clear();
  delete end_;
}

// Access the first element
template <typename value_type>
typename list<value_type>::const_reference list<value_type>::front() {
  if (empty()) {
    throw std::out_of_range("Error: List is empty");
  }
  return head_->value_;
}

// Access the last element
template <typename value_type>
typename list<value_type>::const_reference list<value_type>::back() {
  if (empty()) {
    throw std::out_of_range("Error: List is empty");
  }
  return tail_->value_;
}

// Checks whether the container is empty
template <typename value_type>
bool list<value_type>::empty() {
  return !size_;
}

// Returns the number of elements
template <typename value_type>
typename list<value_type>::size_type list<value_type>::size() const {
  return size_;
}

// Returns the maximum possible number of elements
template <typename value_type>
typename list<value_type>::size_type list<value_type>::max_size() {
  size_type node_size = sizeof(Node);

  size_type max_elements =
      std::numeric_limits<size_type>::max() / (node_size) / 2;
  return max_elements;
}

// Returns an iterator to the beginning
template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() {
  return head_ == nullptr ? iterator(end_) : iterator(head_);
}

// Returns a constant iterator to the beginning
template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::begin() const {
  return head_ == nullptr ? iterator(end_) : iterator(head_);
}

// Returns an iterator to the end
template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() {
  return iterator(end_);
}

// Returns a constant iterator to the end
template <typename value_type>
typename list<value_type>::const_iterator list<value_type>::end() const {
  return const_iterator(end_);
}

// Сlears the contents
template <typename value_type>
void list<value_type>::clear() {
  while (size_) {
    pop_back();
  }
  // end_ = nullptr;
  head_ = nullptr;
  tail_ = nullptr;
}

// Inserts element into concrete pos and returns the iterator that points to the
// new element
template <typename value_type>
typename list<value_type>::iterator list<value_type>::insert(
    iterator pos, const_reference value) {
  if (pos == begin()) {
    push_front(value);
  } else if (pos == end()) {
    push_back(value);
  } else {
    Node* new_node = new Node(value);
    new_node->next_ = pos.node_;
    new_node->prev_ = pos.node_->prev_;
    pos.node_->prev_->next_ = new_node;
    pos.node_->prev_ = new_node;
    pos.node_->next_->prev_ = pos.node_;
    size_++;
  }
  return pos;
}

// Erases element at pos
template <typename value_type>
void list<value_type>::erase(iterator pos) {
  if (empty()) {
    throw std::out_of_range("Error: List is empty");
  }

  if (pos != end()) {
    Node* tmp = pos.node_;
    if (tmp == head_) {
      head_ = tmp->next_;
    }
    if (tmp == tail_) {
      tail_ = tmp->prev_;
    }
    tmp->prev_->next_ = tmp->next_;
    tmp->next_->prev_ = tmp->prev_;

    delete tmp;
    --size_;
  } else {
    pop_back();
  }
}

// Adds an element to the end
template <typename value_type>
void list<value_type>::push_back(const_reference value) {
  Node* new_node = new Node(value);
  new_node->prev_ = tail_ ? tail_ : end_;
  new_node->next_ = end_;
  if (tail_) {
    tail_->next_ = new_node;
  } else {
    head_ = new_node;
  }
  tail_ = new_node;
  ++size_;
  end_->prev_ = tail_;
  end_->next_ = head_;
  end_->value_ = value_type();
}

// Removes the last element
template <typename value_type>
void list<value_type>::pop_back() {
  if (empty()) {
    throw std::out_of_range("Error: List is empty");
  }

  Node* tmp = tail_->prev_;
  tmp->next_ = end_->next_;
  tail_->prev_->next_ = end_;
  end_->prev_ = tmp;
  delete tail_;
  --size_;

  if (size_) {
    tail_ = tmp;
  } else {
    tail_ = nullptr;
  }
  end_->value_ = value_type();
}

// Adds an element to the head
template <typename value_type>
void list<value_type>::push_front(const_reference value) {
  if (head_) {
    Node* new_node = new Node(value);
    new_node->next_ = head_;
    new_node->prev_ = end_;
    head_->prev_ = new_node;
    end_->next_ = new_node;
    head_ = new_node;
    end_->next_ = new_node;
    size_++;
  } else {
    push_back(value);
  }
}

// Removes the first element
template <typename value_type>
void list<value_type>::pop_front() {
  erase(iterator(head_));
}

// Swaps the contents
template <typename value_type>
void list<value_type>::swap(list& other) {
  std::swap(end_, other.end_);
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(size_, other.size_);
}

// Merges two sorted lists
template <typename value_type>
void list<value_type>::merge(list& other) {
  if (!other.empty() && &other != this) {
    for (iterator it_i = other.begin(); it_i != other.end(); it_i++) {
      push_back(*it_i);
    }
    other.clear();
  }
}

// Transfers elements from list other starting from pos(const_iterator)
template <typename value_type>
void list<value_type>::splice(const_iterator pos, list& other) {
  if (other.empty()) {
    throw std::out_of_range("Error: List is empty");
  }
  splice_helper(pos, other);
}

// Transfers elements from list other starting from pos(iterator)
template <typename value_type>
void list<value_type>::splice(iterator pos, list& other) {
  if (other.empty()) {
    throw std::out_of_range("Error: List is empty");
  }
  splice_helper(pos, other);
}

// Reverses the order of the elements
template <typename value_type>
void list<value_type>::reverse() {
  if (size_ > 1) {
    iterator it_begin = begin();
    iterator it_tail = --end();
    while (it_begin != it_tail) {
      value_type tmp = *it_begin;
      *it_begin = *it_tail;
      *it_tail = tmp;
      ++it_begin;
      if (it_begin == it_tail) {
        break;
      }
      --it_tail;
    }
  }
}

// Removes consecutive duplicate elements
template <typename value_type>
void list<value_type>::unique() {
  if (size_ > 1) {
    iterator it = begin();
    while (it != end()) {
      iterator it_next = it;
      ++it_next;
      if (it_next != end() && *it == *it_next) {
        erase(it_next);
      } else {
        ++it;
      }
    }
  }
}

// Removes consecutive duplicate elements
template <typename value_type>
void list<value_type>::sort() {
  if (size_ > 1) {
    for (iterator it_i = begin(); it_i != end(); it_i++) {
      for (iterator it_j = begin(); it_j != end(); it_j++) {
        if (*it_j > *it_i) {
          value_type tmp = *it_j;
          it_j.node_->value_ = it_i.node_->value_;
          it_i.node_->value_ = tmp;
        }
      }
    }
  }
}

// Inserts new elements into the list directly before pos
template <typename value_type>
template <class... Args>
typename list<value_type>::iterator list<value_type>::insert_many(
    iterator pos, Args&&... args) {
  s21::list<value_type> insert_list{args...};
  iterator it = insert_list.begin();
  iterator it_end = insert_list.end();

  while (it != it_end) {
    pos = insert(pos, *it);
    ++it;
  }
  return pos;
}

// Appends new elements to the end of the list
template <typename value_type>
template <class... Args>
void list<value_type>::insert_many_back(Args&&... args) {
  insert_many(end(), args...);
}

// Appends new elements to the top of the list
template <typename value_type>
template <class... Args>
void list<value_type>::insert_many_front(Args&&... args) {
  insert_many(begin(), args...);
}

// Copies the elements from another list to the current list
template <typename value_type>
void list<value_type>::move_other(list& other) {
  head_ = std::exchange(other.head_, nullptr);
  tail_ = std::exchange(other.tail_, nullptr);
  end_ = std::exchange(other.end_, nullptr);
  size_ = std::exchange(other.size_, 0);
}

// Help to transfer elements from list other starting from pos(iterator)
template <typename value_type>
void list<value_type>::splice_helper(iterator pos, list& other) {
  iterator it = other.begin();
  for (size_t i = 0; i < other.size(); ++i) {
    insert(pos, *it);
    ++it;
  }
  other.clear();
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_LIST_S21_LIST_TPP_
