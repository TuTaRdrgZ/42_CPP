#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150) {}
Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &b) { *this = b; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b) {
  this->_grade = b._grade;
  return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->_grade = grade;
}

std::string Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::setGrade(int grade) {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->_grade = grade;
}

void Bureaucrat::incrementGrade() {
  if (this->_grade == 1) {
    throw Bureaucrat::GradeTooHighException();
  }
  this->_grade--;
}

void Bureaucrat::decrementGrade() {
  if (this->_grade == 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->_grade++;
}

void Bureaucrat::signForm(AForm &f) {
  if (this->_grade > f.getSignGrade()) {
    std::cout << this->_name << " cannot sign " << f.getName()
              << " because his grade is too low" << std::endl;
    return;
  }
  std::cout << this->_name << " signed " << f.getName() << std::endl;
  f.setSigned(true);
}

void Bureaucrat::executeForm(AForm const &f) const {
  f.execute(*this);
  std::cout << _name << " executed " << f.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade();
  return os;
}
