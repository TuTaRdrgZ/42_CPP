#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _name("AForm"), _signGrade(), _execGrade(), _signed(false) {}
AForm::~AForm() {}

AForm::AForm(const AForm &b) : _signGrade(), _execGrade(), _signed(false) {
  *this = b;
}

AForm &AForm::operator=(const AForm &b) {
  this->_signed = b._signed;
  return *this;
}

AForm::AForm(std::string name, int signGrade, int execGrade)
    : _name(name), _signGrade(signGrade), _execGrade(execGrade),
      _signed(false) {
  if (signGrade < 1 || execGrade < 1) {
    throw AForm::GradeTooHighException();
  } else if (signGrade > 150 || execGrade > 150) {
    throw AForm::GradeTooLowException();
  }
}

std::string AForm::getName() const { return this->_name; }

int AForm::getSignGrade() const { return this->_signGrade; }
int AForm::getExecGrade() const { return this->_execGrade; }
bool AForm::getSigned() const { return this->_signed; }

void AForm::setSigned(bool b) { this->_signed = b; }

void AForm::beSigned(Bureaucrat const &b) {
  if (b.getGrade() > this->_signGrade) {
    throw AForm::GradeTooLowException();
  }
  this->_signed = true;
}

bool AForm::canExecute(Bureaucrat const &executor) const {
  if (executor.getGrade() > this->_execGrade) {
    std::cout << "Bureaucrat " << executor.getName() << " cannot execute "
              << this->_name << " because ";
    throw AForm::GradeTooLowException();
  }
  if (!this->_signed) {
    std::cout << "Bureaucrat " << executor.getName() << " cannot execute "
              << this->_name << " because ";
    throw AForm::FormNotSignedException();
  }
  return true;
}

std::ostream &operator<<(std::ostream &os, const AForm &b) {
  os << b.getName() << ", AForm signGrade " << b.getSignGrade()
     << ", execGrade " << b.getExecGrade() << ", signed " << b.getSigned();
  return os;
}
