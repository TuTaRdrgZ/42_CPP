#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <cstddef>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

typedef std::vector<int> IntVec;
typedef std::deque<int> IntDeque;
typedef std::pair<int, int> IntPair;
typedef std::vector<IntPair> PairVec;
typedef std::vector<int>::value_type ValueType;

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
  void Insert(IntPair element, PairVec &A, int n);
  void InsertionSortPairs(PairVec &A, int n);

  template <typename Iterator, typename T>
  Iterator BinarySearch(Iterator begin, Iterator end, const T &value);

  template <typename Container> void Sort(Container &c);

  // recursive:
  template <typename Container>
  void FordJohnsonSort(Container &c, int pair_level);
  template <typename Container> void SortRecursive(Container &c);
  template <typename Container>
  void InsertPendIntoMain(Container &main, Container &pend, ValueType odd,
                          bool is_odd);

public:
  PmergeMe(char **args);
  PmergeMe(const PmergeMe &src);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();
  void Run();
};

#endif // PMERGE_ME_HPP
