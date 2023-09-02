#ifndef CPP2_S21_CONTAINERS_SRC_VECTOR_S21_VECTOR_H_
#define CPP2_S21_CONTAINERS_SRC_VECTOR_S21_VECTOR_H_

#include <initializer_list>

namespace s21 {
template <typename T>
class vector {
 private:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

 public:
  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();
  reference operator=(vector &&v);

  // Vector Element access
  const_reference at(size_type pos) const;
  reference at(size_type pos);
  const_reference operator[](size_type pos) const;
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  value_type *data();

  template <typename value_type>
  class VectorIterator {
   public:
    VectorIterator() : ptr(nullptr) {}
    VectorIterator(value_type *iter) : ptr(iter) {}
    VectorIterator(VectorIterator &iter) { this->ptr = iter.ptr; }
    VectorIterator &operator=(VectorIterator it) {
      this->ptr = it.ptr;
      return *this;
    }
    VectorIterator &operator=(value_type *it) {
      this->ptr = it;
      return *this;
    }
    reference operator*() { return *ptr; }
    value_type *operator++() { return ++ptr; }
    value_type *operator--() { return --ptr; }
    value_type *operator+(const int n) { return ptr + n; }
    bool operator==(VectorIterator &iter) { return this->ptr == iter.ptr; }
    bool operator!=(VectorIterator &iter) { return this->ptr != iter.ptr; }

   private:
    value_type *ptr;
  };

  template <typename value_type>
  class VectorConstIterator {
   public:
    VectorConstIterator() : ptr(nullptr) {}
    VectorConstIterator(value_type *iter) : ptr(iter) {}

   private:
    const value_type *ptr;
  };

  using iterator = VectorIterator<value_type>;
  using const_iterator = VectorConstIterator<value_type>;

  // Vector Iterators
  iterator begin();
  iterator end();

  // Vector Capacity
  bool empty();
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const;
  void shrink_to_fit();

  // Vector Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

  // Bonus Vector Modifiers
  template <typename... Args>
  iterator insert_many(iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  size_type size_;
  size_type capacity_;
  value_type *data_;
};

}  // namespace s21

#include "s21_vector.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_VECTOR_S21_VECTOR_H_