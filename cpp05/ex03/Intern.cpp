#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

typedef AForm *(Intern::*formCreator)(std::string const &) const;

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}

AForm *Intern::createShrubberyCreationForm(std::string const &target) const {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string const &target) const {
  return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string const &target) const {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) const {
  std::string formNames[] = {
      "shrubbery creation",
      "presidential pardon",
      "robotomy request",
  };

  formCreator forms[] = {
      &Intern::createShrubberyCreationForm,
      &Intern::createPresidentialPardonForm,
      &Intern::createRobotomyRequestForm,
  };

  for (int i = 0; i < 3; i++) {
    if (name == formNames[i]) {
      std::cout << "Intern creates " << name << std::endl;
      return (this->*forms[i])(target);
    }
  }
  std::cout << "Intern cannot create " << name << std::endl;

  return NULL;
}
