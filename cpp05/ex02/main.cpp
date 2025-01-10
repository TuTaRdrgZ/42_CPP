#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void) {
  try {
    Bureaucrat bureaucrat("tuta", 14);

    std::cout << "------------------ShrubberyCreationForm------------------"
              << std::endl
              << std::endl;
    ShrubberyCreationForm form("tuta");
    bureaucrat.signForm(form);
    bureaucrat.executeForm(form);

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Bureaucrat bureaucrat("tuta", 4);

    std::cout << std::endl
              << "------------------RobotomyRequestForm------------------"
              << std::endl
              << std::endl;

    RobotomyRequestForm robotomyRequestForm("tuta");
    bureaucrat.signForm(robotomyRequestForm);
    bureaucrat.executeForm(robotomyRequestForm);
    bureaucrat.executeForm(robotomyRequestForm);

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Bureaucrat bureaucrat("tuta", 2);

    std::cout << std::endl
              << "------------------PresidentialPardonForm------------------"
              << std::endl
              << std::endl;

    PresidentialPardonForm presidentialPardonForm("tuta");
    bureaucrat.signForm(presidentialPardonForm);
    bureaucrat.executeForm(presidentialPardonForm);

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
