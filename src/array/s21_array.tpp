#ifndef CPP2_S21_CONTAINERS_SRC_ARRAY_S21_ARRAY_TPP_
#define CPP2_S21_CONTAINERS_SRC_ARRAY_S21_ARRAY_TPP_

namespace s21 {

//=========================== Array Member functions =========================

// default constructor
template <typename T, std::size_t Size>
array<T, Size>::array() {}

// initializer list constructor
template <typename T, std::size_t Size>
array<T, Size>::array(std::initializer_list<value_type> const &items) {
  if (items.size() > Size) {
    throw std::invalid_argument("Too many initializers");
  }
  std::copy(items.begin(), items.end(), data_);
}

// copy constructor
template <typename T, std::size_t Size>
array<T, Size>::array(const array &a) {
  for (size_t i = 0; i < a.size(); i++) {
    data_[i] = a.data_[i];
  }
}

// move constructor
template <typename T, std::size_t Size>
array<T, Size>::array(array &&a) {
  for (size_t i = 0; i < a.size(); i++) {
    data_[i] = std::move(a.data_[i]);
  }
}

// destructor
template <typename T, std::size_t Size>
array<T, Size>::~array() {}

// assignment operator
template <typename T, std::size_t Size>
typename array<T, Size>::array &array<T, Size>::operator=(array &&a) {
  for (size_t i = 0; i < Size; i++) {
    data_[i] = std::move(a.data_[i]);
  }
  return *this;
}

// copy operator
template <typename T, size_t Size>
typename array<T, Size>::array &array<T, Size>::operator=(const array &a) {
  for (size_t i = 0; i < Size; i++) {
    data_[i] = a.data_[i];
  }
  return *this;
}

//===========================  Array Element access ==========================

// access specified element with bounds checking
template <typename T, std::size_t Size>
typename array<T, Size>::reference array<T, Size>::at(size_type pos) {
  if (pos >= Size) {
    throw std::out_of_range("index is out of range");
  }
  return data_[pos];
}

// const access specified element with bounds checking
template <typename T, std::size_t Size>
typename array<T, Size>::const_reference array<T, Size>::at(
    size_type pos) const {
  if (pos >= Size) {
    throw std::out_of_range("index is out of range");
  }
  return data_[pos];
}

// access specified element
template <typename T, std::size_t Size>
typename array<T, Size>::reference array<T, Size>::operator[](
    size_type pos) noexcept {
  return data_[pos];
}

// const access specified element
template <typename T, std::size_t Size>
typename array<T, Size>::const_reference array<T, Size>::operator[](
    size_type pos) const noexcept {
  return data_[pos];
}

// access the first element
template <typename T, std::size_t Size>
typename array<T, Size>::reference array<T, Size>::front() {
  return data_[0];
}

// const access the first element
template <typename T, std::size_t Size>
typename array<T, Size>::const_reference array<T, Size>::front() const {
  return data_[0];
}

// access the last element
template <typename T, std::size_t Size>
typename array<T, Size>::reference array<T, Size>::back() {
  return data_[Size - 1];
}

// const access the last element
template <typename T, std::size_t Size>
typename array<T, Size>::const_reference array<T, Size>::back() const {
  return data_[Size - 1];
}

// direct access to the underlying array
template <typename T, std::size_t Size>
typename array<T, Size>::iterator array<T, Size>::data() {
  return data_;
}

// const direct access to the underlying array
template <typename T, std::size_t Size>
typename array<T, Size>::const_iterator array<T, Size>::data() const {
  return data_;
}

//============================= Array Iterators ==============================

// returns an iterator to the beginning
template <typename T, std::size_t Size>
typename array<T, Size>::iterator array<T, Size>::begin() {
  return data_;
}

// returns a const iterator to the beginning
template <typename T, std::size_t Size>
typename array<T, Size>::const_iterator array<T, Size>::begin() const {
  return data_;
}

// returns an iterator to the end
template <typename T, std::size_t Size>
typename array<T, Size>::iterator array<T, Size>::end() {
  return data_ + Size;
}

// returns a const iterator to the end
template <typename T, std::size_t Size>
typename array<T, Size>::const_iterator array<T, Size>::end() const {
  return data_ + Size;
}

//==============================  Array Capacity =============================

// checks whether the container is empty
template <typename T, std::size_t Size>
bool array<T, Size>::empty() const noexcept {
  return Size == 0;
}

// returns the number of elements
template <typename T, std::size_t Size>
typename array<T, Size>::size_type array<T, Size>::size() const noexcept {
  return Size;
}

// returns the maximum possible number of elements
template <typename T, std::size_t Size>
typename array<T, Size>::size_type array<T, Size>::max_size() const noexcept {
  return Size;
}

//=============================  Array Modifiers =============================

// swaps the contents
template <typename T, std::size_t Size>
void array<T, Size>::swap(array &other) {
  std::swap(data_, other.data_);
}

// assigns the given value to all elements in the container
template <typename T, std::size_t Size>
void array<T, Size>::fill(const_reference value) noexcept {
  std::fill(data_, data_ + Size, value);
}

};  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_ARRAY_S21_ARRAY_TPP_