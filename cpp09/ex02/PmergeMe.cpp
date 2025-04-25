#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>

// Constructor
PmergeMe::PmergeMe(char **args) {
  std::vector<int> vec = ParseInput(args);
  vector_ = vec;
  deque_.assign(vec.begin(), vec.end());
  comp_.reset();
}

PmergeMe::PmergeMe(const PmergeMe &src) {
  if (this != &src) {
    vector_ = src.vector_;
    deque_ = src.deque_;
    comp_.count = src.comp_.count;
  }
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    vector_ = other.vector_;
    deque_ = other.deque_;
    comp_.count = other.comp_.count;
  }
  return *this;
}
PmergeMe::~PmergeMe() {}

// Prints the container elements separated by spaces.
template <typename Container>
void PmergeMe::PrintContainer(const Container &data) const {
  for (typename Container::const_iterator it = data.begin(); it != data.end();
       ++it)
    std::cout << *it << " ";
  std::cout << "\n";
}

// Calculate the Jacobsthal number
size_t PmergeMe::ModJac(size_t r) {
  if (r == 1)
    return 1;
  if (r == 2)
    return 3;
  size_t a = 1, b = 3;
  for (size_t i = 3; i <= r; ++i) {
    size_t c = b + 2 * a;
    a = b;
    b = c;
  }
  return b;
}

// Recursive implementation of Ford-Johnson (Merge-Insertion) with explicit
// comparison counting
template <typename Iterator>
void PmergeMe::FordJohnsonSort(Iterator begin, Iterator end, Comparator &comp) {
  typedef typename std::iterator_traits<Iterator>::value_type T;

  size_t n = std::distance(begin, end);
  if (n <= 1)
    return;

  bool hasStray = n % 2 != 0;
  T stray;
  if (hasStray) {
    stray = *(end - 1);
    --end;
    n--;
  }

  // Winners and losers
  std::vector<Iterator> winners;
  std::vector<T> losers;
  for (Iterator it = begin; it != end; it += 2) {
    Iterator first = it;
    Iterator second = it + 1;
    if (comp(*second, *first))
      std::iter_swap(first, second); // first = max, second = min
    winners.push_back(first);        // winner
    losers.push_back(*second);       // loser
  }

  // Recursively sort winners
  std::vector<T> sortedWinners;
  for (size_t i = 0; i < winners.size(); ++i)
    sortedWinners.push_back(*winners[i]);
  FordJohnsonSort(sortedWinners.begin(), sortedWinners.end(), comp);

  // Insertion of losers using Jacobsthal sequence
  int r_max = 1;
  while (ModJac(r_max + 1) <= losers.size())
    ++r_max;
  size_t threshold = ModJac(r_max);
  std::vector<size_t> insertionOrder;
  for (size_t i = threshold; i >= 1; --i)
    insertionOrder.push_back(i - 1);
  for (size_t i = threshold; i < losers.size(); ++i)
    insertionOrder.push_back(i);

  for (std::vector<size_t>::iterator idx = insertionOrder.begin();
       idx != insertionOrder.end(); ++idx) {
    T value = losers[*idx];
    // Binary search with custom comparator
    typename std::vector<T>::iterator pos = std::lower_bound(
        sortedWinners.begin(), sortedWinners.end(), value, comp);
    sortedWinners.insert(pos, value);
  }
  // Insert stray
  if (hasStray) {
    typename std::vector<T>::iterator pos = std::lower_bound(
        sortedWinners.begin(), sortedWinners.end(), stray, comp);
    sortedWinners.insert(pos, stray);
  }
  std::copy(sortedWinners.begin(), sortedWinners.end(), begin);
}

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

std::vector<int> PmergeMe::ParseInput(char **args) const {
  std::vector<int> result;
  if (!args || !*args) {
    std::cerr << "Error ParseInput" << std::endl;
    std::exit(1);
  }
  while (*args) {
    std::string token(*args);
    if (token.find_first_not_of("0123456789") != std::string::npos) {
      std::cerr << "Error: Invalid char" << std::endl;
      std::exit(1);
    }
    result.push_back(std::atoi(*args));
    ++args;
  }
  return result;
}

// Function to run the sort N times and calculate the average time and
// comparisons
template <typename Container>
double PmergeMe::RunAndCheckAverageTime(Container &container, int repetitions,
                                        size_t &avg_comp) {
  double totalTime = 0.0;
  size_t totalComp = 0;

  for (int i = 0; i < repetitions; ++i) {
    Container tempContainer = container;
    comp_.reset();
    clock_t start = clock();
    FordJohnsonSort(tempContainer.begin(), tempContainer.end(), comp_);
    clock_t end = clock();
    totalTime += (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);
    totalComp += comp_.count;
    CheckSorted(tempContainer);
  }

  // Final actual sort to main container
  comp_.reset();
  FordJohnsonSort(container.begin(), container.end(), comp_);
  CheckSorted(container);

  avg_comp = totalComp / repetitions;
  return totalTime / repetitions;
}

void PmergeMe::Sort() {
  int repetitions = 1000;
  std::cout << "Before sorting:\n";
  PrintContainer(vector_);
  size_t avgCompVec = 0;
  size_t avgCompDeq = 0;

  double avgTimeVector =
      RunAndCheckAverageTime(vector_, repetitions, avgCompVec);
  double avgTimeDeque = RunAndCheckAverageTime(deque_, repetitions, avgCompDeq);

  std::cout << "After sorting:\n";
  PrintContainer(vector_);

  std::cout << "Average time to process " << vector_.size()
            << " elements with std::vector: " << avgTimeVector << " ms"
            << " (over " << repetitions << " runs)\n";
  std::cout << "Average comparisons vector: " << avgCompVec << "\n";
  std::cout << "Average time to process " << deque_.size()
            << " elements with std::deque: " << avgTimeDeque << " ms"
            << " (over " << repetitions << " runs)\n";
  std::cout << "Average comparisons deque: " << avgCompDeq << "\n";
}

// Explicit instantiations (for templates in .cpp)
template void PmergeMe::PrintContainer(const std::vector<int> &) const;
template void PmergeMe::PrintContainer(const std::deque<int> &) const;
template void PmergeMe::CheckSorted(const std::vector<int> &) const;
template void PmergeMe::CheckSorted(const std::deque<int> &) const;

template double PmergeMe::RunAndCheckAverageTime(std::vector<int> &, int,
                                                 size_t &);
template double PmergeMe::RunAndCheckAverageTime(std::deque<int> &, int,
                                                 size_t &);
