#include "PmergeMe.hpp"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

// Función para obtener un vector de enteros a partir de los argumentos
// (renombrada a fetchVector)
std::vector<int> fetchVector(char **input) {
  std::vector<int> vec;
  if (!input || !*input) {
    std::cerr << "Error\n";
    exit(1);
  }
  while (*input) {
	std::string str(*input);
	if (str.find_first_not_of("0123456789") != std::string::npos) {
			std::cerr << "Error\n";
			exit(1);
	}
    vec.push_back(std::atoi(*input));
    ++input;
  }
  return vec;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Error\n";
    return 1;
  }
  std::vector<int> vec = fetchVector(++argv);
  std::deque<int> deq(vec.begin(), vec.end());


  std::cout << "Before: ";
  printElements(vec);
  
  double timeVector = mergeProcess(&vec);
  double timeDeque = mergeProcess(&deq);

  std::cout << "After: ";
  printElements(vec);

  checkSorted(vec);
  checkSorted(deq);

  std::cout << "Time to process " << vec.size()
            << " elements with std::vector: " << timeVector << " ms\n";
  std::cout << "Time to process " << deq.size()
            << " elements with std::deque: " << timeDeque << " ms\n";
  return 0;
}
