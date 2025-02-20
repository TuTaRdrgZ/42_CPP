#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>

Span::Span(unsigned int N) : _maxSize(N) {}

Span::~Span() {}

Span::Span(const Span &other) {
  _numbers = other._numbers;
  _maxSize = other._maxSize;
}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    _numbers = other._numbers;
    _maxSize = other._maxSize;
  }
  return *this;
}

void Span::addNumber(int num) {
  if (_numbers.size() >= _maxSize)
    throw std::overflow_error("Span is full, cannot add more numbers.");
  _numbers.push_back(num);
}

// Calcular el menor intervalo entre numeros
int Span::shortestSpan() {
  if (_numbers.size() < 2)
    throw std::logic_error("Not enough numbers to calculate span.");

  std::vector<int> sorted = _numbers;
  std::sort(sorted.begin(), sorted.end());

  int minSpan = std::numeric_limits<int>::max();
  for (size_t i = 1; i < sorted.size(); i++) {
    int diff = sorted[i] - sorted[i - 1];
    if (diff < minSpan)
      minSpan = diff;
  }
  return minSpan;
}

// Calcular el mayor intervalo entre numeros
int Span::longestSpan() {
  if (_numbers.size() < 2)
    throw std::logic_error("Not enough numbers to calculate span.");

  int minNum = *std::min_element(_numbers.begin(), _numbers.end());
  int maxNum = *std::max_element(_numbers.begin(), _numbers.end());

  return maxNum - minNum;
}
