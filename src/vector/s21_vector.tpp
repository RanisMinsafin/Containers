#ifndef CPP2_S21_CONTAINERS_SRC_VECTOR_S21_VECTOR_TPP_
#define CPP2_S21_CONTAINERS_SRC_VECTOR_S21_VECTOR_TPP_

namespace s21 {

template <typename T>
vector<T>::vector() : size_(0), capacity_(0), data_(nullptr) {}

template <typename T>
vector<T>::vector(size_type n) : size_(n), capacity_(n), data_(nullptr) {
  if (size_ > 0) {
    data_ = static_cast<value_type *>(operator new(size_ * sizeof(value_type)));
    for (size_type i = 0; i < size_; ++i) {
      new (&data_[i]) T();
    }
  }
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : size_(items.size()), capacity_(items.size()), data_(nullptr) {
  if (size_ > 0) {
    data_ = static_cast<value_type *>(operator new(size_ * sizeof(value_type)));
    int count = 0;
    for (auto elem : items) {
      new (&data_[count]) T(elem);
      ++count;
    }
  }
}

template <typename T>
vector<T>::vector(const vector &v)
    : size_(v.size_), capacity_(v.capacity_), data_(nullptr) {
  if (size_ > 0) {
    data_ = static_cast<value_type *>(operator new(size_ * sizeof(value_type)));
    for (size_type i = 0; i < size_; ++i) {
      new (data_ + i) T(v.data_[i]);
    }
  }
}

template <typename T>
vector<T>::vector(vector &&v)
    : size_(v.size_), capacity_(v.capacity_), data_(nullptr) {
  this->data_ = v.data_;
  v.size_ = 0;
  v.capacity_ = 0;
  v.data_ = nullptr;
}

template <typename T>
vector<T>::~vector() {
  if (data_) {
    for (size_type i = 0; i < size_; ++i) {
      data_[i].~value_type();
    }
    operator delete(data_);
  }
}

template <typename T>
typename vector<T>::reference vector<T>::operator=(vector &&v) {
  if (this == &v) {
    return *this;
  }
  if (this->data_) {
    for (size_type i = 0; i < size_; ++i) {
      this->data_[i].~value_type();
    }
    operator delete(this->data_);
  }
  this->data_ = v.data_;
  this->size_ = v.size_;
  this->capacity_ = v.capacity_;
  v->data_ = nullptr;
  v->size_ = 0;
  v->capacity_ = 0;
  return *this;
}

template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (size_ == 0) {
    throw std::logic_error("The vector is empty");
  }
  if (pos >= size_) {
    throw std::out_of_range("The index is out of range");
  }
  return data_[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::at(size_type pos) const {
  if (size_ == 0) {
    throw std::logic_error("The vector is empty");
  }
  if (pos >= size_) {
    throw std::out_of_range("The index is out of range");
  }
  return data_[pos];
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  if (size_ == 0) {
    throw std::logic_error("The vector is empty");
  }
  return data_[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::operator[](size_type pos) const {
  if (size_ == 0) {
    throw std::logic_error("The vector is empty");
  }
  return data_[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() {
  return data_[0];
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() {
  return data_[size_ - 1];
}

template <typename T>
typename vector<T>::value_type *vector<T>::data() {
  return data_;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return data_ ? iterator(data_) : iterator(this->end());
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return iterator(data_ + size_);
}

template <typename T>
bool vector<T>::empty() {
  return size_ == 0;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() const {
  return size_;
}

template <typename T>  //посмотреть
typename vector<T>::size_type vector<T>::max_size() const {
  return SIZE_MAX / sizeof(s21::vector<T>);
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() const {
  return capacity_;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ == capacity_) {
    return;
  }
  reserve(size_);
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (size == capacity_) {
    return;
  }
  if (size < size_) {
    throw std::logic_error("New capacity can`t be less then size of vector\n");
  }
  value_type *newdata =
      static_cast<value_type *>(operator new(size * sizeof(value_type)));
  size_t i = 0;
  try {
    for (; i < size_; ++i) {
      new (&newdata[i]) value_type(data_[i]);
    }
  } catch (...) {
    for (size_t j = 0; j < i; ++j) {
      newdata[j].~value_type();
    }
    operator delete(newdata);
    throw;
  }

  for (size_t i = 0; i < size_; ++i) {
    data_[i].~value_type();
  }
  operator delete(data_);
  this->capacity_ = size;
  this->data_ = newdata;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  iterator begin = this->begin();
  // auto my_count = pos - begin;
  // std::cout << "my count: " << my_count << "\n";
  size_type count = 0;
  while (begin != pos) {
    ++count;
    ++begin;
  }
  if (capacity_ < size_ + 1) {
    value_type *newdata = nullptr;
    if (capacity_) {
      newdata = static_cast<value_type *>(operator new(2 * capacity_ *
                                                       sizeof(value_type)));
    } else {
      newdata = static_cast<value_type *>(operator new(sizeof(value_type)));
    }
    for (size_type i = 0; i < size_ + 1; ++i) {
      if (i == count) {
        pos = new (&newdata[i]) value_type(value);
      } else {
        new (&newdata[i]) value_type(*data_);
        ++data_;
      }
    }
    if (size_) {
      data_ = data_ - size_;
      for (size_type i = 0; i < size_; ++i) {
        data_[i].~value_type();
      }
      operator delete(data_);
    }
    data_ = newdata;
    if (capacity_) {
      capacity_ = 2 * capacity_;
    } else {
      capacity_ = 1;
    }
  } else {
    for (size_type i = size_; i > count; --i) {
      new (&data_[i]) value_type(data_[i - 1]);
    }
    new (&data_[count]) value_type(value);
    pos = &data_[count];
  }
  ++size_;
  return pos;
}

template <typename T>
void vector<T>::erase(iterator pos) {
  if (this->data_ == 0) {
    throw std::logic_error("The vector is empty");
  }
  iterator begin = this->begin();
  size_type count = 0;
  while (begin != pos) {
    ++count;
    ++begin;
  }
  data_[count].~value_type();
  for (size_type i = count; i < size_ - 1; ++i) {
    new (&data_[i]) value_type(data_[i + 1]);
  }
  if (count != size_ - 1) {
    data_[size_ - 1].~value_type();
  }
  --size_;
}

template <typename T>
void vector<T>::clear() {
  if (data_) {
    for (size_type i = 0; i < size_; ++i) {
      data_[i].~value_type();
    }
  }
  size_ = 0;
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  if (capacity_ < size_ + 1) {
    if (!capacity_) {
      reserve(1);
    } else {
      reserve(2 * capacity_);
    }
  }
  new (data_ + size_) value_type(value);
  ++size_;
}

template <typename T>
void vector<T>::pop_back() {
  (data_ + size_ - 1)->~value_type();
  --size_;
}

template <typename T>
void vector<T>::swap(vector &other) {
  T *tmp_ptr = this->data_;
  this->data_ = other.data_;
  other.data_ = tmp_ptr;
  size_type tmp_size = this->size_;
  this->size_ = other.size_;
  other.size_ = tmp_size;
  size_type tmp_cap = this->capacity_;
  this->capacity_ = other.capacity_;
  other.capacity_ = tmp_cap;
}

template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(iterator pos,
                                                    Args &&...args) {
  vector<value_type> insert_list{args...};
  iterator it_begin = insert_list.begin();
  iterator it_end = insert_list.end();
  while (it_begin != it_end) {
    --it_end;
    pos = this->insert(pos, *it_end);
  }
  return pos;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  vector<value_type> insert_list{args...};
  iterator it_begin = insert_list.begin();
  iterator it_end = insert_list.end();
  while (it_begin != it_end) {
    this->push_back(*it_begin);
    ++it_begin;
  }
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_VECTOR_S21_VECTOR_TPP_