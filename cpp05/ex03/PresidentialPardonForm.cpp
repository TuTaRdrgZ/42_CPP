#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &copy)
    : AForm(copy) {
  *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
  if (this != &copy) {
    _target = copy._target;
  }
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {

  if (!canExecute(executor)) {
    return;
  }
  std::cout << _target << " has been pardoned by Zafod Beeblebrox."
            << std::endl;
}
