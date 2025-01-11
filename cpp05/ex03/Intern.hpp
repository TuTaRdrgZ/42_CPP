#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
class Intern {
public:
  Intern();
  Intern(const Intern &);
  Intern &operator=(const Intern &);
  ~Intern();
  AForm *makeForm(std::string name, std::string target) const;
  AForm *createShrubberyCreationForm(std::string const &target) const;
  AForm *createRobotomyRequestForm(std::string const &target) const;
  AForm *createPresidentialPardonForm(std::string const &target) const;
};

#endif
