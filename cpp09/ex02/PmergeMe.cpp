#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>

// Constructor from input arguments
PmergeMe::PmergeMe(char **args) : vector_(), deque_() { ParseInput(args); }

PmergeMe::PmergeMe(const PmergeMe &src) {
  if (this != &src) {
    vector_ = src.vector_;
    deque_ = src.deque_;
  }
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    vector_ = other.vector_;
    deque_ = other.deque_;
  }
  return *this;
}
PmergeMe::~PmergeMe() {}

// Prints all elements in the container separated by spaces.
template <typename Container>
void PmergeMe::PrintContainer(const Container &data) const {
  for (typename Container::const_iterator it = data.begin(); it != data.end();
       ++it)
    std::cout << *it << " ";
  std::cout << "\n";
}

// Checks if the container is sorted in ascending order.
template <typename Container>
void PmergeMe::CheckSorted(const Container &data) const {
  typename Container::const_iterator next;
  for (typename Container::const_iterator it = data.begin(); it != data.end();
       ++it) {
    next = it;
    ++next;
    if (next != data.end() && *it > *next) {
      std::cout << "Sequence is NOT sorted!" << std::endl;
      std::exit(1);
    }
  }
}

// Parses input arguments into a vector of ints.
void PmergeMe::ParseInput(char **args) {
  if (!args || !*args) {
    std::cerr << "Error" << std::endl;
    std::exit(1);
  }
  while (*args) {
    std::string token(*args);
    if (token.find_first_not_of("0123456789") != std::string::npos) {
      std::cerr << "Error" << std::endl;
      std::exit(1);
    }
    deque_.push_back(std::atoi(token.c_str()));
    vector_.push_back(std::atoi(token.c_str()));
    ++args;
  }
}

// Calculates the n-th Jacobsthal number. J(n)=J(n−1)+2⋅J(n−2) = 1 3 5 11 21 43 85 171...
int PmergeMe::Jacobsthal(int n) {
  if (n == 1)
    return 1;
  if (n == 2)
    return 3;
  int a = 1, b = 3;
  for (int i = 3; i <= n; ++i) {
    int c = b + 2 * a;
    a = b;
    b = c;
  }
  return b;
}

// Returns the Jacobsthal insertion order for a given length.
template <typename Container>
Container PmergeMe::JacobsthalInsertionOrder(size_t length) {
  Container result;
  int index = 3;
  while (length > 1 && static_cast<size_t>(Jacobsthal(index)) < length - 1) {
    result.push_back(Jacobsthal(index));
    ++index;
  }
  return result;
}

// Creates pairs from the input container. Handles stray element if present.
template <typename Container>
PairVec PmergeMe::CreatePairs(const Container &a, int &stray, bool &has_stray) {
  PairVec split_array;
  typename Container::const_iterator it = a.begin();
  while (it != a.end()) {
    if (std::distance(it, a.end()) == 1) {
      has_stray = true;
      stray = *it;
      ++it;
    } else {
      int first = *it;
      ++it;
      int second = *it;
      ++it;
      split_array.push_back(std::make_pair(first, second));
    }
  }
  return split_array;
}

// Sorts each pair so that first <= second
void PmergeMe::SortEachPair(PairVec &split_array) {
  for (size_t i = 0; i < split_array.size(); ++i) {
    if ((split_array[i].second < split_array[i].first)) {
      std::swap(split_array[i].first, split_array[i].second);
    }
  }
}

// Binary search
template <typename Iterator, typename T>
Iterator PmergeMe::BinarySearch(Iterator begin, Iterator end, const T &value) {
  while (begin < end) {
    Iterator mid = begin + (end - begin) / 2;
    if ((*mid < value))
      begin = mid + 1;
    else
      end = mid;
  }
  return begin;
}

// Ford-Johnson Sort
template <typename Container> void PmergeMe::Sort(Container &c) {
  if (c.size() <= 1)
    return;

  int stray = -1;
  bool has_stray = false;

  PairVec pairs = CreatePairs(c, stray, has_stray);

  SortEachPair(pairs);

  Container winners; // List of winners (second elements of pairs)
  for (typename PairVec::iterator it = pairs.begin(); it != pairs.end(); ++it) {
    winners.push_back(it->second);
  }

  Sort(winners); // Recursively sort the winners

  Container losers; // List of losers (first elements of pairs)
  for (typename PairVec::iterator it = pairs.begin(); it != pairs.end(); ++it) {
    losers.push_back(it->first);
  }

  std::cout << "Losers.size() = " << losers.size() << std::endl;
  Container jacobsthal_order = JacobsthalInsertionOrder<Container>(
      losers.size()); // Get Jacobsthal order
  std::cout << "Jacobsthal order: ";
  PrintContainer(jacobsthal_order);
  std::cout << std::endl;

  // Insert the losers into the winners in Jacobsthal order
  std::vector<bool> inserted(losers.size(),
                             false); // Tracking inserted elements
  for (typename Container::iterator it = jacobsthal_order.begin();
       it != jacobsthal_order.end(); ++it) {
    if (static_cast<size_t>(*it) < losers.size() && !inserted[*it]) {
      typename Container::iterator pos =
          BinarySearch(winners.begin(), winners.end(), losers[*it]);
      winners.insert(pos, losers[*it]);
      inserted[*it] = true;
    }
  }

  // Insert the remaining losers in sorted order
  for (size_t i = 0; i < losers.size(); ++i) {
    if (!inserted[i]) {
      typename Container::iterator pos =
          BinarySearch(winners.begin(), winners.end(), losers[i]);
      winners.insert(pos, losers[i]);
    }
  }

  // Insert the stray element if it exists
  if (has_stray) {
    typename Container::iterator pos =
        BinarySearch(winners.begin(), winners.end(), stray);
    winners.insert(pos, stray);
  }

  // Copy the sorted winners back to the original container
  std::copy(winners.begin(), winners.end(), c.begin());
}

// Run the sorting algorithm and measure time
void PmergeMe::Run() {

  size_t vec_og_size = vector_.size();
  size_t deq_og_size = deque_.size();

  std::cout << "Before sorting:\n";
  PrintContainer(vector_);

  clock_t start = clock();
  Sort(vector_);
  clock_t end = clock();
  CheckSorted(vector_);
  double vec_time = (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);

  start = clock();
  Sort(deque_);
  end = clock();
  CheckSorted(deque_);
  double deq_time = (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);

  if (vec_og_size != vector_.size() || deq_og_size != deque_.size()) {
    std::cerr << "Error: Container size changed during sorting.\n";
    std::exit(1);
  }

  std::cout << "After sorting:\n";
  PrintContainer(vector_);

  std::cout << "Time to process " << vector_.size()
            << " elements with std::vector: " << vec_time << " ms\n";
  std::cout << "Time to process " << deque_.size()
            << " elements with std::deque: " << deq_time << " ms\n";
}

// Explicit template instantiation
template void PmergeMe::PrintContainer(const std::vector<int> &) const;
template void PmergeMe::PrintContainer(const std::deque<int> &) const;
template void PmergeMe::CheckSorted(const std::vector<int> &) const;
template void PmergeMe::CheckSorted(const std::deque<int> &) const;
template PairVec PmergeMe::CreatePairs(const std::vector<int> &, int &, bool &);
template PairVec PmergeMe::CreatePairs(const std::deque<int> &, int &, bool &);
template void PmergeMe::Sort(std::vector<int> &);
template void PmergeMe::Sort(std::deque<int> &);
template std::vector<int> PmergeMe::JacobsthalInsertionOrder(size_t);
template std::deque<int> PmergeMe::JacobsthalInsertionOrder(size_t);
