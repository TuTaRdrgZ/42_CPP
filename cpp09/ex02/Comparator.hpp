#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP
#include <cstddef>
#include <iostream>

class Comparator {
public:
  mutable size_t count;
  Comparator();
  ~Comparator();
  Comparator(const Comparator &src);
  Comparator &operator=(const Comparator &other);
  void reset();
  template <typename T> bool operator()(const T &a, const T &b) const;
};

#endif // COMPARATOR_HPP
