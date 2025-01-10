#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
class PresidentialPardonForm : public AForm {
private:
  std::string _target;
  PresidentialPardonForm();

public:
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &);
  ~PresidentialPardonForm();

  void execute(Bureaucrat const &executor) const;
};

#endif
