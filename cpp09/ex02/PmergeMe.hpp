#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include "Comparator.hpp"
#include <cstddef>
#include <deque>
#include <iostream>
#include <vector>

class PmergeMe {

private:
  std::vector<int> vector_;
  std::deque<int> deque_;
  Comparator comp_;
  size_t ModJac(size_t r);
  template <typename Container>
  void PrintContainer(const Container &data) const;
  template <typename T> void Sort(T &container);
  template <typename Iterator>
  void FordJohnsonSort(Iterator begin, Iterator end, Comparator &comp);
  template <typename Container> void CheckSorted(const Container &data) const;
  std::vector<int> ParseInput(char **args) const;
  template <typename Container>
  double RunAndCheckAverageTime(Container &container, int repetitions,
                                size_t &avg_comp);

public:
  PmergeMe(char **args);
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();
  void Sort();
};

#endif // PMERGE_ME_HPP
