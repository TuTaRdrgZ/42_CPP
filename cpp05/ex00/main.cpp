#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
  {
    try {
      Bureaucrat bureaucrat("tuta", 2);

      std::cout << bureaucrat << std::endl;

      bureaucrat.incrementGrade();
      std::cout << bureaucrat.getGrade() << std::endl;
      bureaucrat.decrementGrade();
      std::cout << bureaucrat.getGrade() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      Bureaucrat bureaucrat("tuta", 150);

      std::cout << bureaucrat << std::endl;

      bureaucrat.decrementGrade();
      std::cout << bureaucrat.getGrade() << std::endl;
      bureaucrat.incrementGrade();
      std::cout << bureaucrat.getGrade() << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      Bureaucrat bureaucrat("tuta", 0);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    try {
      Bureaucrat bureaucrat("tuta", 151);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  return 0;
}
