#ifndef FORM_HPP
#define FORM_HPP
#include <string>

class Bureaucrat;

class Form {
private:
  std::string const _name;
  const int _signGrade;
  const int _execGrade;
  bool _signed;

public:
  Form();
  ~Form();
  Form(std::string name, int signGrade, int execGrade);
  Form(const Form &);
  Form &operator=(const Form &);
  std::string getName() const;
  int getExecGrade() const;
  int getSignGrade() const;
  void setSigned(bool);
  bool getSigned() const;
  void beSigned(Bureaucrat const &b);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too high"; }
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too low"; }
  };
};

std::ostream &operator<<(std::ostream &os, const Form &b);

#endif
