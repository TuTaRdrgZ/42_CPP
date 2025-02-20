#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  {
    try {
      Span sp(11);

      sp.addNumber(5);
      sp.addNumber(10);
      sp.addNumber(20);

      std::vector<int> vec;
      vec.push_back(30);
      vec.push_back(40);
      vec.push_back(50);
      vec.push_back(60);
      vec.push_back(70);
      vec.push_back(80);
      vec.push_back(90);
      vec.push_back(100);

      sp.addNumber(vec.begin(), vec.end());

      std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
      std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }

  return 0;
}
