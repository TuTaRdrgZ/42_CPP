#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <cstddef>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

typedef std::pair<int, int> IntPair;
typedef std::vector<IntPair> PairVec;

class PmergeMe {
private:
  std::vector<int> vector_;
  std::deque<int> deque_;

  int Jacobsthal(int r);
  template <typename Container>
  Container JacobsthalInsertionOrder(size_t length);

  template <typename Container>
  void PrintContainer(const Container &data) const;

  template <typename Container> void CheckSorted(const Container &data) const;

  void ParseInput(char **args);

  template <typename Container>
  PairVec CreatePairs(const Container &a, int &straggler, bool &hasStraggler);

  void SortEachPair(PairVec &split_array);

  template <typename Iterator, typename T>
  Iterator BinarySearch(Iterator begin, Iterator end, const T &value);

  template <typename Container> void Sort(Container &c);

public:
  PmergeMe(char **args);
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();
  void Run();
};

#endif // PMERGE_ME_HPP
