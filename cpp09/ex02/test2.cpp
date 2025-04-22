#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <cstdlib>

// N of comparisons
static int nbr_of_comps = 0;

template <typename T>
bool comp(const T& lv, const T& rv) {
    ++nbr_of_comps;
    return lv < rv;
}

// Print container
template <typename Container>
void printContainer(const Container& data) {
    for (typename Container::const_iterator it = data.begin(); it != data.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// Jacobsthal sequence
int modJac(int r) {
    if (r == 1) return 1;
    if (r == 2) return 3;
    int a = 1, b = 3;
    for (int i = 3; i <= r; ++i) {
        int c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

// Generate insertion order using Jacobsthal sequence
std::vector<size_t> generateInsertionOrder(size_t size) {
    std::vector<size_t> order;
    std::vector<size_t> used;
    int r = 1;
    while (true) {
        int idx = modJac(r++) - 1;
        if ((size_t)idx >= size)
            break;
        order.push_back(idx);
        used.push_back(idx);
    }
    for (size_t i = 0; i < size; ++i) {
        if (std::find(used.begin(), used.end(), i) == used.end())
            order.push_back(i);
    }
    return order;
}

// Main sorting function
template <typename Iterator>
void FordJohnsonSort(Iterator begin, Iterator end) {
    typedef typename std::iterator_traits<Iterator>::value_type T;
    size_t n = std::distance(begin, end);
    if (n <= 1) return;

    bool hasStray = (n % 2 != 0);
    T stray;
    if (hasStray) {
        stray = *(end - 1);
        --end;
        n--;
    }

    std::vector<T> winners;
    std::vector<T> losers;
    std::vector<T> pairWinner;

    for (Iterator it = begin; it != end; it += 2) {
        T a = *it;
        T b = *(it + 1);
        if (comp(a, b)) std::swap(a, b);
        winners.push_back(a);
        losers.push_back(b);
        pairWinner.push_back(a);
    }

    FordJohnsonSort(winners.begin(), winners.end());

	// Insert losers using jacobsthal numbers
    std::vector<size_t> order = generateInsertionOrder(losers.size());
    for (size_t k = 0; k < order.size(); ++k) {
        size_t i = order[k];
        T val = losers[i];
		// find winner position respect to pairWinner
        typename std::vector<T>::iterator itWin = std::find(winners.begin(), winners.end(), pairWinner[i]);
        size_t hi = std::distance(winners.begin(), itWin);
		// binary search to find the position of val
        typename std::vector<T>::iterator pos = std::lower_bound(
            winners.begin(), winners.begin() + hi, val, comp<T>);
        winners.insert(pos, val);
    }

	// Insert stray numbers
    if (hasStray) {
        typename std::vector<T>::iterator strayPos = std::lower_bound(
            winners.begin(), winners.end(), stray, comp<T>
        );
        winners.insert(strayPos, stray);
    }

	// copy sorted winners back to the original container
    std::copy(winners.begin(), winners.end(), begin);
}

// Check if the container is sorted
template <typename Container>
void checkSorted(const Container& data) {
    for (typename Container::const_iterator it = data.begin(); it + 1 != data.end(); ++it) {
        if (*(it + 1) < *it) {
            throw std::runtime_error("Sequence is NOT sorted!");
        }
    }
}

// Generate a vector of integers from command line arguments
std::vector<int> fetchIntVector(char** args) {
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

// Execute the sorting and check the average time
template <typename Container>
double RunAndCheckAverageTime(Container& container, int repetitions) {
    double totalTime = 0.0;
    for (int i = 0; i < repetitions; ++i) {
        Container temp = container;
        clock_t start = clock();
        FordJohnsonSort(temp.begin(), temp.end());
        clock_t end = clock();
        totalTime += (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);
        checkSorted(temp);
    }
    FordJohnsonSort(container.begin(), container.end());
    checkSorted(container);
    return totalTime / repetitions;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::vector<int> vec = fetchIntVector(++argv);
    std::deque<int> deq(vec.begin(), vec.end());
    int reps = 1000;
    try {
        std::cout << "Before sorting:" << std::endl;
        printContainer(vec);
        double tv = RunAndCheckAverageTime(vec, reps);
        double td = RunAndCheckAverageTime(deq, reps);
        std::cout << "After sorting:" << std::endl;
        printContainer(vec);
        std::cout << "Avg time (vector): " << tv << " ms over " << reps << " runs" << std::endl;
        std::cout << "Avg time (deque): " << td << " ms over " << reps << " runs" << std::endl;
        std::cout << "Comparisons: " << nbr_of_comps / reps << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
