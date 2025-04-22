#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

//static int nbr_of_comps = 0;

// Count the number of comparisons
template <typename T> bool comp(T lv, T rv) {
  //  nbr_of_comps++;
    return *lv < *rv;
}

// Prints the container elements separated by spaces.
template <typename Container> void printContainer(const Container &data) {
    for (typename Container::const_iterator it = data.begin(); it != data.end(); ++it)
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

// Recursive implementation of Ford-Johnson
template <typename Iterator>
void FordJohnsonSort(Iterator begin, Iterator end) {
    typedef typename std::iterator_traits<Iterator>::value_type T;

    size_t n = std::distance(begin, end);
    if (n <= 1)
        return;

    // Handle stray element if odd number of items
    bool hasStray = n % 2 != 0;
    T stray;
    if (hasStray) {
        stray = *(end - 1);
        --end;
        n--;
    }

    // Separate winners and losers
    std::vector<Iterator> winners;
    std::vector<T> losers;
    for (Iterator it = begin; it != end; it += 2) {
        Iterator first = it;
        Iterator second = it + 1;
        if (comp(first, second))
            std::iter_swap(first, second);
        winners.push_back(first);  // Winners
        losers.push_back(*second); // Losers
    }

    // Recursively sort the winners
    std::vector<T> sortedWinners;
    for (size_t i = 0; i < winners.size(); ++i)
        sortedWinners.push_back(*winners[i]);
    FordJohnsonSort(sortedWinners.begin(), sortedWinners.end());

    // Insertion of losers using Jacobsthal sequence
    int r_max = 1;
    while (modJac(r_max + 1) <= static_cast<int>(losers.size()))
        ++r_max;
    int threshold = modJac(r_max);

    std::vector<int> insertionOrder;
    for (int i = threshold; i >= 1; --i)
        insertionOrder.push_back(i - 1);
    for (int i = threshold; i < static_cast<int>(losers.size()); ++i)
        insertionOrder.push_back(i);

    for (typename std::vector<int>::iterator idx = insertionOrder.begin();
         idx != insertionOrder.end(); ++idx) {
        T value = losers[*idx];
        typename std::vector<T>::iterator pos =
            std::lower_bound(sortedWinners.begin(), sortedWinners.end(), value);
        sortedWinners.insert(pos, value);
    }

    // Insert stray element, if any
    if (hasStray) {
        typename std::vector<T>::iterator pos =
            std::lower_bound(sortedWinners.begin(), sortedWinners.end(), stray);
        sortedWinners.insert(pos, stray);
    }

    // Copy sorted results back into the original range
    std::copy(sortedWinners.begin(), sortedWinners.end(), begin);
}

template <typename Container> void checkSorted(const Container &data) {
    typename Container::const_iterator next;
    for (typename Container::const_iterator it = data.begin(); it != data.end(); ++it) {
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

// Function to run the sort N times and calculate the average time
template <typename Container>
double RunAndCheckAverageTime(Container &container, int repetitions) {
    double totalTime = 0.0;
	
    for (int i = 0; i < repetitions; ++i) {
        Container tempContainer = container;
        clock_t start = clock();
        FordJohnsonSort(tempContainer.begin(), tempContainer.end());
        clock_t end = clock();
        totalTime += (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);
        checkSorted(tempContainer);
    }
	
	FordJohnsonSort(container.begin(), container.end());
	checkSorted(container);

    return totalTime / repetitions;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vec = fetchIntVector(++argv);
    std::deque<int> deq(vec.begin(), vec.end());

    int repetitions = 1000; // Number of times to repeat the sort
    std::cout << "Before sorting:" << std::endl;
    printContainer(vec);

    double avgTimeVector = RunAndCheckAverageTime(vec, repetitions);
    double avgTimeDeque = RunAndCheckAverageTime(deq, repetitions);

    std::cout << "After sorting:" << std::endl;
    printContainer(vec);

    std::cout << "Average time to process " << vec.size()
              << " elements with std::vector: " << avgTimeVector << " ms"
              << " (over " << repetitions << " runs)" << std::endl;
    std::cout << "Average time to process " << deq.size()
              << " elements with std::deque: " << avgTimeDeque << " ms"
              << " (over " << repetitions << " runs)" << std::endl;

    return 0;
}
