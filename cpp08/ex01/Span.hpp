#pragma once

#include <stdexcept>
#include <vector>

class Span {
private:
  std::vector<int> _numbers;
  unsigned int _maxSize;

public:
  Span(unsigned int N);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber(int num);
  int shortestSpan();
  int longestSpan();

  template <typename InputIt> void addNumber(InputIt begin, InputIt end) {
    if (std::distance(begin, end) + _numbers.size() > _maxSize)
      throw std::overflow_error(
          "Adding these elements would exceed Span capacity");
    _numbers.insert(_numbers.end(), begin, end);
  }
};
