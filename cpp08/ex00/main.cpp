#include "easyfind.hpp"
#include <bits/stdc++.h>
#include <iostream>

int main() {
  std::vector<int> v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(5);
  v.push_back(4);
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);
  std::cout << "Vector:" << std::endl;
  std::cout << easyfind(v, 3) << std::endl;
  int value = 42;
  try {
    std::cout << easyfind(v, value) << std::endl;
  } catch (std::exception &e) {
    std::cout << "Value not found: " << value << std::endl;
  }

  std::list<int> l;
  l.push_back(1);
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);
  l.push_back(5);
  l.push_back(4);
  l.push_back(3);
  l.push_back(2);
  l.push_back(1);
  std::cout << "List:" << std::endl;
  try {
    std::cout << easyfind(l, 5) << std::endl;
    std::cout << easyfind(l, value) << std::endl;
  } catch (std::exception &e) {
    std::cout << "Value not found: " << value << std::endl;
  }

  std::deque<int> d;

  d.push_back(1);
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  d.push_back(4);
  d.push_back(5);
  d.push_back(5);
  d.push_back(4);
  d.push_back(3);
  d.push_back(2);
  d.push_back(1);
  std::cout << "Deque:" << std::endl;
  try {
    std::cout << easyfind(d, 2) << std::endl;
    std::cout << easyfind(d, value) << std::endl;
  } catch (std::exception &e) {
    std::cout << "Value not found: " << value << std::endl;
  }
  return 0;
}
