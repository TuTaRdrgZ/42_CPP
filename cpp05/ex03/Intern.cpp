#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <map>

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string name, std::string target) const {
  std::string formNames[] = {
      std::string("shrubbery creation"),
      std::string("presidential pardon"),
      std::string("robotomy request"),
  };

  AForm *forms[] = {
      new ShrubberyCreationForm(target),
      new PresidentialPardonForm(target),
      new RobotomyRequestForm(target),
  };

  for (int i = 0; i < 3; i++) {
    if (name == formNames[i]) {
      std::cout << "Intern creates " << name << std::endl;
      return forms[i];
    }
  }
  std::cout << "Intern cannot create " << name << std::endl;

  return NULL;
}
