#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <cstdlib>

// Contador de comparaciones
static int nbr_of_comps = 0;

// Comparador que cuenta comparaciones
template <typename T>
bool comp(const T& lv, const T& rv) {
    ++nbr_of_comps;
    return lv < rv;
}

// Imprimir contenedor
template <typename Container>
void printContainer(const Container& data) {
    for (typename Container::const_iterator it = data.begin(); it != data.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// Secuencia de Jacobsthal
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

// Generar orden de insercion segun Jacobsthal
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

// Insercion binaria guiada por etiquetas
template <typename T>
size_t binarySearchInsert(const std::vector<T>& sorted, const T& value) {
    size_t left = 0, right = sorted.size();
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (comp(value, sorted[mid]))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

// Implementacion clasica del Ford-Johnson
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

    for (Iterator it = begin; it != end; it += 2) {
        T a = *it;
        T b = *(it + 1);
        if (comp(a, b)) std::swap(a, b);
        winners.push_back(a); // ganador
        losers.push_back(b);  // perdedor
    }

    FordJohnsonSort(winners.begin(), winners.end());

    std::vector<size_t> insertionOrder = generateInsertionOrder(losers.size());
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        size_t idx = insertionOrder[i];
        T value = losers[idx];
        size_t pos = binarySearchInsert(winners, value);
        winners.insert(winners.begin() + pos, value);
    }

    if (hasStray) {
        size_t pos = binarySearchInsert(winners, stray);
        winners.insert(winners.begin() + pos, stray);
    }

    std::copy(winners.begin(), winners.end(), begin);
}

// Verificacion de orden
template <typename Container>
void checkSorted(const Container& data) {
    for (typename Container::const_iterator it = data.begin(); it + 1 != data.end(); ++it) {
        if (*(it + 1) < *it) {
			throw std::runtime_error("Sequence is NOT sorted!");
        }
    }
}

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

	try {
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
	  std::cout << "Number of comparisons: " << nbr_of_comps / repetitions << std::endl;
	} catch (std::exception &e) {
	  std::cout << e.what() << std::endl;
	}


    return 0;
}
