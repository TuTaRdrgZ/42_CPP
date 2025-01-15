#pragma once

#include <cstddef>
template <typename T> class Array {
private:
  T *_data;
  unsigned int _size;

public:
  Array();
  Array(unsigned int n);
  Array(const Array<T> &a);
  Array &operator=(const Array &t_obj);
  T operator[](unsigned int n) const;
  T &operator[](unsigned int n);
  size_t size() const;
};
