#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm(copy) {
  *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
  if (this != &copy) {
    _target = copy._target;
  }
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {

  if (!canExecute(executor)) {
    return;
  }

  std::cout << "Drilling noises" << std::endl;
  static int i = 0;
  if (i % 2 == 0)
    std::cout << "BZZZZZT! " << _target << " has been robotomized!"
              << std::endl;
  else
    std::cout << "Robotomy failed! " << _target << " is still alive."
              << std::endl;
  i++;
}
