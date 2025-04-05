#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// Prints the container elements separated by spaces.
template <typename Container> void printContainer(const Container &data) {
  typedef typename Container::const_iterator ConstIter;
  for (ConstIter it = data.begin(); it != data.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

// Helper: Computes the modified Jacobsthal number.
// modJac(1)=1, modJac(2)=3, and for r>=3: modJac(r) = modJac(r-1) + 2 *
// modJac(r-2)
int modJac(int r) {
  if (r == 1)
    return 1;
  if (r == 2)
    return 3;
  int a = 1, b = 3;
  for (int i = 3; i <= r; ++i) {
    int c = b + 2 * a;
    a = b;
    b = c;
  }
  return b;
}

// Authentic Ford–Johnson merge–insertion sort.
// This templated function sorts the container "data" in ascending order.
template <typename Container> void fordJohnsonFullSort(Container &data) {
  typedef typename Container::value_type T;
  size_t n = data.size();
  if (n <= 1)
    return; // Already sorted

  // Partition data into pairs.
  // For each pair, the larger element (winner) goes to winners, and the smaller
  // (loser) goes to losers.
  std::vector<T> winners;
  std::vector<T> losers;
  bool hasStray = (n % 2 != 0);
  T stray;
  if (hasStray) {
    stray = data[n - 1];
    --n;
  }
  for (size_t i = 0; i < n; i += 2) {
    T first = data[i], second = data[i + 1];
    if (first < second) {
      winners.push_back(second);
      losers.push_back(first);
    } else {
      winners.push_back(first);
      losers.push_back(second);
    }
  }

  // Recursively sort the winners.
  fordJohnsonFullSort(winners);

  // Determine insertion order for losers using modified Jacobsthal numbers.
  int pairCount = static_cast<int>(losers.size()); // number of pairs
  int r_max = 1;
  // Find largest r such that modJac(r+1) <= pairCount.
  while (modJac(r_max + 1) <= pairCount)
    ++r_max;
  int threshold = modJac(r_max); // one-based threshold

  // Build insertion order:
  // First, losers with indices (threshold-1 downto 0) [zero-based],
  // then any remaining losers in natural order.
  std::vector<int> insertionOrder;
  for (int i = threshold; i >= 1; --i)
    insertionOrder.push_back(i - 1);
  for (int i = threshold; i < pairCount; ++i)
    insertionOrder.push_back(i);

  // Start with sorted winners as the initial chain.
  std::vector<T> sortedChain = winners;
  // Insert losers in the computed order using binary insertion.
  for (size_t i = 0; i < insertionOrder.size(); ++i) {
    T loserVal = losers[insertionOrder[i]];
    typename std::vector<T>::iterator pos =
        std::lower_bound(sortedChain.begin(), sortedChain.end(), loserVal);
    sortedChain.insert(pos, loserVal);
  }
  // Insert stray element, if it exists.
  if (hasStray) {
    typename std::vector<T>::iterator pos =
        std::lower_bound(sortedChain.begin(), sortedChain.end(), stray);
    sortedChain.insert(pos, stray);
  }

  // Copy the sorted chain back into the original container.
  // Since we cannot assign a std::vector<T> to a Container (e.g., std::deque),
  // we clear the container and copy the sorted elements.
  data.clear();
  std::copy(sortedChain.begin(), sortedChain.end(), std::back_inserter(data));
}

// Checks if the container is sorted in ascending order.
template <typename Container> void checkSorted(const Container &data) {
  typedef typename Container::const_iterator ConstIter;
  ConstIter it = data.begin(), next = data.begin();
  if (it != data.end())
    ++next;
  while (next != data.end()) {
    if (*it > *next) {
      std::cout << "Sequence is NOT sorted!" << std::endl;
      std::exit(1);
    }
    ++it;
    ++next;
  }
}

// Utility: Constructs a vector<int> from command-line arguments.
// Each argument must consist solely of digits.
std::vector<int> fetchIntVector(char **args) {
  std::vector<int> result;
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
    result.push_back(std::atoi(*args));
    ++args;
  }
  return result;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  // Build a vector of integers from command-line arguments.
  std::vector<int> vec = fetchIntVector(++argv);
  std::deque<int> deq(vec.begin(), vec.end());

  std::cout << "Before sorting:" << std::endl;
  printContainer(vec);

  clock_t start, end;
  double timeVector, timeDeque;

  start = clock();
  fordJohnsonFullSort(vec);
  end = clock();
  timeVector = (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);

  start = clock();
  fordJohnsonFullSort(deq);
  end = clock();
  timeDeque = (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);

  std::cout << "After sorting:" << std::endl;
  printContainer(vec);

  checkSorted(vec);
  checkSorted(deq);

  std::cout << "Time to process " << vec.size()
            << " elements with std::vector: " << timeVector << " ms"
            << std::endl;
  std::cout << "Time to process " << deq.size()
            << " elements with std::deque: " << timeDeque << " ms" << std::endl;

  return 0;
}
