#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
class ShrubberyCreationForm : public AForm {
private:
  std::string _target;
  ShrubberyCreationForm();

public:
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
  ~ShrubberyCreationForm();

  void execute(Bureaucrat const &executor) const;
};

#endif
