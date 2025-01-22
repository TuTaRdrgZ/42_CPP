#include "Array.hpp"
#include <iostream>

int main() {

  {
    try {

      Array<int> a(5);
      a[0] = 1;
      a[1] = 2;
      a[2] = 3;
      a[3] = 4;
      a[4] = 5;
      a[5] = 6;

      for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;

    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  try {
    Array<std::string> a(3);
    a[0] = "Hello";
    a[1] = "World";
    a[2] = "!";

    for (unsigned int i = 0; i < a.size(); i++)
      std::cout << a[i] << " ";
    std::cout << std::endl;

  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
