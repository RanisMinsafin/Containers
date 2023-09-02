#ifndef CPP2_S21_CONTAINERS_SRC_ARRAY_S21_ARRAY_H_
#define CPP2_S21_CONTAINERS_SRC_ARRAY_S21_ARRAY_H_

namespace s21 {
template <typename T, std::size_t Size>
class array {
 public:
  //============================= Array Member type ============================

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  //=========================== Array Member functions =========================

  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a);
  ~array();
  array &operator=(array &&a);
  array &operator=(const array &a);

  //===========================  Array Element access ==========================

  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos) noexcept;
  const_reference operator[](size_type pos) const noexcept;
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;
  iterator data();
  const_iterator data() const;

  //============================= Array Iterators ==============================

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

  //==============================  Array Capacity =============================

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  //=============================  Array Modifiers =============================

  void swap(array &other);
  void fill(const_reference value) noexcept;

 private:
  value_type data_[Size]{};
};
}  // namespace s21

#include "s21_array.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_ARRAY_S21_ARRAY_H_
