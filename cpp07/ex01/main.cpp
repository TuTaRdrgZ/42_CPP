#include "iter.hpp"
#include <iostream>

void printInt(int const &i) { std::cout << i << std::endl; }
void printDouble(double const &d) { std::cout << d << std::endl; }
void printChar(char const &c) { std::cout << c << std::endl; }
void printStr(std::string const &s) { std::cout << s << std::endl; }

int main() {
  {
    int array[] = {1, 2, 3, 4, 5};
    size_t size = 5;
    iter(array, size, printInt);
  }
  {
    char array[] = {'a', 'b', 'c', 'd', 'e'};
    size_t size = 5;
    iter(array, size, printChar);
  }
  {
    std::string array[] = {"hola", "como", "estas", "todo", "bien?"};
    size_t size = 5;
    iter<std::string>(array, size, printStr); // explicit template instantiation
  }
  {
    double array[] = {1.32, 2.34, 3.64, 4.76, 5.68};
    size_t size = 5;
    iter(array, size, printDouble);
  }
  return 0;
}
