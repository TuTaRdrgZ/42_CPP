#include "Form.hpp"
#include <iostream>

Form::Form() : _name("Form"), _signGrade(0), _execGrade(0), _signed(false) {}
Form::~Form() {}

Form::Form(const Form &b) : _execGrade(0), _signGrade(0), _signed(0) {
  *this = b;
}

Form &Form::operator=(const Form &b) {
  this->_signed = b._signed;
  return *this;
}

Form::Form(std::string name, int signGrade, int execGrade)
    : _name(name), _signGrade(signGrade), _execGrade(execGrade),
      _signed(false) {
  if (signGrade < 1 || execGrade < 1) {
    throw Form::GradeTooHighException();
  } else if (signGrade > 150 || execGrade > 150) {
    throw Form::GradeTooLowException();
  }
}

std::string Form::getName() const { return this->_name; }

int Form::getSignGrade() const { return this->_signGrade; }
int Form::getExecGrade() const { return this->_execGrade; }
bool Form::getSigned() const { return this->_signed; }

void Form::setSigned(bool b) { this->_signed = b; }

void Form::beSigned(Bureaucrat const &b) {
  if (b.getGrade() > this->_signGrade) {
    throw Form::GradeTooLowException();
  }
  this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &b) {
  os << b.getName() << ", Form signGrade " << b.getSignGrade() << ", execGrade "
     << b.getExecGrade() << ", signed " << b.getSigned();
  return os;
}
