#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// Computes the n-th Jacobsthal number (used in the original Ford–Johnson
// research) (Not used in this simplified insertion order, but kept for
// reference)
static int computeJacobsthal(int n) {
  int a = 1, b = 1;
  for (int i = 0; i < n; ++i) {
    int temp = b;
    b = b + a * 2; // J(n) = J(n-1) + 2*J(n-2)
    a = temp;
  }
  return b;
}

// Templated Ford–Johnson (merge–insertion) sort.
// The algorithm partitions the data into pairs, recursively sorts the winners,
// then inserts the losers (in reverse order) using binary insertion.
template <typename Container> void fordJohnsonSort(Container &data) {
  typedef typename Container::value_type T;
  size_t size = data.size();
  if (size <= 1)
    return; // Already sorted

  Container winners, losers;
  T stray; // Holds an extra element if the size is odd
  bool hasStray = false;

  // If odd, remove the last element as stray
  if (size % 2 != 0) {
    stray = data.back();
    hasStray = true;
    --size;
  }

  // Process elements in pairs and partition into winners and losers.
  // For each pair, the larger element goes to winners and the smaller to
  // losers.
  for (size_t i = 0; i < size; i += 2) {
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
  fordJohnsonSort(winners);

  // Insert the losers into the sorted winners.
  // (A full Ford–Johnson algorithm would determine an optimal insertion order
  // using the Jacobsthal numbers; here we simply insert losers in reverse
  // order.)
  if (!losers.empty()) {
    // Start with the loser from the pair that produced the largest winner.
    Container merged = winners;
    typename Container::iterator pos;
    // Insert the last loser first.
    pos = std::lower_bound(merged.begin(), merged.end(), losers.back());
    merged.insert(pos, losers.back());
    // Then insert the remaining losers in reverse order.
    for (int i = static_cast<int>(losers.size()) - 2; i >= 0; --i) {
      pos = std::lower_bound(merged.begin(), merged.end(), losers[i]);
      merged.insert(pos, losers[i]);
    }
    winners = merged;
  }

  // If there was a stray element, insert it as well.
  if (hasStray) {
    typename Container::iterator pos =
        std::lower_bound(winners.begin(), winners.end(), stray);
    winners.insert(pos, stray);
  }

  // Replace original data with the sorted sequence.
  data = winners;
}

// Checks whether the container is sorted in ascending order.
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

// Prints the elements of the container separated by spaces.
template <typename Container> void printContainer(const Container &data) {
  typedef typename Container::const_iterator ConstIter;
  for (ConstIter it = data.begin(); it != data.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

// Utility function that builds a vector of integers from command-line
// arguments. It verifies that each token contains only digits.
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

// Main function:
// Builds containers from command-line arguments, sorts them using Ford–Johnson
// sort, checks the results, and prints timing information.
int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  // Build a vector of integers from command-line arguments.
  std::vector<int> vec = fetchIntVector(++argv);
  // Also create a deque from the vector.
  std::deque<int> deq(vec.begin(), vec.end());

  std::cout << "Before sorting:" << std::endl;
  printContainer(vec);

  // Time the sorting for each container.
  clock_t start, end;
  double timeVector, timeDeque;

  start = clock();
  fordJohnsonSort(vec);
  end = clock();
  timeVector = (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);

  start = clock();
  fordJohnsonSort(deq);
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
