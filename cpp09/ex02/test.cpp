#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

static int nbr_of_comps = 0;

template <typename T> bool comp(T lv, T rv) {
	nbr_of_comps++;
	return *lv < *rv;
}

// Prints the container elements separated by spaces.
template <typename Container> void printContainer(const Container &data) {
  for (typename Container::const_iterator it = data.begin(); it != data.end();
       ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

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

template <typename Container> void fordJohnsonFullSort(Container &data) {
  typedef typename Container::value_type T;
  typedef typename Container::iterator Iterator;

  size_t n = data.size();
  if (n <= 1)
    return;

  // Handle stray element if odd number of items
  bool hasStray = n % 2 != 0;
  T stray;
  if (hasStray) {
    stray = data.back();
    data.pop_back();
    n--;
  }

  // Level structure: each level is a vector of iterators
  std::vector<std::vector<Iterator> > levels;
  std::vector<Iterator> currentLevel;

  // Create initial pairs (level 1)
  for (size_t i = 0; i < n; i += 2) {
    Iterator first = data.begin() + i;
    Iterator second = data.begin() + i + 1;
    if (comp(first, second))
      std::iter_swap(first, second);
    currentLevel.push_back(first); // winners
  }
  levels.push_back(currentLevel);

  // Build upper levels by pairing winners
  while (currentLevel.size() > 1) {
    std::vector<Iterator> nextLevel;
    for (size_t i = 0; i + 1 < currentLevel.size(); i += 2) {
      Iterator first = currentLevel[i];
      Iterator second = currentLevel[i + 1];
      if (comp(first, second))
        std::iter_swap(first, second);
      nextLevel.push_back(first);
    }
    if (currentLevel.size() % 2 != 0)
      nextLevel.push_back(currentLevel.back());
    levels.push_back(nextLevel);
    currentLevel = nextLevel;
  }

  // Sorted chain starts with highest winner chain (last level)
  std::vector<T> sortedChain;
  for (typename std::vector<Iterator>::iterator it = levels.back().begin();
       it != levels.back().end(); ++it)
    sortedChain.push_back(**it);

  // Gather pend elements (all losers)
  std::vector<T> pend;
  for (size_t i = 0; i < n; i += 2) {
    Iterator first = data.begin() + i;
    Iterator second = data.begin() + i + 1;
    pend.push_back(*second); // losers
	pend.push_back(*first);
  }

  // Insertion order using Jacobsthal
  int r_max = 1;
  while (modJac(r_max + 1) <= static_cast<int>(pend.size()))
    ++r_max;
  int threshold = modJac(r_max);

  std::vector<int> insertionOrder;
  for (int i = threshold; i >= 1; --i)
    insertionOrder.push_back(i - 1);
  for (int i = threshold; i < static_cast<int>(pend.size()); ++i)
    insertionOrder.push_back(i);

  // Insert pend into main chain
  for (typename std::vector<int>::iterator idx = insertionOrder.begin();
       idx != insertionOrder.end(); ++idx) {
    T value = pend[*idx];
    typename std::vector<T>::iterator pos =
        std::lower_bound(sortedChain.begin(), sortedChain.end(), value);
    sortedChain.insert(pos, value);
  }

  if (hasStray) {
    typename std::vector<T>::iterator pos =
        std::lower_bound(sortedChain.begin(), sortedChain.end(), stray);
    sortedChain.insert(pos, stray);
  }

  data.clear();
  //sortedChain[sortedChain.size() - 2] = sortedChain[sortedChain.size() - 2] + 1;
  std::copy(sortedChain.begin(), sortedChain.end(), std::back_inserter(data));
  data.pop_back();
}

template <typename Container> void checkSorted(const Container &data) {
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

  std::vector<int> vec = fetchIntVector(++argv);
  std::deque<int> deq(vec.begin(), vec.end());

  int prevVecSize = vec.size();

  /* std::cout << "Before sorting:" << std::endl; */
  /* printContainer(vec); */

  /* clock_t start, end; */
  //double timeVector, timeDeque;

  /* start = clock(); */
  fordJohnsonFullSort(vec);
  /* end = clock(); */
  /* timeVector = (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000); */

  /* start = clock(); */
  /* fordJohnsonFullSort(deq); */
  /* end = clock(); */
  /* timeDeque = (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000); */
  /**/
  std::cout << "After: " << std::endl;
  printContainer(vec);

  int afterVecSize = vec.size();
  if (afterVecSize != prevVecSize) {
		std::cerr << "Error: vector size changed during sorting!" << std::endl;
		return 1;
	}
  checkSorted(vec);
  /* checkSorted(deq); */

  /* std::cout << "Time to process " << vec.size() */
  /*           << " elements with std::vector: " << timeVector << " ms" */
  /*           << std::endl; */
  /* std::cout << "Time to process " << deq.size() */
  /*           << " elements with std::deque: " << timeDeque << " ms" << std::endl; */
  /**/
  std::cout << "Number of comparisons: " << nbr_of_comps << std::endl;

  return 0;
}
