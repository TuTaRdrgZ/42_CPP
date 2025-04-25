#include "Comparator.hpp"

Comparator::Comparator() : count(0) {}
Comparator::~Comparator() {}
Comparator::Comparator(const Comparator &src) : count(src.count) {}
Comparator &Comparator::operator=(const Comparator &other) {
  if (this != &other) {
    count = other.count;
  }
  return *this;
}
void Comparator::reset() { count = 0; }

template <typename T>
bool Comparator::operator()(const T &a, const T &b) const {
  ++count;
  return a < b;
}

template bool Comparator::operator()(const int &a, const int &b) const;
template bool Comparator::operator()(const size_t &a, const size_t &b) const;
