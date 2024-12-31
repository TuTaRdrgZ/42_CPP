#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
  try {
    Bureaucrat bureaucrat("tuta", 10);
    Form form("form", 10, 10);

    bureaucrat.signForm(form);

    std::cout << form << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
