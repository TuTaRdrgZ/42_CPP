#include "MutantStack.hpp"

int main(void) {
  MutantStack<int> mstack;

  mstack.push(14);
  mstack.push(1);

  std::cout << "Top element: " << mstack.top() << std::endl;

  std::cout << "Size before pop: " << mstack.size() << std::endl;
  mstack.pop();
  std::cout << "Size after pop: " << mstack.size() << std::endl;

  mstack.push(6);
  mstack.push(90);
  mstack.push(17);
  mstack.push(3);
  mstack.push(8);
  mstack.push(2);
  mstack.push(10);

  std::cout << "MutantStack iterator:" << std::endl;
  for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
       ++it) {
    std::cout << *it << std::endl;
  }

  std::cout << "MutantStack reverse iterator:" << std::endl;
  for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
       rit != mstack.rend(); ++rit) {
    std::cout << *rit << std::endl;
  }

  MutantStack<int> mstackCopy(mstack);
  std::cout << "MutantStack copy:" << std::endl;
  for (MutantStack<int>::iterator it = mstackCopy.begin();
       it != mstackCopy.end(); ++it) {
    std::cout << *it << std::endl;
  }

  return 0;
}
