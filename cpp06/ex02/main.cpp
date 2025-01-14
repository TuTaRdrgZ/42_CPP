#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
  unsigned int randomNum = rand() % 3;

  if (randomNum == 0) {
    A *a = new A();
    return a;
  } else if (randomNum == 1) {
    B *b = new B();
    return b;
  } else {
    C *c = new C();
    return c;
  }

  return NULL;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p)) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "B" << std::endl;
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "C" << std::endl;
  }
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "A" << std::endl;

  } catch (std::exception &e) {
  }
  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "B" << std::endl;

  } catch (std::exception &e) {
  }
  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "C" << std::endl;

  } catch (std::exception &e) {
  }
}

int main() {
  srand(time(NULL));
  Base *generated = generate();
  identify(generated);
  identify(*generated);
  delete generated;
  return 0;
}
