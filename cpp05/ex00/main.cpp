#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
  try {
    Bureaucrat bureaucrat("tuta", 2);

    std::cout << bureaucrat << std::endl;

    bureaucrat.incrementGrade();
    std::cout << bureaucrat.getGrade() << std::endl;
    bureaucrat.decrementGrade();
    std::cout << bureaucrat.getGrade() << std::endl;
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
