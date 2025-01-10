#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>

class Bureaucrat;

class AForm {
protected:
  std::string const _name;
  const int _signGrade;
  const int _execGrade;
  bool _signed;

public:
  AForm();
  virtual ~AForm();
  AForm(std::string name, int signGrade, int execGrade);
  AForm(const AForm &);
  AForm &operator=(const AForm &);
  std::string getName() const;
  int getExecGrade() const;
  int getSignGrade() const;
  void setSigned(bool);
  bool getSigned() const;
  void beSigned(Bureaucrat const &b);

  virtual void execute(Bureaucrat const &executor) const = 0;

  bool canExecute(Bureaucrat const &executor) const;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too high"; }
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too low"; }
  };

  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Form not signed"; }
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &b);

#endif
