#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
class Bureaucrat {
private:
  std::string const _name;
  int _grade;

public:
  Bureaucrat();
  ~Bureaucrat();
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &);
  Bureaucrat &operator=(const Bureaucrat &);
  std::string getName() const;
  int getGrade() const;
  void setGrade(int grade);
  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too high"; }
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade too low"; }
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
